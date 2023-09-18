#include "../include/middlebar.h"
#include "../include/serialInfo.h"
#include <QList>
#include <QString>
#include <QTextStream>

MiddleBar::MiddleBar(QObject *parent)
    : QObject{parent}
    , m_lowBeam (false)
    , m_highBeam (false)
    , m_parkingBrake (false)
    , m_speedValue (0)
    , m_rpmValue (0)
    , m_serialInfo ("")
{

}

bool MiddleBar::lowBeam() const
{
    return m_lowBeam;
}

void MiddleBar::setlowBeam(bool newLowBeam)
{
    if (m_lowBeam == newLowBeam)
        return;
    m_lowBeam = newLowBeam;
    emit lowBeamChanged();
}

bool MiddleBar::highBeam() const
{
    return m_highBeam;
}

void MiddleBar::sethighBeam(bool newHighBeam)
{
    if (m_highBeam == newHighBeam)
        return;
    m_highBeam = newHighBeam;
    emit highBeamChanged();
}

bool MiddleBar::parkingBrake() const
{
    return m_parkingBrake;
}

void MiddleBar::setparkingBrake(bool newParkingBrake)
{
    if (m_parkingBrake == newParkingBrake)
        return;
    m_parkingBrake = newParkingBrake;
    emit parkingBrakeChanged();
}

unsigned int MiddleBar::speedValue() const
{
    return m_speedValue;
}

void MiddleBar::setspeedValue(unsigned int newSpeedValue)
{
    if (m_speedValue == newSpeedValue)
        return;
    m_speedValue = newSpeedValue;
    emit speedValueChanged();
}

unsigned int MiddleBar::rpmValue() const
{
    return m_rpmValue;
}

void MiddleBar::setrpmValue(unsigned int newRpmValue)
{
    if (m_rpmValue == newRpmValue)
        return;
    m_rpmValue = newRpmValue;
    emit rpmValueChanged();
}

QString MiddleBar::serialInfo() const
{
    QString output_string_serial;
    QList <QSerialPortInfo> listSerial;
    listSerial = getSerialInfo();

    for (const QSerialPortInfo &portInfo : listSerial) {
    QTextStream(&output_string_serial) << "PORT NAME: " << portInfo.portName() << "\n"
                                       << "Location: " << portInfo.systemLocation() << "\n"
                                       << "\n";
    }

    return output_string_serial;
}

void MiddleBar::setserialInfo(const QString &newSerialInfo)
{

    if (m_serialInfo == newSerialInfo)
        return;
    m_serialInfo = newSerialInfo;
    emit serialInfoChanged();
}
