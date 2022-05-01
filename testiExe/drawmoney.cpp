#include "drawmoney.h"
#include "ui_drawmoney.h"


drawmoney::drawmoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::drawmoney)
{
    ui->setupUi(this);

    pREST_APIDLL = new REST_APIDLL;
    timer = new QTimer();

    pREST_APIDLL->tiliTiedot();

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
    summa=0;
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
    qDebug()<< "Summa" <<summa;

    if(summa==0){
        qDebug()<<"ei summaa valittu";
    }
    else{

        Stringsaldo = pREST_APIDLL->getSaldo();
        qDebug()<<"Saldo"<<Stringsaldo;
        saldo = Stringsaldo.toInt();
            if(saldo<summa){
                ui->lineEdit->setText("Not enough balance");
            }
            else{

                tulos=saldo-summa;
                int tulos3 = tulos;
                qDebug()<<"Uusi Saldo"<<tulos;

                tulos2 = QString::number(tulos3);
                pREST_APIDLL->updatetili(tulos);
                pREST_APIDLL->addtilitapahtumat(summa);

            }
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

const QString &drawmoney::getTulos2() const
{
    return tulos2;
}
