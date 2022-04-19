#ifndef PINDLL_H
#define PINDLL_H

#include "PinDll_global.h"
#include "dialog.h"
#include <QDebug>
#include <QString>


class PINDLL_EXPORT PinDll
{
public:
    PinDll();
    ~PinDll();
    void getpin();
    short pincompare(QString givenpin);
private:
    Dialog *objectDialog;
};

#endif // PINDLL_H
