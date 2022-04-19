#ifndef PINIKKUNA_H
#define PINIKKUNA_H

#include <QDialog>
#include <QString>
#include <QDebug>

#include "pindll.h"

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

public slots:
    void aloitatimer();

private slots:
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_6_clicked();
    void on_Button_5_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_send_clicked();
    void on_clear_clicked();

    void suljepinikkuna();

private:
    Ui::pinikkuna *ui;
    PinDll * PinDllClass;
    QTimer *timer;
};

#endif // PINIKKUNA_H
