#include "rest_apidll.h"

REST_APIDLL::REST_APIDLL()
{

}

REST_APIDLL::~REST_APIDLL()
{

}

void REST_APIDLL::tiedot()
{
    QString base_url="http://localhost:3000/Asiakas";
    QNetworkRequest request((base_url));
    getManager = new QNetworkAccessManager;

    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getAsiakas(QNetworkReply*)));

    reply = getManager->get(request);
    qDebug() << "REST APISSA";
}

void REST_APIDLL::tiliTiedot()
{
    QString base_url="http://localhost:3000/tili";
    QNetworkRequest request((base_url));
    getManager = new QNetworkAccessManager;

    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getTili(QNetworkReply*)));

    reply = getManager->get(request);
    qDebug() << "REST APISSA";
}


void REST_APIDLL::getAsiakas(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       asiakas+=QString(json_obj["Nimi"].toString());
    }
    reply->deleteLater();
    getManager->deleteLater();
    emit pois();
}

void REST_APIDLL::getTili(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       saldo+=QString::number(json_obj["Saldo"].toInt());
    }
    reply->deleteLater();
    getManager->deleteLater();
    emit pois2();
}

const QString &REST_APIDLL::getSaldo() const
{
    return saldo;
}

const QString &REST_APIDLL::getAsiakas() const
{
    return asiakas;
}
