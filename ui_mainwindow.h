/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_31;
    QLabel *label_17;
    QLabel *label_27;
    QLabel *label_29;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_16;
    QLabel *label_23;
    QLabel *label_18;
    QLabel *label_28;
    QLabel *label_30;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QWidget *tab_3;
    QLabel *label_21;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_22;
    QPushButton *pushButton_5;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_7;
    QTableWidget *tableWidget_2;
    QWidget *page_4;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    QLabel *label_26;
    QLineEdit *lineEdit_9;
    QSplitter *splitter_4;
    QLabel *label_33;
    QLineEdit *lineEdit_11;
    QSplitter *splitter_3;
    QLabel *label_32;
    QLineEdit *lineEdit_10;
    QSplitter *splitter_5;
    QLabel *label_34;
    QLineEdit *lineEdit_12;
    QSplitter *splitter_6;
    QLabel *label_35;
    QLineEdit *lineEdit_13;
    QPushButton *pushButton_11;
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1020, 0, 581, 801));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_5 = new QGroupBox(page);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout_4->addWidget(label_5);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_4->addWidget(label_7);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        verticalLayout_4->addWidget(label_9);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout_3->addWidget(label_6);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout_3->addWidget(label_8);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout_3->addWidget(label_10);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        verticalLayout_5->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(page);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        label_11->setFont(font2);

        verticalLayout_2->addWidget(label_11);

        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font2);

        verticalLayout_2->addWidget(label_13);

        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font2);

        verticalLayout_2->addWidget(label_15);

        label_31 = new QLabel(groupBox_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font2);

        verticalLayout_2->addWidget(label_31);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);

        verticalLayout_2->addWidget(label_17);

        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font2);

        verticalLayout_2->addWidget(label_27);

        label_29 = new QLabel(groupBox_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);

        verticalLayout_2->addWidget(label_29);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(true);
        font3.setWeight(75);
        font3.setStrikeOut(false);
        label_12->setFont(font3);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_12);

        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font3);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_14);

        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font3);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_16);

        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font3);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_23);

        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font3);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_18);

        label_28 = new QLabel(groupBox_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_28);

        label_30 = new QLabel(groupBox_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font3);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));

        verticalLayout->addWidget(label_30);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_5->addWidget(groupBox_6);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_6->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(tableWidget);

        tabWidget = new QTabWidget(page_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setIconSize(QSize(16, 16));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 20, 144, 36));
        QFont font4;
        font4.setPointSize(18);
        label_19->setFont(font4);
        label_20 = new QLabel(tab);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 100, 108, 36));
        label_20->setFont(font4);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(180, 100, 351, 41));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 20, 351, 41));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(400, 250, 131, 51));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 20, 144, 36));
        label_21->setFont(font4);
        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(180, 100, 351, 41));
        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(180, 20, 351, 41));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 100, 108, 36));
        label_22->setFont(font4);
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(400, 250, 131, 51));
        tabWidget->addTab(tab_3, QString());

        verticalLayout_6->addWidget(tabWidget);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit_6 = new QLineEdit(page_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_3->addWidget(lineEdit_6);

        pushButton_7 = new QPushButton(page_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);


        verticalLayout_7->addLayout(horizontalLayout_3);

        tableWidget_2 = new QTableWidget(page_3);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(tableWidget_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        groupBox_7 = new QGroupBox(page_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 551, 451));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter_2 = new QSplitter(groupBox_7);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        label_26 = new QLabel(splitter_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QFont font5;
        font5.setPointSize(13);
        label_26->setFont(font5);
        splitter_2->addWidget(label_26);
        lineEdit_9 = new QLineEdit(splitter_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setFont(font5);
        splitter_2->addWidget(lineEdit_9);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);

        splitter_4 = new QSplitter(groupBox_7);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_33 = new QLabel(splitter_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font5);
        splitter_4->addWidget(label_33);
        lineEdit_11 = new QLineEdit(splitter_4);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setFont(font5);
        splitter_4->addWidget(lineEdit_11);

        gridLayout_3->addWidget(splitter_4, 1, 0, 1, 1);

        splitter_3 = new QSplitter(groupBox_7);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_32 = new QLabel(splitter_3);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font5);
        splitter_3->addWidget(label_32);
        lineEdit_10 = new QLineEdit(splitter_3);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setFont(font5);
        splitter_3->addWidget(lineEdit_10);

        gridLayout_3->addWidget(splitter_3, 2, 0, 1, 1);

        splitter_5 = new QSplitter(groupBox_7);
        splitter_5->setObjectName(QString::fromUtf8("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_34 = new QLabel(splitter_5);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font5);
        splitter_5->addWidget(label_34);
        lineEdit_12 = new QLineEdit(splitter_5);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setFont(font5);
        splitter_5->addWidget(lineEdit_12);

        gridLayout_3->addWidget(splitter_5, 3, 0, 1, 1);

        splitter_6 = new QSplitter(groupBox_7);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        label_35 = new QLabel(splitter_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font5);
        splitter_6->addWidget(label_35);
        lineEdit_13 = new QLineEdit(splitter_6);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setFont(font5);
        splitter_6->addWidget(lineEdit_13);

        gridLayout_3->addWidget(splitter_6, 4, 0, 1, 1);

        pushButton_11 = new QPushButton(groupBox_7);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout_3->addWidget(pushButton_11, 5, 0, 1, 1);

        stackedWidget->addWidget(page_4);
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(1130, 790, 371, 51));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        splitter->addWidget(pushButton);
        pushButton_2 = new QPushButton(splitter);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        splitter->addWidget(pushButton_2);
        pushButton_6 = new QPushButton(splitter);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        splitter->addWidget(pushButton_6);
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(1520, 790, 61, 51));
        pushButton_10->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1011, 831));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 27, 521, 381));
        label->setStyleSheet(QString::fromUtf8("image: url(:/OIP.jpg);"));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 30, 521, 381));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/OIP-C.jpg);"));

        gridLayout_2->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 30, 521, 381));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/OIP-C.jpg);"));

        gridLayout_2->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 521, 381));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/OIP.jpg);"));

        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\350\275\246\344\277\251\344\277\241\346\201\257", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\350\277\233\345\234\272\346\227\266\351\227\264:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "label_6", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "label_8", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "label_10", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\346\234\200\350\277\221\345\207\272\345\234\272\350\275\246\344\277\251\344\277\241\346\201\257", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267:", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\350\277\233\345\234\272\346\227\266\351\227\264:", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\345\207\272\345\234\272\346\227\266\351\227\264:", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\346\227\266\351\225\277:", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\346\266\210\350\264\271\351\207\221\351\242\235:", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "\345\215\241\345\211\251\344\275\231\351\207\221\351\242\235:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "label_12", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "label_14", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "label_16", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "label_23", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "label_18", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "label_28", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "label_30", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\346\220\234\347\264\242\347\232\204\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267\357\274\232", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267\357\274\232", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "  \344\277\256\346\224\271  ", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267\357\274\232", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267\357\274\232", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\346\267\273\345\212\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "  \346\267\273\345\212\240  ", nullptr));
        lineEdit_6->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\246\201\346\220\234\347\264\242\347\232\204\344\277\241\346\201\257", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "\347\253\257\345\217\243\350\256\276\347\275\256", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\345\205\245\345\217\243\346\221\204\345\203\217\345\244\264:", nullptr));
        lineEdit_9->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\243\346\221\204\345\203\217\345\244\264:", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\345\205\245\345\217\243\344\277\241\346\201\257:", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\243\344\277\241\346\201\257:", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "\350\257\255\351\237\263\346\222\255\346\212\245:", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\275\246\350\276\206\344\277\241\346\201\257", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", " \346\266\210\350\264\271\344\277\241\346\201\257", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\205\245\345\217\243\346\221\204\345\203\217\345\244\264", nullptr));
        label->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\345\207\272\345\217\243\350\275\246\350\276\206\346\234\200\350\277\221\347\205\247\347\211\207", nullptr));
        label_4->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\205\245\345\217\243\350\275\246\350\276\206\346\234\200\350\277\221\347\205\247\347\211\207", nullptr));
        label_3->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\207\272\345\217\243\346\221\204\345\203\217\345\244\264", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
