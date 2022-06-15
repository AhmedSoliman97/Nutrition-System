#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mySocket = new QTcpSocket(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_submit_clicked()
{

        char myChar[1024];QString str;

        float weight = (ui->lineEdit_weight_2->text()).toFloat();
        float height = ((ui->lineEdit_height_2->text()).toFloat()) -100;
        QString name = ui->lineEdit_name_2->text();
        int age = (ui->lineEdit_age_2->text()).toInt() ;
        QString gender = ui->comboBox_gender_2->currentText();
        QString diseases = ui->comboBox_diseases_2->currentText();
        QString bloodPressure = ui->lineEdit_bloodpressure->text();
        QString mail = ui->lineEdit_mail_2->text();

        if(! (ui->lineEdit_weight_2->isModified() || ui->lineEdit_height_2->isModified() || ui->lineEdit_name_2->isModified() ||  ui->lineEdit_age_2->isModified()  || ui->lineEdit_bloodpressure->isModified() || ui->lineEdit_mail_2->isModified()) ){
           QMessageBox::warning(this,"Diet System","Please Fill All Data" );
        }
        else{

            //******** start connecting the server ************************

            mySocket->connectToHost("127.0.0.1",1234);
            if(! mySocket->waitForConnected(3000)){
                QMessageBox::warning(this,"Diet System","Server not Connected Please Try Again" );
            }
            else{
                 qDebug()<<"connected to server";

                if(height < weight){

                   if( ( weight-height) >10){
                    //so much fat
                       str="veryFat";
                   }
                   else{
                    //not much fat
                       str="Fat";
                   }
                }

                else if(height == weight){

                    //have perfect body
                       str="Perfect";
                }

                else{
                    if((height-weight) <10){
                        // not so thin
                           str="veryThin";
                    }
                    else{
                       str="Thin";
                    }
                }
                str= str+" "+name;
                memset(myChar,'\0',sizeof(myChar) +1);
                memcpy(myChar,str.toUtf8(),str.length());

                if(mySocket->isWritable()){
                    mySocket->write(myChar);
                    mySocket->waitForBytesWritten(1000);
                }
                 QMessageBox::information(this,"Client Side","Server Connected and Data is up to it" );


            }





        }







}



