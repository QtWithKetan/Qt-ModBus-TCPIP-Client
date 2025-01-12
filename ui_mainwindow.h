/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_Port_Host;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_Write;
    QPushButton *pushButton_Read;
    QListWidget *listWidget_Holding_Data;
    QPushButton *pushButton_Read_Input;
    QPushButton *pushButton_Read_Input_Discreate;
    QPushButton *pushButton_Write_Coils;
    QPushButton *pushButton_Read_Coils;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_Port_Host = new QLineEdit(centralwidget);
        lineEdit_Port_Host->setObjectName(QString::fromUtf8("lineEdit_Port_Host"));
        lineEdit_Port_Host->setGeometry(QRect(20, 10, 191, 22));
        pushButton_Connect = new QPushButton(centralwidget);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));
        pushButton_Connect->setGeometry(QRect(220, 10, 75, 24));
        pushButton_Write = new QPushButton(centralwidget);
        pushButton_Write->setObjectName(QString::fromUtf8("pushButton_Write"));
        pushButton_Write->setGeometry(QRect(300, 10, 221, 24));
        pushButton_Read = new QPushButton(centralwidget);
        pushButton_Read->setObjectName(QString::fromUtf8("pushButton_Read"));
        pushButton_Read->setGeometry(QRect(530, 10, 221, 24));
        listWidget_Holding_Data = new QListWidget(centralwidget);
        listWidget_Holding_Data->setObjectName(QString::fromUtf8("listWidget_Holding_Data"));
        listWidget_Holding_Data->setGeometry(QRect(300, 170, 460, 192));
        pushButton_Read_Input = new QPushButton(centralwidget);
        pushButton_Read_Input->setObjectName(QString::fromUtf8("pushButton_Read_Input"));
        pushButton_Read_Input->setGeometry(QRect(300, 50, 450, 24));
        pushButton_Read_Input_Discreate = new QPushButton(centralwidget);
        pushButton_Read_Input_Discreate->setObjectName(QString::fromUtf8("pushButton_Read_Input_Discreate"));
        pushButton_Read_Input_Discreate->setGeometry(QRect(300, 90, 450, 24));
        pushButton_Write_Coils = new QPushButton(centralwidget);
        pushButton_Write_Coils->setObjectName(QString::fromUtf8("pushButton_Write_Coils"));
        pushButton_Write_Coils->setGeometry(QRect(300, 130, 221, 24));
        pushButton_Read_Coils = new QPushButton(centralwidget);
        pushButton_Read_Coils->setObjectName(QString::fromUtf8("pushButton_Read_Coils"));
        pushButton_Read_Coils->setGeometry(QRect(530, 130, 221, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_Port_Host->setText(QCoreApplication::translate("MainWindow", "127.0.0.1:502", nullptr));
        pushButton_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Write->setText(QCoreApplication::translate("MainWindow", "Write The Holding Data", nullptr));
        pushButton_Read->setText(QCoreApplication::translate("MainWindow", "Read The Holding Data", nullptr));
        pushButton_Read_Input->setText(QCoreApplication::translate("MainWindow", "Read The Input  Data", nullptr));
        pushButton_Read_Input_Discreate->setText(QCoreApplication::translate("MainWindow", "Read The Discreate Input  Data", nullptr));
        pushButton_Write_Coils->setText(QCoreApplication::translate("MainWindow", "Write The Coils Data", nullptr));
        pushButton_Read_Coils->setText(QCoreApplication::translate("MainWindow", "Read The Coils Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
