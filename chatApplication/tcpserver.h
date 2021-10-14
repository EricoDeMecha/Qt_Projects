#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);

signals:
public slots:
    void onNewConnection();
    void onReadyRead();
private:
QString getClientKey(QTcpSocket* client) const;
private:
    QTcpServer _server;
    QHash<String, QTcpSocket*> _clients;

};

#endif // TCPSERVER_H
