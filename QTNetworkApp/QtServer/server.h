#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>

class Server : public QObject
{
    Q_OBJECT public:
    explicit Server(QObject *parent = nullptr);
    signals:

    public slots:
        void registerCon();
        void readData();
    private:
        QTcpServer server;
        quint16 port;

};

#endif // SERVER_H
