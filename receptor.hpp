#ifndef RECEPTOR_H
#define RECEPTOR_H

#include <QObject>
class QUdpSocket;
class Receptor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float pitch READ pitch WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(float roll READ roll WRITE setRoll NOTIFY rollChanged)
    Q_PROPERTY(float yaw READ yaw WRITE setYaw NOTIFY yawChanged)
public:
    explicit Receptor(QObject *parent = 0);
    ~Receptor();
signals:
    void pitchChanged(float);
    void rollChanged(float);
    void yawChanged(float);
public:
    float pitch() const;
    float roll() const;
    float yaw() const;
public slots:
    void procesarDatagramas();
    void setPitch(float n);
    void setRoll(float n);
    void setYaw(float n);
private:
    float m_pitch;
    float m_roll;
    float m_yaw;
    QUdpSocket *m_udpSocket;
};

#endif // RECEPTOR_H
