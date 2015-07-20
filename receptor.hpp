#ifndef RECEPTOR_H
#define RECEPTOR_H

#include <QObject>

class Receptor : public QObject
{
    Q_OBJECT
public:
    explicit Receptor(QObject *parent = 0);

signals:

public slots:
};

#endif // RECEPTOR_H
