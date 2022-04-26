#include "pinikkuna.h"
#include "ui_pinikkuna.h"
#include "mainwindow.h"
#include "bankmain.h"

pinikkuna::pinikkuna(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinikkuna)
{
    ui->setupUi(this);
    PMyUrl = new MyUrl;

    base_url = PMyUrl->getBase_url();

    timer = new QTimer();
    connect(this->timer,SIGNAL(timeout()),
                this,SLOT(suljepinikkuna()));
}

pinikkuna::~pinikkuna()
{
    delete ui;
    delete timer;
    delete PBankMain;
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



void pinikkuna::aloitatimer()
{
    timer->start(10000);
    qDebug()<<"timer aloitettu";
}

void pinikkuna::suljepinikkuna()
{
    ui->lineEdit->setText("");
    ui->label->setText("");
    this->close();
}



void pinikkuna::on_clear_clicked()
{
    ui->lineEdit->setText("");
    ui->label->setText("");
    emit sulje_2();
}
void pinikkuna::on_laheta_clicked()
{
    //qDebug()<<"base_url="+base_url;

    annettupin = ui->lineEdit->text();
    annettukorttinnumero = "0600064922";

    QJsonObject jsonObj;
    jsonObj.insert("Kortinnumero",annettukorttinnumero);
    jsonObj.insert("Pin",annettupin);


    QNetworkRequest request((base_url+"/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginmanager = new QNetworkAccessManager(this);
    connect(loginmanager, SIGNAL(finished (QNetworkReply*)), this, SLOT(pinslot(QNetworkReply*)));

    reply = loginmanager->post(request, QJsonDocument(jsonObj).toJson());


}



void pinikkuna::pinslot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;

    if (response_data!="false"){
            if(lukittukortinnumero == annettukorttinnumero){
                ui->label->setText("This card is allready locked");
            }
            else{
                PBankMain = new BankMain;
                ui->lineEdit->setText("");
                ui->label->setText("");
                this->close();
                PBankMain->show();
            }
    }
    else {

            ui->lineEdit->setText("");
            ui->label->setText("Incorrect pin");
            attempts=attempts-1;
            tarkistaAttempts();
    }
}

void pinikkuna::tarkistaAttempts()
{
    qDebug()<<attempts;
    if(attempts==0){
        lukitsekortti();
        attempts=3;
    }
}

void pinikkuna::lukitsekortti()
{
    lukittukortinnumero = annettukorttinnumero;
    emit lukitse();
    this->close();
}
