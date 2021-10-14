#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent) : QObject(parent)
{
    connect(&_server, &QTcpServer::newConnection, this, &TCPServer::onNewConnection);
    if(_server.listen(QHostAddress::Any, 45000)){
        qInfo() << "Listening...";
    }
}
void TCPServer::onNewConnection(){
    const auto client = _server.nextPendingConnection();
    if(client == nullptr){
          return;
    }
    qInfo() << "New client connected. ";
    _clients.insert(this->getClientKey(client),client);
    connect(client, &QTcpSocket::readyRead, this, &TCPServer::onReadyRead);
}
QString TCPServer::getClientKey(QTcpSocket* client) const{
    return client->peerAddress().toString().append(":").append(QString::number(client->peerPort()));
}

void TCPServer::onReadyRead(){
    const auto client = qobject_cast<QTcpSocket*>(sender());
    if(client == nullptr){
        return;
    }
    const auto messages =this->getClientKey(client) + ":" +client->readAll();
    emit newMessage(messages);
}
