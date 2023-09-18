#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

//SerialDataTransmit::SerialDataTransmit(QObject *parent)
//    : QObject{parent}
//{
//}

#include "../include/serialdatatransmit.h"

UartReader::UartReader(QObject *parent) : QObject(parent)
{
    serialPort = new QSerialPort(this);

    connect(serialPort, &QSerialPort::readyRead, this, &UartReader::readData);

    // Configure the serial port settings
    serialPort->setPortName("/dev/ttyS0"); // Update this with the correct port name
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite))
    {
        qDebug() << "Serial port opened successfully.";
    }
    else
    {
        qDebug() << "Failed to open serial port.";
    }
}

UartReader::~UartReader()
{
    serialPort->close();
}

void UartReader::readData()
{
    QByteArray data = serialPort->readAll();

    if (!data.isEmpty())
    {
        // Assuming that the STM32F4 sends data in the format: RPM(uint) | Oil Temp(int) | Speed(uint) | Beam Lights(bool)
        if (data.size() == 10) // Assuming 4 bytes each for uint and int, and 1 byte for bool
        {
            uint rpm = static_cast<uint>(data.mid(0, 4).toUInt());
            int oilTemp = static_cast<int>(data.mid(4, 4).toInt());
            uint speed = static_cast<uint>(data.mid(8, 4).toUInt());
            bool beamLights = static_cast<bool>(data.at(12));

            emit newDataReceived(rpm, oilTemp, speed, beamLights);
        }
        else
        {
            qDebug() << "Received data size mismatch.";
        }
    }
}

