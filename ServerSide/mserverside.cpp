#include "mserverside.h"
#include "global.h"
#include "mainwindow.h" "

#include<QStringList>
#include <QString>
#include <QDebug>


mServerSide::mServerSide(QObject *parent) : QObject(parent)
{

}


void mServerSide::StartServer(){

    server = new QTcpServer(this);


    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()) );


    if(!server->listen(QHostAddress::Any,1234)){

        qDebug()<<"Server Couldn't Start ";

    }
    else{
        qDebug()<<"Server started";

    }



}


void mServerSide::newConnection(){

    socket = server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

   // socket->flush();
   //socket->waitForBytesWritten(10000);
    //socket->close();



};

void mServerSide::readyRead(){


    QByteArray data_buffer;
    clientdata=0;

    while(1){
        data_buffer= socket->read(1024);
        if(data_buffer.isEmpty()){
            break;
        }
        clientdata.append(data_buffer);
        qDebug()<<"recieved\n";

    };
   global::data = QString(clientdata).split(" ")[0];
   global::dataName = QString(clientdata).split(" ")[1];

   qDebug()<<QString(QString(clientdata).split(" ")[1]);


}




