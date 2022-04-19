#include "pinikkuna.h"
#include "ui_pinikkuna.h"
#include "mainwindow.h"

pinikkuna::pinikkuna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinikkuna)
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(this->timer,SIGNAL(timeout()),
                this,SLOT(suljepinikkuna()));
}

pinikkuna::~pinikkuna()
{
    delete ui;
    delete timer;
    timer = nullptr;
}



void pinikkuna::on_Button_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "1");
    emit sulje_2();
}
void pinikkuna::on_Button_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "2");
    emit sulje_2();
}
void pinikkuna::on_Button_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "3");
    emit sulje_2();
}
void pinikkuna::on_Button_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "4");
    emit sulje_2();
}
void pinikkuna::on_Button_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "5");
    emit sulje_2();
}
void pinikkuna::on_Button_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "6");
    emit sulje_2();
}
void pinikkuna::on_Button_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "7");
    emit sulje_2();
}
void pinikkuna::on_Button_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "8");
    emit sulje_2();
}
void pinikkuna::on_Button_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ "9");
    emit sulje_2();
}



void pinikkuna::on_send_clicked()
{
   QString givenpin = ui->lineEdit->text();
   PinDllClass->pincompare(givenpin);
}
void pinikkuna::on_clear_clicked()
{
    ui->lineEdit->setText("");
    emit sulje_2();
}



void pinikkuna::aloitatimer()
{
    timer->start(10000);
    qDebug()<<"timer aloitettu";
}

void pinikkuna::suljepinikkuna()
{
    ui->lineEdit->setText("");
    this->close();
}

