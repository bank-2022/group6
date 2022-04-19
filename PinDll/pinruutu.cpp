#include "pinruutu.h"
#include "ui_pinruutu.h"

pinruutu::pinruutu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinruutu)
{
    ui->setupUi(this);
}

pinruutu::~pinruutu()
{
    delete ui;
}
