#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "pindll.h"
#include "pinikkuna.h"

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

private slots:
    void on_avaa_clicked();

private:
    Ui::MainWindow *ui;
    PinDll * PinDllClass;
    pinikkuna *Ppinikkuna;

};
#endif // MAINWINDOW_H
