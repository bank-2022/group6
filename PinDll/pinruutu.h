#ifndef PINRUUTU_H
#define PINRUUTU_H

#include <QDialog>

namespace Ui {
class pinruutu;
}

class pinruutu : public QDialog
{
    Q_OBJECT

public:
    explicit pinruutu(QWidget *parent = nullptr);
    ~pinruutu();

private:
    Ui::pinruutu *ui;
};

#endif // PINRUUTU_H
