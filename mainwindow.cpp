#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Connect_clicked()
{
    MClient = new QModbusTcpClient(this);

    const QUrl url = QUrl::fromUserInput(ui->lineEdit_Port_Host->text());

    MClient->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());
    MClient->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
    MClient->setTimeout(1000);
    MClient->setNumberOfRetries(5);

    if (!MClient->connectDevice())
    {
        qDebug() << "Connection failed : " << MClient->errorString();
        statusBar()->showMessage("Connection failed : " + MClient->errorString());
    }
    else
    {
        qDebug() << "Connection is done";
        statusBar()->showMessage("Connection is done");
    }
}

void MainWindow::on_pushButton_Write_clicked()
{
    QVector<quint16> DataToWrite;
    DataToWrite.append(100);
    DataToWrite.append(200);
    DataToWrite.append(300);
    DataToWrite.append(400);
    DataToWrite.append(500);

    QModbusDataUnit WriteUnit(QModbusDataUnit::HoldingRegisters, 0, DataToWrite.size());
    for (int i = 0 ; i < DataToWrite.size() ; i++)
    {
        WriteUnit.setValue(i, DataToWrite.at(i));
    }

    if (auto *reply = MClient->sendWriteRequest(WriteUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
               if (reply->error() == QModbusDevice::NoError)
               {
                   qDebug() << "Data is write sucessfully";
                   statusBar()->showMessage("Data is write sucessfully");
               }
               else
               {
                   qDebug() << "Data is write failed";
                   statusBar()->showMessage("Data is write failed : " + reply->errorString());
               }
            });
        }
    }
}
void MainWindow::on_pushButton_Read_clicked()
{
    QModbusDataUnit ReadUnit(QModbusDataUnit::HoldingRegisters, 0, 10);
    if (auto *reply = MClient->sendReadRequest(ReadUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
               auto reply_1 =  qobject_cast<QModbusReply*>(sender());
               if (!reply_1) return;

               if (reply_1->error() == QModbusDevice::NoError)
               {
                   qDebug() << "Data read sucessfully";
                   statusBar()->showMessage("Data read sucessfully");

                   const QModbusDataUnit units = reply_1->result();
                   ui->listWidget_Holding_Data->clear();
                   for (int i = 0 ; i < units.valueCount() ; i++)
                   {
                       QString Entry = "Address : " + QString::number(units.startAddress() + i) + " Values : " + QString::number(units.value(i), 16) + " | " + QString::number(units.value(i));
                       ui->listWidget_Holding_Data->addItem(Entry);
                   }
               }
               else
               {
                   qDebug() << "Data read failed";
                   statusBar()->showMessage("Data read failed : " + reply_1->errorString());
               }
            });
        }
    }
}
void MainWindow::on_pushButton_Read_Input_clicked()
{
    QModbusDataUnit ReadUnit(QModbusDataUnit::InputRegisters, 0, 10);
    if (auto *reply = MClient->sendReadRequest(ReadUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
               auto reply_1 = qobject_cast<QModbusReply*>(sender()) ;
               if (!reply_1) return;

               if (reply_1->error() == QModbusDevice::NoError)
               {
                   qDebug() << "Data Read sucessfully";
                   statusBar()->showMessage("Data Read sucessfully");

                   const QModbusDataUnit units = reply_1->result();
                   ui->listWidget_Holding_Data->clear();
                   for (int i = 0 ; i < units.valueCount() ; i++)
                   {
                       QString Entry = "Address : " + QString::number(units.startAddress() + i) + " Values : " + QString::number(units.value(i), 16) + " | " + QString::number(units.value(i), 10);
                       ui->listWidget_Holding_Data->addItem(Entry);
                   }
               }
               else
               {
                    qDebug() << "Data Read Failed : " + reply_1->errorString();
                    statusBar()->showMessage("Data Read Failed : " + reply_1->errorString());
               }
            });
        }
    }
}
void MainWindow::on_pushButton_Read_Input_Discreate_clicked()
{
    QModbusDataUnit ReadUnit(QModbusDataUnit::DiscreteInputs, 0, 10);
    if (auto *reply = MClient->sendReadRequest(ReadUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
               auto reply_1 = qobject_cast<QModbusReply*>(sender()) ;
               if (!reply_1) return;

               if (reply_1->error() == QModbusDevice::NoError)
               {
                   qDebug() << "Data Read sucessfully";
                   statusBar()->showMessage("Data Read sucessfully");

                   const QModbusDataUnit units = reply_1->result();
                   ui->listWidget_Holding_Data->clear();
                   for (int i = 0 ; i < units.valueCount() ; i++)
                   {
                       QString Entry = "Address : " + QString::number(units.startAddress() + i) + " Values : " + QString::number(units.value(i), 10);
                       ui->listWidget_Holding_Data->addItem(Entry);
                   }
               }
               else
               {
                    qDebug() << "Data Read Failed : " + reply_1->errorString();
                    statusBar()->showMessage("Data Read Failed : " + reply_1->errorString());
               }
            });
        }
    }
}
void MainWindow::on_pushButton_Write_Coils_clicked()
{
    QBitArray CoilsBits(10);
    CoilsBits.setBit(0);
    CoilsBits.clearBit(1);
    CoilsBits.setBit(2);
    CoilsBits.clearBit(3);
    CoilsBits.setBit(4);
    CoilsBits.setBit(5);
    CoilsBits.setBit(6);
    CoilsBits.setBit(7);
    CoilsBits.setBit(8);
    CoilsBits.setBit(9);

    QModbusDataUnit WriteUnits(QModbusDataUnit::Coils, 0, CoilsBits.size());
    for (int i = 0 ; i < CoilsBits.size() ; i++)
    {
        WriteUnits.setValue(i, CoilsBits.at(i));
    }

    if (auto *reply = MClient->sendWriteRequest(WriteUnits, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
                if (reply->error() == QModbusDevice::NoError)
                {
                    qDebug() << "Coils Write Sucessfully";
                    statusBar()->showMessage("Coils Write Sucessfully");
                }
                else
                {
                    qDebug() << "Coils Write Failed : " + reply->errorString();
                    statusBar()->showMessage("Coils Write Failed : " + reply->errorString());
                }
            });
        }
    }
}
void MainWindow::on_pushButton_Read_Coils_clicked()
{
    QModbusDataUnit ReadUnit(QModbusDataUnit::Coils, 0, 10);
    if (auto *reply = MClient->sendReadRequest(ReadUnit, 1))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]()
            {
                auto reply_1 = qobject_cast<QModbusReply*>(sender());
                if (!reply_1) return;

                if (reply_1->error() == QModbusDevice::NoError)
                {
                    qDebug() << "Coils Read Sucessfully";
                    statusBar()->showMessage("Coils Read Sucessfully");

                    const QModbusDataUnit Units = reply_1->result();
                    ui->listWidget_Holding_Data->clear();
                    for (int i = 0; i < Units.valueCount() ; i++)
                    {
                        QString Entry = "Address : " + QString::number(i + Units.startAddress()) + " Value : " + QString::number(Units.value(i), 10);
                        ui->listWidget_Holding_Data->addItem(Entry);
                    }
                }
                else
                {
                    qDebug() << "Coils Read Failed : " + reply->errorString();
                    statusBar()->showMessage("Coils Read Failed : " + reply->errorString());
                }
            });
        }
    }
}

