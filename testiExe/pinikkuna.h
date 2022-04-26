#ifndef PINIKKUNA_H
#define PINIKKUNA_H

#include <QDialog>
#include <QString>
#include <QDebug>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "pindll.h"
#include "bankmain.h"
#include "myurl.h"


namespace Ui {
class pinikkuna;
}

class pinikkuna : public QDialog
{
    Q_OBJECT

public:
    explicit pinikkuna(QWidget *parent = nullptr);
    ~pinikkuna();


signals:
    void sulje_2();
    void lukitse();

public slots:
    void aloitatimer();
    void pinslot(QNetworkReply *reply);

private slots:
    void suljepinikkuna();

    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_6_clicked();
    void on_Button_5_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_clear_clicked();
    void on_laheta_clicked();

private:
    QString annettupin;
    QString annettukorttinnumero;

    int attempts=3;
    void tarkistaAttempts();
    void lukitsekortti();
    QString lukittukortinnumero;


    Ui::pinikkuna *ui;
    PinDll * PinDllClass;
    QTimer *timer;
    BankMain *PBankMain;

    MyUrl *PMyUrl;
    QString base_url;
    QString id;
    QNetworkAccessManager *loginmanager;
    QNetworkReply *reply;
    QByteArray response_data;


};

#endif // PINIKKUNA_H
