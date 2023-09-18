#ifndef SERIALINFO_H
#define SERIALINFO_H
#include <QString>
#include <QStringList>
#include <QSerialPortInfo>

void printSerialInfo();
QList <QSerialPortInfo>  getSerialInfo();

#endif // SERIALINFO_H
