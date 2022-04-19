#include "pindll.h"

PinDll::PinDll()
{
    qDebug()<<"PinDll luotu";
    objectDialog= new Dialog;
    objectDialog->exec();
}

PinDll::~PinDll()
{
    qDebug()<<"PinDll tuhottu";
}

void PinDll::getpin()
{
    //hae pin restapi dllstä
}

short PinDll::pincompare(QString givenpin)
{

}
