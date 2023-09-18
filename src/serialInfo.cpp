#include <QSerialPortInfo>
#include <QDebug>
#include <QList>

void printSerialInfo() {
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    qDebug() << serialPortInfos[0].portName();
    for (const QSerialPortInfo &portInfo : serialPortInfos) {
        qDebug() << "\n"
                 << "Port:" << portInfo.portName() << "\n"
                 << "Location:" << portInfo.systemLocation() << "\n"
                 << "Description:" << portInfo.description() << "\n"
                 << "Manufacturer:" << portInfo.manufacturer() << "\n"
                 << "Serial number:" << portInfo.serialNumber() << "\n"
                 << "Vendor Identifier:"
                 << (portInfo.hasVendorIdentifier()
                         ? QByteArray::number(portInfo.vendorIdentifier(), 16)
                         : QByteArray()) << "\n"
                 << "Product Identifier:"
                 << (portInfo.hasProductIdentifier()
                         ? QByteArray::number(portInfo.productIdentifier(), 16)
                         : QByteArray());
    }
}

QList <QSerialPortInfo>  getSerialInfo()
{

    const auto serialPortInfos = QSerialPortInfo::availablePorts();


    return serialPortInfos;
}



