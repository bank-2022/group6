#ifndef RFID_DLL_H
#define RFID_DLL_H
#include <QCoreApplication>
#include <QDebug>
#include "rfid_engine.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QWidget>
#include <QRegularExpression>

#include "RFID_DLL_global.h"

class RFID_DLL_EXPORT RFID_DLL : public QObject
{
    Q_OBJECT
public:
    RFID_DLL();
    ~RFID_DLL();
    void readData();
    void data();


    const QString &getMuutettu() const;

signals:
    void avaaikkuna();
    void idLuettu();

public slots:
    void engineslot();
    //QString simplified() const;


private:
    //RFID_Engine *pRFID_Engine;
    QSerialPort *serial;
    QByteArray datas;
    QString muutettu;
    QString str;

};

#endif // RFID_DLL_H
