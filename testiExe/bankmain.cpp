#include "bankmain.h"
#include "ui_bankmain.h"


BankMain::BankMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankMain)
{
    ui->setupUi(this);

    timer = new QTimer();
    pREST_APIDLL = new REST_APIDLL;
    pDrawMoney = new drawmoney;

    pREST_APIDLL->tiedot();
    pREST_APIDLL->tiliTiedot();
    pREST_APIDLL->tiliTapahtumat();
    connect(pREST_APIDLL, SIGNAL(pois()),
            this, SLOT(RestApistaPois()));
    connect(pREST_APIDLL, SIGNAL(pois2()),
            this, SLOT(RestApistaPois2()));
    connect(pREST_APIDLL, SIGNAL(pois3()),
            this, SLOT(RestApistaPois3()));
    connect(this->timer,SIGNAL(timeout()),
                this,SLOT(suljemainikkuna()));

    connect(this, SIGNAL(sulje_4()),
    this, SLOT(aloitatimer30()));
    connect(this, SIGNAL(sulje_5()),
    pDrawMoney, SLOT(aloitatimer10_2()));


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
    pDrawMoney->show();
    emit sulje_5();
}


void BankMain::on_close_clicked()
{
    this->close();
}


void BankMain::on_pushButton_clicked()
{
    emit sulje_4();
}

void BankMain::RestApistaPois()
{
    qDebug() << "Asiakas" << pREST_APIDLL->getAsiakas();
    ui->accountOwner->setText(pREST_APIDLL->getAsiakas());
}

void BankMain::RestApistaPois2()
{
    qDebug() << "Saldo" << pREST_APIDLL->getSaldo();
    ui->balance->setText(pREST_APIDLL->getSaldo());
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

void BankMain::RestApistaPois3()
{
    qDebug() << "Tilitapahtumat" << pREST_APIDLL->gettilitapahtumat();
    ui->lineEdit->setText(pREST_APIDLL->gettilitapahtumat());
}

