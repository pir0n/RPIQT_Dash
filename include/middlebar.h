#ifndef MIDDLEBAR_H
#define MIDDLEBAR_H

#include <QObject>
#include <QString>

class MiddleBar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool lowBeam READ lowBeam WRITE setlowBeam NOTIFY lowBeamChanged FINAL)
    Q_PROPERTY(bool highBeam READ highBeam WRITE sethighBeam NOTIFY highBeamChanged FINAL)
    Q_PROPERTY(bool parkingBrake READ parkingBrake WRITE setparkingBrake NOTIFY parkingBrakeChanged FINAL)
    Q_PROPERTY(unsigned int speedValue READ speedValue WRITE setspeedValue NOTIFY speedValueChanged FINAL)
    Q_PROPERTY(unsigned int rpmValue READ rpmValue WRITE setrpmValue NOTIFY rpmValueChanged FINAL)
    Q_PROPERTY(QString serialInfo READ serialInfo WRITE setserialInfo NOTIFY serialInfoChanged FINAL)

public:
    explicit MiddleBar(QObject *parent = nullptr);

    bool lowBeam() const;
    bool highBeam() const;

    bool parkingBrake() const;

    unsigned int speedValue() const;

    unsigned int rpmValue() const;

    QString serialInfo() const;

public slots:
    void setlowBeam(bool newLowBeam);
    void sethighBeam(bool newHighBeam);

    void setparkingBrake(bool newParkingBrake);

    void setspeedValue(unsigned int newSpeedValue);

    void setrpmValue(unsigned int newRpmValue);
    void setserialInfo(const QString &newSerialInfo);



signals:

    void lowBeamChanged();
    void highBeamChanged();

    void parkingBrakeChanged();

    void speedValueChanged();

    void rpmValueChanged();

    void serialInfoChanged();

private:
    bool m_lowBeam;
    bool m_highBeam;
    bool m_parkingBrake;
    unsigned int m_speedValue;
    unsigned int m_rpmValue;
    QString m_serialInfo;
};

#endif // MIDDLEBAR_H
