#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"

#include <QTime>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMessageBox::information(this,"Server","Server is listening...");

       ui->plainTextEdit_dietdata->appendPlainText("no Data yet");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_done_clicked()
{
    if(global::data != "no Data yet"){
        global::ratePressed=1;
        global::rate = (ui->lineEdit_rateValue->text()).toInt();
        QString rate ="You Rate us: "+ui->lineEdit_rateValue->text();
        ui->lineEdit_rateValue->clear();

        ui->plainTextEdit_dietdata->appendPlainText(rate);
    }


}


void MainWindow::on_pushButton_clicked()
{
    int i=0;
    while(i>1000){
        i++;
    };
    ui->plainTextEdit_dietdata->clear();
    ui->plainTextEdit_dietdata->appendPlainText(global::data);




    if(global::data != "no Data yet" ){

        QString name="Hi  "+global::dataName+" depend on your health data which make you have "+ global::data+" body we suggest you this diet plan :";

        ui->label_name->setText(name);
        ui->plainTextEdit_dietdata->clear();
        ui->plainTextEdit_dietdata->appendPlainText("Server is Connected");

        QMap<QString,QStringList> foodList;

        int high =15;int low =0;int randomValue;

        randomValue = int(qrand() % ((high + 1) - low) + low) ;

        qDebug()<<QString(randomValue);



        foodList.insert("Breakfast",{"Orange Juice","Butter","Wheat Toast","Goat's Milk",
                                    "Salmon","Bacon","Buckwheat","Tea","Banana","Coffee","Chicken Egg","Honey Dew","Apricot",
                                    "Blueberry","Beet Suger","Apple Juice"});

        foodList.insert("Lunch",{"Beef","Wheat Bun","Cows's Milk","Cheese","Tomato","Butter","CatFish","Okra","Apple","Pork Chop",
                                 "Green Beans","Brocoli","Cod",
                                 "Vinegar","Cashew","Chicken","Curry Powder","Jicama","Carrots","Goat's Milk Cheese","Multon","Beef",
                                 "Wheat Pasta","Cow's Milk Cheese","Butter","Cucumber"});

        foodList.insert("Dinner",{"Cow's Milk","Beef","White Bread","Apple","Carrots Juice","Checken","Goat's Milk","Cucumber","Eggs",
                                  "Brown Rice","Beans","Cup of Tea","Evo Oil","Almonds","Potatoes","Corn","Brown Bread","Calamari",
                                  "Opnion Brinjals","Black Olives","Honey","Feta fat free cheese","Cacao Nibs","Walnuts","Milk low fat"});

         high=14;

         randomValue = int(qrand() % ((high + 1) - low) + low) ;
         qDebug()<<QString(randomValue);

          ui->label_table_Dsun_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dmon_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dtue_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dwen_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dthur_3->setText(foodList["Breakfast"][randomValue]+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dfri_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dsat_3->setText(foodList["Breakfast"][randomValue]+" "+foodList["Breakfast"][randomValue+1]);


          //lunch


          high =23; low =0;

          randomValue = int(qrand() % ((high + 1) - low) + low) ;
          qDebug()<<QString(randomValue);
          ui->label_table_Dsun_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dmon_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dtue_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dwen_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dthur_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dfri_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dsat_2->setText(foodList["Lunch"][randomValue]+" "+foodList["Lunch"][randomValue+1]+" "+foodList["Lunch"][randomValue+2]);


          //Dinner

          high =22; low =0;

         randomValue =  qrand() % ((high + 1) - low) + low;
         qDebug()<<QString(randomValue);


          ui->label_table_Dsun->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);

          randomValue = int(qrand() % ((high + 1) - low) + low) ;;

          ui->label_table_Dmon->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dtue->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dwen->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);

          randomValue =  qrand() % ((high + 1) - low) + low;

          ui->label_table_Dthur->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);

                randomValue =  qrand() % ((high + 1) - low) + low;
          ui->label_table_Dfri->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);
            randomValue =  qrand() % ((high + 1) - low) + low;
          ui->label_table_Dsat->setText(foodList["Dinner"][randomValue]+" "+foodList["Dinner"][randomValue+1]+" "+foodList["Dinner"][randomValue+2]);



    }







}

