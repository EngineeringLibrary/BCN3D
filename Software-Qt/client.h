#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <iostream>
#include <string>

using namespace std;

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client  (QObject *parent = 0);
             Client  (QString address = "", quint16 port = 0);
             ~Client ();

    void Connect2Host(QString address, quint16 port);
    void DisconnectFromHost();

    bool writeData(QString str);
    bool isConneted();

    QString dataReceived();

private:
    bool hasConnection;

    QTcpSocket socket;
    QString bytesReaded;
    QNetworkSession *networkSession;


    void Init();
    void registerSlots();

signals:
    void hasReadData();
    void connectionSuccessful();

private slots:
    void readData();
    void Awake();

};


#endif // CLIENT_H
