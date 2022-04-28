#include "drawmoney.h"
#include "ui_drawmoney.h"

drawmoney::drawmoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);
}

drawmoney::~drawmoney()
{
    delete ui;
}

void drawmoney::on_CloseButton_clicked()
{
    this->close();
}


void drawmoney::on_kaksikymmenta_clicked()
{

}


void drawmoney::on_neljakymmenta_clicked()
{

}


void drawmoney::on_viisikymmenta_clicked()
{

}


void drawmoney::on_kuusikymmenta_clicked()
{

}


void drawmoney::on_sata_clicked()
{

}


void drawmoney::on_kaksisataa_clicked()
{

}


void drawmoney::on_viisisataa_clicked()
{

}


void drawmoney::on_drawbutton_clicked()
{

}

