#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QtSerialBus>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Connect_clicked();

    void on_pushButton_Write_clicked();

    void on_pushButton_Read_clicked();

    void on_pushButton_Read_Input_clicked();

    void on_pushButton_Read_Input_Discreate_clicked();

    void on_pushButton_Write_Coils_clicked();

    void on_pushButton_Read_Coils_clicked();

private:
    Ui::MainWindow *ui;

    QModbusClient *MClient;
};
#endif // MAINWINDOW_H
