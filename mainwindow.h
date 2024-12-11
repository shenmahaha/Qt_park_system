#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadCarInfoTable(const QString &sql);
    void delete_event();
    void loadCarConsumptionInfoTable(const QString &sql);
    void readPendingDatagrams();
    void new_connect();
    void readPendingDatagrams_info();
    void readPendingDatagrams1();
    void readPendingDatagrams_info1();
    void vehicleExit(QString plate,QString cardId,QString time);
    void vehicleEntry(QString plate,QString cardId,QString time);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap camera_pic;
    QPixmap camera_pic1;
    QPixmap admission_pic;
    QPixmap exit_pic;
};
#endif // MAINWINDOW_H
