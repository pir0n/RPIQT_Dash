//#ifndef SERIALDATATRANSMIT_H
//#define SERIALDATATRANSMIT_H

//#include <QObject>


//class SerialDataTransmit : public QObject
//{
//    Q_OBJECT



//public:
//    explicit SerialDataTransmit(QObject *parent = nullptr);

//signals:

//};

//#endif // SERIALDATATRANSMIT_H

#ifndef UARTREADER_H
#define UARTREADER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class UartReader : public QObject
{
    Q_OBJECT

public:
    explicit UartReader(QObject *parent = nullptr);
    ~UartReader();

signals:
    void newDataReceived(uint rpm, int oilTemp, uint speed, bool beamLights);

private slots:
    void readData();

private:
    QSerialPort *serialPort;
};

#endif // UARTREADER_H

