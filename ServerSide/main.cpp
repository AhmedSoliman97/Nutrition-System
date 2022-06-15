#include "mainwindow.h"
#include "mserverside.h"
#include "global.h"

#include <QDebug>
#include <QObject>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);




    //first establish the server
    mServerSide Server;
    Server.StartServer();
    MainWindow w;
    w.show();






    return a.exec();
}
