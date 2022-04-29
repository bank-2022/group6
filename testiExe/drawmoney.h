#ifndef DRAWMONEY_H
#define DRAWMONEY_H
//#include "bankmain.h"

#include "rest_apidll.h"

#include <QWidget>
#include <QDebug>
#include <QTimer>


namespace Ui {
class drawmoney;
}

class drawmoney : public QWidget
{
    Q_OBJECT

public:
    explicit drawmoney(QWidget *parent = nullptr);
    ~drawmoney();

signals:
    void sulje_6();
public slots:
    void aloitatimer10_2();

private slots:
    void on_CloseButton_clicked();
    void on_kaksikymmenta_clicked();
    void on_neljakymmenta_clicked();
    void on_viisikymmenta_clicked();
    void on_kuusikymmenta_clicked();
    void on_sata_clicked();
    void on_kaksisataa_clicked();
    void on_viisisataa_clicked();
    void on_drawbutton_clicked();

    void suljedrawikkuna();

private:
    int summa=0;
    QString tapahtuma="Nosto";

    Ui::drawmoney *ui;
    QTimer *timer;
    REST_APIDLL *pREST_APIDLL;

};

#endif // DRAWMONEY_H
