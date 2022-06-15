#ifndef MSERVERSIDE_H
#define MSERVERSIDE_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class mServerSide : public QObject
{
    Q_OBJECT
public:
    explicit mServerSide(QObject *parent = nullptr);
    void StartServer();
    QByteArray clientdata;
    bool connected;


signals:
public slots:
     void newConnection();
     void readyRead();

    private:
     QTcpServer *server;
     QTcpSocket* socket;

};

#endif // MSERVERSIDE_H
