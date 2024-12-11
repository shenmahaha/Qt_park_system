#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QCommandLinkButton>
#include <QMessageBox>
#include <QDebug>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDateTime>
#include <QFile>

#include "tts_offline_sample.h"  // 引入 C 文件


QSqlDatabase db;
QString edit_id;
QString delet_id;
QUdpSocket *udp_recv;
QUdpSocket *udp_recv1;
QUdpSocket *udp_recv_info;
QUdpSocket *udp_recv_info1;
QTcpServer *audio_tcp;
QTcpSocket *new_clien;

//端口全局变量
//入口摄像头端口
quint16 entranceCamera_port=8080;
//入口信息端口
quint16 entranceInfo_port=9999;
//出口摄像头端口
quint16 exportCamera_port=8082;
//出口信息端口
quint16 exportInfo_port=7777;

//音频传输端口
quint16 audioTransmission_port=8889;

void sendWavFile(const QString &filePath, QTcpSocket *new_clien);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/OIP-removebg-preview.ico"));
    this->setWindowTitle("智停宝");
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_13->setReadOnly(true);
    //加载数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("park.db");
    if(db.open()){
        qDebug()<<"数据库打开成功";
    }else{
        qDebug()<<"数据库打开失败";
    }

    // 禁用所有单元格的编辑功能
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    udp_recv= new QUdpSocket(this);
    udp_recv1= new QUdpSocket(this);
    udp_recv_info=new QUdpSocket(this);
    udp_recv_info1=new QUdpSocket(this);
    audio_tcp = new QTcpServer(this);
    bool ret  =  audio_tcp->listen(QHostAddress::Any,audioTransmission_port);
    if(ret)
    {
        ui->statusbar->showMessage("服务器监听成功");
    }else
    {
        ui->statusbar->showMessage("服务器监听失败");
    }
    if(udp_recv->bind(QHostAddress::Any,entranceCamera_port))
    {
        qDebug() << "绑定成功" ;
    }else
    {
        qDebug() << "绑定失败" ;
    }
    if(udp_recv_info->bind(QHostAddress::Any,entranceInfo_port))
    {
        qDebug() << "绑定成功" ;
    }else
    {
        qDebug() << "绑定失败" ;
    }
    if(udp_recv1->bind(QHostAddress::Any,exportCamera_port))
    {
        qDebug() << "绑定成功" ;
    }else
    {
        qDebug() << "绑定失败" ;
    }
    if(udp_recv_info1->bind(QHostAddress::Any,exportInfo_port))
    {
        qDebug() << "绑定成功" ;
    }else
    {
        qDebug() << "绑定失败" ;
    }


    connect(udp_recv, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams);
    connect(udp_recv_info, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info);
    connect(udp_recv1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams1);
    connect(udp_recv_info1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info1);
    connect(audio_tcp,&QTcpServer::newConnection,this,[](){
        qDebug() << "有新的客户端链接，请处理" << endl;
        //产生新对象
        new_clien = audio_tcp->nextPendingConnection();

        qDebug() << "对方的IP信息:" << new_clien->peerAddress().toString();
        qDebug() << "对方的端口信息:" << new_clien->peerPort();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void sendWavFile(const QString &filePath, QTcpSocket *new_clien)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "无法打开文件:" << filePath;
        return;
    }

    while (!file.atEnd()) {
        QByteArray chunk = file.read(1024);
        new_clien->write(chunk);
    }

    // 发送结束标志
    new_clien->write("end");
    new_clien->flush();
    qDebug() << "文件发送完毕";
    file.close();
}



//接收到入场信息后操作数据库
void MainWindow::vehicleEntry(QString plate,QString cardId,QString time){
    QSqlQuery cmd(db);
    QString sql=QString("select * from car_info where license_plate='%1'").arg(plate);
    if(cmd.exec(sql)){
        if(cmd.next()){
            qDebug()<<"有该车辆数据";
            sql=QString("insert into car_consumption_info(license_plate,card_number,entry_time)"
                        " values('%1','%2','%3')").arg(plate,cardId,time);
            qDebug()<<sql;
            if(cmd.exec(sql)){
                qDebug()<<"添加消费信息成功";
            }else{
                qDebug()<<"添加消费信息失败";
            }
            //设置进场车辆图片
            admission_pic=camera_pic;
            ui->label_3->setPixmap(admission_pic);
            //设置入场车辆信息
            ui->label_6->setText(plate);
            ui->label_8 ->setText(cardId);
            ui->label_10->setText(time);
            TTS(QString("车牌号%1，欢迎光临。").arg(plate).toUtf8());
            sendWavFile("tts_sample.wav",new_clien);
        }else{
            qDebug()<<"无该车辆数据，注册车辆";
            sql=QString("insert into car_info(license_plate,card_number,card_balance) values('%1','%2',%3)").arg(plate,cardId,"1000");
            qDebug()<<sql;
            if(cmd.exec(sql)){

                qDebug()<<"添加成功,即将添加消费信息";
                sql=QString("insert into car_consumption_info(license_plate,card_number,entry_time)"
                            " values('%1','%2','%3')").arg(plate,cardId,time);
                qDebug()<<sql;
                if(cmd.exec(sql)){
                    qDebug()<<"添加消费信息成功";
                    //设置进场车辆图片
                    admission_pic=camera_pic;
                    ui->label_3->setPixmap(admission_pic);
                    //设置入场车辆信息
                    ui->label_6->setText(plate);
                    ui->label_8 ->setText(cardId);
                    ui->label_10->setText(time);
                    TTS(QString("车牌号%1，欢迎光临。").arg(plate).toUtf8());
                    sendWavFile("tts_sample.wav",new_clien);
                }else{
                    qDebug()<<"添加消费信息失败";
                }

            }else{
                qDebug()<<"添加失败";
            }
        }

    }else{
        qDebug()<<"查询失败";
    }

}

//入场摄像头
void MainWindow::readPendingDatagrams()
{

    while (udp_recv->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udp_recv->receiveDatagram();
        //转换数'Hh/'/据报获取数据
        QString  ip  = datagram.senderAddress().toString();
        int port     = datagram.senderPort();
        //        qDebug() <<ip ;
        //        qDebug() << port ;
        QString msg =datagram.data();
        //        qDebug() << "msg" << msg;
        camera_pic.loadFromData(datagram.data());
        ui->label->setPixmap(camera_pic);

    }
}
//获取入场车辆车牌信息
void MainWindow::readPendingDatagrams_info()
{
    while (udp_recv_info->hasPendingDatagrams()) {

        QByteArray datagram;
        datagram.resize(udp_recv_info->pendingDatagramSize());
        // 获取发送方信息
        QHostAddress sender; quint16 senderPort;
        udp_recv_info->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        // 打印收到的数据
        qDebug() << "Received datagram from" << sender.toString() << "port" << senderPort;
        // 将 QByteArray 转换为 QString
        QString message = QString::fromUtf8(datagram);
        // 分割字符串，按 ", " 分割
        QStringList parts = message.split(", ");

        if (parts.size() == 3) {
            // 提取卡号
            QString cardId = parts[0].split(": ")[1];
            // 提取车牌号（包含UTF-8字符）
            QString plate = parts[1].split(": ")[1];
            // 提取时间
            QString time = parts[2].split(": ")[1];
            // 打印解析后的信息
            qDebug() << "Card ID: " << cardId;
            qDebug() << "Plate: " << plate;
            qDebug() << "Time: " << time;

            //设置数据库
            vehicleEntry(plate,cardId,time);
        } else {
            qDebug() << "Message format is incorrect!";
        }
        // 显示收到的数据

    }
}
//出场摄像头
void MainWindow::readPendingDatagrams1()
{

    while (udp_recv1->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udp_recv1->receiveDatagram();
        //转换数据报获取数据
        QString  ip  = datagram.senderAddress().toString();
        int port     = datagram.senderPort();
        //                qDebug() <<ip ;
        //                qDebug() << port ;
        QString msg =datagram.data();
        //        qDebug() << "msg" << msg;
        camera_pic1.loadFromData(datagram.data());
        ui->label_2->setPixmap(camera_pic1);
    }
}

void MainWindow::vehicleExit(QString plate,QString cardId,QString time){
    //判断卡内金额是否充足
    QSqlQuery cmd(db);
    double cardBalance=0;
    if(cmd.exec(QString("select card_balance from car_info where license_plate='%1'").arg(plate))){
        if(cmd.next()){
            cardBalance=cmd.value(0).toDouble();
            qDebug()<<"卡上余额："<<cardBalance;
        }

    }else{
        qDebug()<<"car_info查询失败";
    }
    if(cmd.exec(QString("select * from car_consumption_info where license_plate='%1'").arg(plate))){
        double hoursDiff=0;
        while(cmd.next()){
            QString license_plate=cmd.value(1).toString();
            QString card_number=cmd.value(2).toString();
            QString entry_time=cmd.value(3).toString();
            QString exit_time=cmd.value(4).toString();
            if(exit_time!=""){
                continue;
            }
            //            qDebug() << " entry_time" << entry_time;
            //            qDebug() << " time" << time;
            //             将字符串转换为 QDateTime 对象
            QDateTime dateTime1 = QDateTime::fromString(entry_time, "yyyy-MM-dd HH:mm:ss");
            QDateTime dateTime2 = QDateTime::fromString(time, "yyyy-MM-dd HH:mm:ss");
            // 计算时间差，以秒为单位
            qint64 secondsDiff = dateTime1.secsTo(dateTime2);
            //            qDebug() << "secondsDiff: " << secondsDiff;
            // 将时间差转换为小时
            hoursDiff = secondsDiff / 3600.0;
            // 输出结果
            qDebug() << "Time difference in hours: " << hoursDiff;
            double consumption=hoursDiff*2;
            double balance=cardBalance-consumption;
            //            qDebug() <<"exit_time:"<<exit_time;
            //            qDebug() <<"consumption:"<<consumption;
            //             qDebug() <<"balance:"<<balance;
            //             qDebug() <<"cardId==card_number&&exit_time==""&&balance>=0:"<<(cardId==card_number&&exit_time==""&&balance>=0);
            if(cardId==card_number&&exit_time==""&&balance>=0){
                qDebug()<<"出场成功";
                QString sql=QString("UPDATE  car_consumption_info "
                                    "SET exit_time='%1',total_time='%2',money=%3 WHERE license_plate='%4'")
                        .arg(time)
                        .arg(QString::number(hoursDiff,'f',1))
                        .arg(QString::number(consumption,'f',2))
                        .arg(plate);
                qDebug()<<sql;
                if(cmd.exec(sql)){
                    qDebug()<<"修改car_consumption_info成功";
                }else{
                    qDebug()<<"修改car_consumption_info失败";
                }
                sql=QString("UPDATE  car_info "
                            "SET card_balance=%1 WHERE license_plate='%2'")
                        .arg(QString::number(balance,'f',2))
                        .arg(plate);
                qDebug()<<sql;
                if(cmd.exec(sql)){
                    //设置进场车辆图片
                    exit_pic=camera_pic1;
                    ui->label_4->setPixmap(exit_pic);
                    //            设置入场车辆信息
                    ui->label_12->setText(plate);
                    ui->label_14 ->setText(cardId);
                    ui->label_16->setText(entry_time);
                    ui->label_23->setText(time);
                    ui->label_18->setText(QString::number(hoursDiff,'f',1)+"h");
                    ui->label_28->setText(QString::number(consumption,'f',2)+"元");
                    ui->label_30->setText(QString::number(balance,'f',2)+"元");
                    TTS(QString("车牌号%1，停车时长%2小时，消费金额%3元。")
                        .arg(plate)
                        .arg(QString::number(hoursDiff,'f',1))
                        .arg(QString::number(balance,'f',2))
                        .toUtf8());
                    sendWavFile("tts_sample.wav",new_clien);
                    qDebug()<<"修改car_info成功";
                }else{
                    qDebug()<<"修改car_info失败";
                }
            }

        }
    }else{
        qDebug()<<"查询失败";
    }
}

//获取出场车辆车牌信息
void MainWindow::readPendingDatagrams_info1(){
    while (udp_recv_info1->hasPendingDatagrams()) {

        QByteArray datagram;
        datagram.resize(udp_recv_info1->pendingDatagramSize());
        // 获取发送方信息
        QHostAddress sender; quint16 senderPort;
        udp_recv_info1->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        // 打印收到的数据
        qDebug() << "Received datagram from" << sender.toString() << "port" << senderPort;
        // 将 QByteArray 转换为 QString
        QString message = QString::fromUtf8(datagram);
        // 分割字符串，按 ", " 分割
        QStringList parts = message.split(", ");

        if (parts.size() == 3) {
            // 提取卡号
            QString cardId = parts[0].split(": ")[1];
            // 提取车牌号（包含UTF-8字符）
            QString plate = parts[1].split(": ")[1];
            // 提取时间
            QString time = parts[2].split(": ")[1];
            // 打印解析后的信息
            qDebug() << "Card ID: " << cardId;
            qDebug() << "Plate: " << plate;
            qDebug() << "Time: " << time;
            QSqlQuery cmd(db);
            if(cmd.exec(QString("select * from car_consumption_info where license_plate='%1'").arg(plate))){
                if(cmd.next()){
                    qDebug("该车辆有入场");
                    vehicleExit(plate,cardId,time);
                }else{
                    qDebug("该车辆未入场,不能出去");
                }
            }else{
                qDebug("查询失败");
            }



        } else {
            qDebug() << "Message format is incorrect!";
        }
        // 显示收到的数据

    }
}

//显示车俩信息按钮
void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}

//显示全部信息
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    loadCarInfoTable("SELECT * FROM car_info");

}
//搜索按钮
void MainWindow::on_pushButton_3_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
        this->on_pushButton_2_clicked();
        return;
    }

    QString searchTerm = ui->lineEdit->text();
    QString sql = QString("SELECT * FROM car_info WHERE id='%1' OR license_plate='%1' OR card_number='%1'")
            .arg(searchTerm);
    loadCarInfoTable(sql);
}
void MainWindow::loadCarInfoTable(const QString &sql)
{
    QSqlQuery cmd(db);
    // 执行查询操作
    if (!cmd.exec(sql)) {
        qDebug() << "查询失败：" ;
        return;
    }

    QSqlRecord sqlre = db.record("car_info");

    // 获取表格行数
    int rowCount = 0;
    cmd.first(); // 定位到查询的第一行
    while (cmd.isValid()) {
        rowCount++;
        cmd.next();
    }

    // 设置表格行列
    ui->tableWidget->setColumnCount(sqlre.count() + 1); // +1 for 操作 column
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnWidth(0, 54); // 设置列宽
    ui->tableWidget->setColumnWidth(3, 71); // 设置列宽
    ui->tableWidget->setColumnWidth(4, 71); // 设置列宽



    // 设置表头
    QStringList headers;
    for (int i = 0; i < sqlre.count()-1; ++i) {
        headers << sqlre.fieldName(i);
    }
    headers << "操作"<<"操作";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 重新执行查询并遍历数据
    cmd.first(); // 定位到第一条记录
    int row = 0;
    while (cmd.isValid()) {
        // 插入数据
        for (int col = 0; col < sqlre.count()-1; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(cmd.value(col).toString());
            item->setTextAlignment(Qt::AlignCenter);  // 数据居中显示
            ui->tableWidget->setItem(row, col, item);
        }


        // 创建操作按钮并放置
        QCommandLinkButton *qclb = new QCommandLinkButton("修改", ui->tableWidget);
        qclb->setIcon(QIcon());
        qclb->setText("修改");
        qclb->setFixedSize(50, 30); // 设置按钮大小
        // 设置按钮文本为蓝色并带下划线
        qclb->setStyleSheet(
                    "QCommandLinkButton {"
                    "   color: blue;"               // 设置文本颜色为蓝色
                    "   font-weight: bold;"         // 设置字体加粗
                    "   background-color: transparent;"  // 设置背景透明
                    "   border: none;"              // 去掉边框
                    "   text-decoration: underline;" // 设置文本下划线

                    "}"
                    );

        // 创建操作按钮并放置
        QCommandLinkButton *qclb1 = new QCommandLinkButton("删除", ui->tableWidget);
        qclb1->setIcon(QIcon());
        qclb1->setText("删除");
        qclb1->setFixedSize(50, 30); // 设置按钮大小
        //        // 设置按钮文本为蓝色并带下划线
        qclb1->setStyleSheet(
                    "QCommandLinkButton {"
                    "   color: red;"               // 设置文本颜色为蓝色
                    "   font-weight: bold;"         // 设置字体加粗
                    "   background-color: transparent;"  // 设置背景透明
                    "   border: none;"              // 去掉边框
                    "   text-decoration: underline;" // 设置文本下划线

                    "}"
                    );



        ui->tableWidget->setCellWidget(row, sqlre.count()-1, qclb); // 放置到最后一列
        ui->tableWidget->setCellWidget(row, sqlre.count(), qclb1);
        // 连接按钮点击事件
        connect(qclb, &QCommandLinkButton::clicked, this, [=]() {
            qDebug() << "修改按钮被点击，行号: " << row;
            // 处理修改逻辑
            QTableWidgetItem *item = ui->tableWidget->item(row, 1);
            ui->lineEdit_2->setText(item->text());
            item=ui->tableWidget->item(row,2);
            ui->lineEdit_3->setText(item->text());
            item=ui->tableWidget->item(row,0);
            edit_id=item->text();
            ui->tabWidget->setCurrentIndex(0);
        });
        // 连接按钮点击事件
        connect(qclb1, &QCommandLinkButton::clicked, this,[=](){
            QTableWidgetItem *item=ui->tableWidget->item(row,0);
            delet_id=item->text();
            //            qDebug()<<row;
            this->delete_event();
        });


        row++;
        cmd.next();  // 移动到下一条记录
    }
}
//车辆信息删除事件
void MainWindow::delete_event()
{
    QMessageBox  box(this);


    QPushButton *bt = new QPushButton("是(Y)");
    box.addButton(bt,QMessageBox::ActionRole);//添加自定义按钮


    QPushButton *bt1 = new QPushButton("否(N)");
    box.addButton(bt1,QMessageBox::ActionRole);//添加自定义按钮


    //设置标题
    box.setWindowTitle("删除项目");
    //设置提示信息
    box.setText("你确定将这项永久删除吗?");


    //设置默认小图标
    box.setIcon(QMessageBox::Warning);
    box.exec(); //执行窗口


    if (box.clickedButton() == bt) {
        qDebug() << "删除文件";
        QSqlQuery cmd(db);
        QString sql = QString("delete from car_info where id=%1")
                .arg(delet_id);
        qDebug()<<sql;
        if(cmd.exec(sql)){
            qDebug()<<"删除成功";
            QMessageBox::information(this,"消息","删除成功！",QMessageBox::Yes);
            this->on_pushButton_2_clicked();
        }else{
            qDebug()<<"删除失败";
            QMessageBox::information(this,"消息","删除失败！",QMessageBox::Yes);
        }
    } else if (box.clickedButton() == bt1) {
        qDebug() << "取消删除";
    }
}


//车辆保存修改按钮
void MainWindow::on_pushButton_4_clicked()
{

    if(ui->lineEdit_2->text()!=""&&ui->lineEdit_3->text()!=""){
        QSqlQuery cmd(db);
        QString sql = QString("UPDATE car_info SET license_plate='%1', card_number='%2' where id=%3")
                .arg(ui->lineEdit_2->text())
                .arg(ui->lineEdit_3->text())
                .arg(edit_id);
        qDebug()<<sql;
        if(cmd.exec(sql)){
            qDebug()<<"修改成功";
            QMessageBox::information(this,"消息","修改成功！",QMessageBox::Yes);
        }else{
            qDebug()<<"修改失败";
            QMessageBox::information(this,"消息","修改失败！",QMessageBox::Yes);
        }
    }
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    this->on_pushButton_2_clicked();
}

//添加按钮
void MainWindow::on_pushButton_5_clicked()
{

    if(ui->lineEdit_4->text()!=""&&ui->lineEdit_5->text()!=""){
        QSqlQuery cmd(db);
        QString sql = QString("insert into car_info(license_plate,card_number,card_balance) values('%1','%2',100)")
                .arg(ui->lineEdit_5->text())
                .arg(ui->lineEdit_4->text());
        qDebug()<<sql;
        if(cmd.exec(sql)){
            qDebug()<<"添加成功";
            QMessageBox::information(this,"消息","添加成功！",QMessageBox::Yes);
        }else{
            qDebug()<<"添加失败";
            QMessageBox::information(this,"消息","添加失败！",QMessageBox::Yes);
        }
    }
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    this->on_pushButton_2_clicked();
}
//获取数据
void MainWindow::loadCarConsumptionInfoTable(const QString &sql){
    QSqlQuery cmd(db);
    qDebug()<<sql;
    // 执行查询操作
    if (!cmd.exec(sql)) {
        qDebug() << "查询失败：" ;
        return;
    }

    QSqlRecord sqlre = db.record("car_consumption_info");

    // 获取表格行数
    int rowCount = 0;
    cmd.first(); // 定位到查询的第一行
    while (cmd.isValid()) {
        rowCount++;
        cmd.next();
    }

    // 设置表格行列
    ui->tableWidget_2->setColumnCount(sqlre.count()); // +1 for 操作 column
    ui->tableWidget_2->setRowCount(rowCount);
    ui->tableWidget_2->setColumnWidth(0, 54); // 设置列宽
    ui->tableWidget_2->setColumnWidth(3, 200); // 设置列宽
    ui->tableWidget_2->setColumnWidth(4, 200); // 设置列宽
    ui->tableWidget_2->setColumnWidth(5,100);
    ui->tableWidget_2->setColumnWidth(6,100);


    // 设置表头
    QStringList headers;
    for (int i = 0; i < sqlre.count(); ++i) {
        headers << sqlre.fieldName(i);
    }
    //    headers << "操作"<<"操作";
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);

    // 重新执行查询并遍历数据
    cmd.first(); // 定位到第一条记录
    int row = 0;
    while (cmd.isValid()) {
        // 插入数据
        for (int col = 0; col < sqlre.count(); ++col) {
            QString data=cmd.value(col).toString();
            if(col==5&&data!=""){
                data+="h";
            }
            if(col==6&&data!=""){
                data+="元";
            }
            QTableWidgetItem *item = new QTableWidgetItem(data);
            item->setTextAlignment(Qt::AlignCenter);  // 数据居中显示

            ui->tableWidget_2->setItem(row, col, item);
        }

        row++;
        cmd.next();  // 移动到下一条记录
    }
}

//消费信息页面切换按钮
void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    //获取消费信息
    loadCarConsumptionInfoTable("SELECT * FROM car_consumption_info");

}

//消费信息搜索按钮
void MainWindow::on_pushButton_7_clicked()
{
    QString val=ui->lineEdit_6->text();
    if(val==""){
        this->on_pushButton_6_clicked();
        return ;
    }

    QString sql = QString("SELECT * FROM car_consumption_info WHERE id='%1' OR license_plate='%1' OR card_number='%1'")
            .arg(val);
    //获取消费信息
    loadCarConsumptionInfoTable(sql);

}

//端口设置按钮
void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->lineEdit_9->setText(QString::number(entranceCamera_port));
    ui->lineEdit_10->setText(QString::number(entranceInfo_port));
    ui->lineEdit_11->setText(QString::number(exportCamera_port));
    ui->lineEdit_12->setText(QString::number(exportInfo_port));
    ui->lineEdit_13->setText(QString::number(audioTransmission_port));
}

//保存端口设置
void MainWindow::on_pushButton_11_clicked()
{

    //入口摄像头端口
    if(entranceCamera_port!=ui->lineEdit_9->text().toUInt()){
        disconnect(udp_recv, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams);
        udp_recv->close();
        udp_recv = new QUdpSocket(this);
        if (udp_recv->bind(QHostAddress::Any, ui->lineEdit_9->text().toUInt())) {
            qDebug() << "成功绑定到新端口:"<<ui->lineEdit_9->text().toUInt();
            connect(udp_recv, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams);
            entranceCamera_port=ui->lineEdit_9->text().toUInt();
        } else {
            qDebug() << "绑定端口失败1";
        }
    }
    //入口信息端口
    if(entranceInfo_port!=ui->lineEdit_10->text().toUInt()){
        disconnect(udp_recv_info, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info);
        udp_recv_info->close();
        udp_recv_info = new QUdpSocket(this);
        if (udp_recv_info->bind(QHostAddress::Any, ui->lineEdit_10->text().toUInt())) {
            qDebug() << "成功绑定到新端口:"<<ui->lineEdit_10->text().toUInt();
            connect(udp_recv_info, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info);
            entranceInfo_port=ui->lineEdit_10->text().toUInt();
        } else {
            qDebug() << "绑定端口失败2";
        }
    }
    //出口摄像头端口
    if(exportCamera_port!=ui->lineEdit_11->text().toUInt()){
        disconnect(udp_recv1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams1);
        udp_recv1->close();
        udp_recv1 = new QUdpSocket(this);
        if (udp_recv1->bind(QHostAddress::Any, ui->lineEdit_11->text().toUInt())) {
            qDebug() << "成功绑定到新端口:"<<ui->lineEdit_11->text().toUInt();
            connect(udp_recv1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams1);
            exportCamera_port=ui->lineEdit_11->text().toUInt();
        } else {
            qDebug() << "绑定端口失败3";
        }
    }
    //出口信息端口
    if(exportInfo_port!=ui->lineEdit_12->text().toUInt()){
        disconnect(udp_recv_info1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info1);
        udp_recv_info1->close();
        udp_recv_info1 = new QUdpSocket(this);
        if (udp_recv_info1->bind(QHostAddress::Any, ui->lineEdit_12->text().toUInt())) {
            qDebug() << "成功绑定到新端口:"<<ui->lineEdit_12->text().toUInt();
            connect(udp_recv_info1, &QUdpSocket::readyRead,this, &MainWindow::readPendingDatagrams_info1);
            exportInfo_port=ui->lineEdit_12->text().toUInt();
        } else {
            qDebug() << "绑定端口失败4";
        }
    }
}
