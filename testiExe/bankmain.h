#ifndef BANKMAIN_H
#define BANKMAIN_H

#include <QDialog>


namespace Ui {
class BankMain;
}

class BankMain : public QDialog
{
    Q_OBJECT

public:
    explicit BankMain(QWidget *parent = nullptr);
    ~BankMain();

private slots:
    void on_actions_clicked();
    void on_previous_clicked();
    void on_nextactions_clicked();
    void on_money_clicked();
    void on_close_clicked();
    void on_pushButton_clicked();

private:
    Ui::BankMain *ui;
};

#endif // BANKMAIN_H
