#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pinikkuna.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Ppinikkuna = new pinikkuna;
    pRFID_DLL = new RFID_DLL;
    QObject::connect(this, SIGNAL(nappipainettu()),
                     this, SLOT(lahetaeteenpain()));
    QObject::connect(this, SIGNAL(RFID_signaalitakaisin()),
                     this, SLOT(signaalitakaisin()));

    QObject::connect(this, SIGNAL(sulje_1()),
    Ppinikkuna, SLOT(aloitatimer()), Qt::QueuedConnection);

    QObject::connect(Ppinikkuna, SIGNAL(sulje_2()),
    Ppinikkuna, SLOT(aloitatimer()), Qt::QueuedConnection);

    QObject::connect(this, SIGNAL(pinIkkuna()),
                     this, SLOT(avaaPIN()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Ppinikkuna;
    delete pRFID_DLL;
}

void MainWindow::on_avaa_clicked()
{
    qDebug() << "Nappia painettu";
    emit nappipainettu();

}

void MainWindow::avaaPIN()
{
    this->close();
    Ppinikkuna->show();
    emit sulje_1();
}

void MainWindow::lahetaeteenpain()
{
    qDebug() << "Lähti eteenpäin";
    pRFID_DLL->readData();
    emit RFID_signaalitakaisin();
}

void MainWindow::signaalitakaisin()
{
    qDebug() << "Data tuli exeen";
    pRFID_DLL->data();
    emit pinIkkuna();
}

