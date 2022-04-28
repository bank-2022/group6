#include "drawmoney.h"
#include "ui_drawmoney.h"


drawmoney::drawmoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);

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
}


void drawmoney::on_CloseButton_clicked()
{
    this->close();
}


void drawmoney::on_kaksikymmenta_clicked()
{
    emit sulje_6();
}


void drawmoney::on_neljakymmenta_clicked()
{
    emit sulje_6();
}


void drawmoney::on_viisikymmenta_clicked()
{
    emit sulje_6();
}


void drawmoney::on_kuusikymmenta_clicked()
{
    emit sulje_6();
}


void drawmoney::on_sata_clicked()
{
    emit sulje_6();
}


void drawmoney::on_kaksisataa_clicked()
{
    emit sulje_6();
}


void drawmoney::on_viisisataa_clicked()
{
    emit sulje_6();
}


void drawmoney::on_drawbutton_clicked()
{
    emit sulje_6();
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
