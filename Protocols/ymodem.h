#ifndef YMODEM_H
#define YMODEM_H

#include <QObject>

class Ymodem : public QObject
{
    Q_OBJECT
public:
    explicit Ymodem(QObject *parent = nullptr);

signals:
};

#endif // YMODEM_H
