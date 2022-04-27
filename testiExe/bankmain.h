#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QDialog>
#include <QDebug>
#include <QTimer>


namespace Ui {
class BankMain;
}

class BankMain : public QDialog
{
    Q_OBJECT

public:
    explicit BankMain(QWidget *parent = nullptr);
    ~BankMain();

signals:
    void sulje_4();

public slots:
    void aloitatimer30();

private slots:
    void on_actions_clicked();
    void on_previous_clicked();
    void on_nextactions_clicked();
    void on_money_clicked();
    void on_close_clicked();
    void on_pushButton_clicked();

    void suljemainikkuna();

private:
    Ui::BankMain *ui;
    QTimer *timer;
};

#endif // BANKMAIN_H
