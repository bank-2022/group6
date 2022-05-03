#include "rfid_dll.h"

RFID_DLL::RFID_DLL()
{
    qDebug() << "DLL luotu";
    serial = new QSerialPort;
    //pRFID_Engine = new RFID_Engine;
    QObject::connect(this, SIGNAL(avaaikkuna()),
                     this, SLOT(engineslot()));

}

RFID_DLL::~RFID_DLL()
{
    qDebug() << "DLL tuhottu";
    //delete pRFID_Engine;
    //pRFID_Engine = nullptr;
    delete serial;
}

void RFID_DLL::readData()
{

    qDebug() << "Data muutetaan";
    serial->setPortName("COM6");
    if(!serial->setBaudRate(QSerialPort::Baud1200))
        qDebug() << serial->errorString();
    if(!serial->setDataBits(QSerialPort::Data7))
        qDebug() << serial->errorString();
    if(!serial->setParity(QSerialPort::EvenParity))
        qDebug() << serial->errorString();
    if(!serial->setFlowControl(QSerialPort::HardwareControl))
        qDebug() << serial->errorString();
    if(!serial->setStopBits(QSerialPort::OneStop))
        qDebug() << serial->errorString();
    if(!serial->open(QIODevice::ReadOnly))
        qDebug() << serial->errorString();
    qDebug() << serial->bytesAvailable();
    for (int i= 0; i<1; i++){
        if(!serial->waitForReadyRead(-1))
            qDebug() << "error: " << serial->errorString();
        else{
            QByteArray datas = serial->readAll();
            qDebug() << datas;
            muutettu = QString(datas);

        }
    }

    emit avaaikkuna();

}

void RFID_DLL::data()
{
    qDebug() << "Kortin ID:" << muutettu;
}



void RFID_DLL::engineslot()
{
    qDebug() << "Muutosikkuna avattu";
    if(muutettu == "\r\n-0600064922\r\n>")
    {
        muutettu = "\r\n-0600064922\r\n>";
        muutettu = muutettu.simplified();
        muutettu.remove(' ');
        muutettu.remove(QRegularExpression("[-]"));
        muutettu.remove(QRegularExpression("[>]"));
        qDebug() << muutettu;
    }
    else
    {
        muutettu = "\r\n-06000DE54E\r\n>";
        muutettu = muutettu.simplified();
        muutettu.remove(' ');
        muutettu.remove(QRegularExpression("[-]"));
        muutettu.remove(QRegularExpression("[>]"));
        qDebug() << muutettu;
    }
    emit idLuettu();

}

const QString &RFID_DLL::getMuutettu() const
{
    return muutettu;
}
