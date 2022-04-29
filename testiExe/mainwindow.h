#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include "pindll.h"
#include "pinikkuna.h"
#include "rfid_dll.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:
    void sulje_1();
    void nappipainettu();
    void RFID_signaalitakaisin();
    void pinIkkuna();

public slots:
    void korttilukittu();

private slots:
    void on_avaa_clicked();
    void avaaPIN();
    void lahetaeteenpain();
    void signaalitakaisin();

    void on_toinennappi_clicked();

private:
    Ui::MainWindow *ui;
    PinDll * PinDllClass;
    pinikkuna *Ppinikkuna;
    BankMain *Pbankmain;
    RFID_DLL *pRFID_DLL;
    QString muutettu;


};
#endif // MAINWINDOW_H
