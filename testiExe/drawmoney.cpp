#include "drawmoney.h"
#include "ui_drawmoney.h"


drawmoney::drawmoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);

    pREST_APIDLL = new REST_APIDLL;
    timer = new QTimer();
    connect(this->timer,SIGNAL(timeout()),
                this,SLOT(suljedrawikkuna()));

    connect(this, SIGNAL(sulje_6()),
    this, SLOT(aloitatimer10_2()));

}

drawmoney::~drawmoney()
{
    delete ui;
    delete timer;
    delete pREST_APIDLL;
}


void drawmoney::on_CloseButton_clicked()
{
    this->close();
}


void drawmoney::on_kaksikymmenta_clicked()
{
    emit sulje_6();
    summa=20;
    ui->lineEdit->setText("Draw 20");
}


void drawmoney::on_neljakymmenta_clicked()
{
    emit sulje_6();
    summa=40;
    ui->lineEdit->setText("Draw 40");
}


void drawmoney::on_viisikymmenta_clicked()
{
    emit sulje_6();
    summa=50;
    ui->lineEdit->setText("Draw 50");
}


void drawmoney::on_kuusikymmenta_clicked()
{
    emit sulje_6();
    summa=60;
    ui->lineEdit->setText("Draw 60");
}


void drawmoney::on_sata_clicked()
{
    emit sulje_6();
    summa=100;
    ui->lineEdit->setText("Draw 100");
}


void drawmoney::on_kaksisataa_clicked()
{
    emit sulje_6();
    summa=200;
    ui->lineEdit->setText("Draw 200");
}


void drawmoney::on_viisisataa_clicked()
{
    emit sulje_6();
    summa=500;
    ui->lineEdit->setText("Draw 500");
}


void drawmoney::on_drawbutton_clicked()
{
    emit sulje_6();
    qDebug()<<summa;

    if(summa==0){
        qDebug()<<"ei summaa valittu";
    }
    else{
        pREST_APIDLL->addtilitapahtumat(summa);
    }
}




void drawmoney::aloitatimer10_2()
{
    timer->start(10000);
    qDebug()<<"10s timer aloitettu_2";
}
void drawmoney::suljedrawikkuna()
{
    this->close();
}
