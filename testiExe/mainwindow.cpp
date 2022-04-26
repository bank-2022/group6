#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pinikkuna.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Ppinikkuna = new pinikkuna;

    QObject::connect(this, SIGNAL(sulje_1()),
    Ppinikkuna, SLOT(aloitatimer()), Qt::QueuedConnection);

    QObject::connect(Ppinikkuna, SIGNAL(sulje_2()),
    Ppinikkuna, SLOT(aloitatimer()), Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Ppinikkuna;
    delete pRFID_DLL;
}

void MainWindow::korttilukittu()
{
    ui->label->setText("Given card has been locked");
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
    ui->label->setText("");
    emit sulje_1();
}

