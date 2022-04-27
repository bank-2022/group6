#include "bankmain.h"
#include "ui_bankmain.h"


BankMain::BankMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankMain)
{
    ui->setupUi(this);

    timer = new QTimer();


    connect(this->timer,SIGNAL(timeout()),
                this,SLOT(suljemainikkuna()));
    QObject::connect(this, SIGNAL(sulje_4()),
    this, SLOT(aloitatimer30()));
}

BankMain::~BankMain()
{
    delete ui;

}


void BankMain::on_actions_clicked()
{
    emit sulje_4();
}


void BankMain::on_previous_clicked()
{
    emit sulje_4();
}


void BankMain::on_nextactions_clicked()
{
    emit sulje_4();
}




void BankMain::on_money_clicked()
{

}


void BankMain::on_close_clicked()
{

    this->close();
}


void BankMain::on_pushButton_clicked()
{
    emit sulje_4();
}


void BankMain::aloitatimer30()
{
    timer->start(30000);
    qDebug()<<"30s timer aloitettu";
}
void BankMain::suljemainikkuna()
{
     this->close();
}

