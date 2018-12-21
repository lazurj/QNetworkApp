#include "server.h"

Server::Server(QObject *parent) : QObject(parent) {
    connect(&this->server, SIGNAL(newConnection()), this, SLOT(registerCon()));
    this->port = 9999;
    this->server.listen(QHostAddress::LocalHost,this->port) ? qDebug() << "Server is running..." : qDebug() << "A problem has occured.";

}

void Server::registerCon() {
    qDebug() << "New connection has just arrived.";
    //run in new Thread
    QTcpSocket *clientConnection = this->server.nextPendingConnection();
    connect(&clientConnection, SIGNAL(readyRead()), this, SLOT(readData())) ;
    // this provides the socket for coomunication with the client
//     connect(clientConnection, SIGNAL(disconnected()),
  //           clientConnection, SLOT(deleteLater()));
     //clientConnection->disconnectFromHost();
}


void Server::readData() {
    QTcpSocket *clientConnection = this->server.nextPendingConnection();
//    while (clientConnection->bytesAvailable() > 0) {
  //      char buffer[300*300]={0};
    //    clientConnection->read(buffer, clientConnection->bytesAvailable());
      //  qDebug()<<"buffer data:"<<QByteArray(buffer,70).toHex();
    //11}
}
