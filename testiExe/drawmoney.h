#ifndef DRAWMONEY_H
#define DRAWMONEY_H

#include <QWidget>

namespace Ui {
class drawmoney;
}

class drawmoney : public QWidget
{
    Q_OBJECT

public:
    explicit drawmoney(QWidget *parent = nullptr);
    ~drawmoney();

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

private:
    Ui::drawmoney *ui;
};

#endif // DRAWMONEY_H
