#include "client.h"


Client::Client(QObject *parent): QObject(parent) {
    registerSlots();
    Init();
}

Client::Client(QString address, quint16 port) {
    registerSlots();
    Init();

    Connect2Host(address, port);
}

Client::~Client() {
    DisconnectFromHost();
}

void Client::Connect2Host(QString address, quint16 port) {
    QHostAddress addr(address);
    socket.connectToHost(addr, port);
}

void Client::DisconnectFromHost() {
    socket.disconnectFromHost();
    socket.close();
}

bool Client::isConneted() {
    std::cout<<socket.errorString().toStdString();
    return this->hasConnection;
}

bool Client::writeData(QString str)
{
    if(this->hasConnection)
    {
        socket.waitForConnected();
        socket.write(str.toStdString().c_str());
    }

    return socket.flush();
}

QString Client::dataReceived()
{
    return this->bytesReaded;
}

void Client::Init() {
    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        this->networkSession = new QNetworkSession(config, this);
        connect(this->networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        this->networkSession->open();
    }
}

void Client::registerSlots() {
    connect(&socket, SIGNAL(connected()), this, SLOT(Awake()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void Client::Awake() {
    this->hasConnection = true;
    emit connectionSuccessful();
}

void Client::readData(){
    char buffer[1024] = {0};
    unsigned sizeChar = socket.bytesAvailable();
    socket.read(buffer, socket.bytesAvailable());

    this->bytesReaded.clear();
    for(unsigned i = 0; i < sizeChar; ++i)
        this->bytesReaded.append(buffer[i]);

    emit this->hasReadData();
}
