#include "receptor.hpp"
#include <QUdpSocket>
Receptor::Receptor(QObject *parent) : QObject(parent)
{
    m_udpSocket = new QUdpSocket(this);
    m_udpSocket->bind(2020, QUdpSocket::ShareAddress);
    connect(m_udpSocket, SIGNAL(readyRead()), this,
                    SLOT(procesarDatagramas()));
}

Receptor::~Receptor(){
    m_udpSocket->close();

}

float Receptor::pitch()const{
    return m_pitch;
}

float Receptor::roll()const{
    return m_roll;
}

float Receptor::yaw()const{
    return m_yaw;
}

void Receptor::setPitch(float n){
    if(n!=m_pitch){
        m_pitch =n;
        emit pitchChanged(n);
    }
}

void Receptor::setRoll(float n){
    if(n!=m_roll){
        m_roll =n;
        emit rollChanged(n);
    }
}

void Receptor::setYaw(float n){
    if(n!=m_yaw){
        m_yaw =n;
        emit yawChanged(n);
    }
}

void Receptor::procesarDatagramas(){
    while (m_udpSocket->hasPendingDatagrams()) {
        // Create a temporary buffer ...
        QByteArray datagram;

        // ... with the size of the received datagram ...
        datagram.resize(m_udpSocket->pendingDatagramSize());

        // ... and copy over the received datagram into that buffer.
        m_udpSocket->readDatagram(datagram.data(), datagram.size());

        // Update the 'status' property with the content of the received datagram
        if(datagram.size()>=12){
            float* addr = (float*)datagram.data();
            emit setPitch( addr[0]);
            emit setRoll(  addr[1]);
            emit setYaw(   addr[2]);
        }
    }

}




