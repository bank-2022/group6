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
    connect(pREST_APIDLL, SIGNAL(pois()),
            this, SLOT(RestApistaPois()));
    connect(pREST_APIDLL, SIGNAL(pois2()),
            this, SLOT(RestApistaPois2()));
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
    pDrawMoney->show();
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

