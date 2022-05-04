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

void REST_APIDLL::tiliTapahtumat()
{
    QString base_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((base_url));
    getManager = new QNetworkAccessManager;

    connect(getManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(getTiliTapahtumat(QNetworkReply*)));

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



void REST_APIDLL::getTiliTapahtumat(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       tilitapahtumat+=QString::number(json_obj["Summa"].toInt())+", "+json_obj["Tapahtuma"].toString()+"\n";
    }
    reply->deleteLater();
    getManager->deleteLater();
    emit pois3();
}



void REST_APIDLL::addtilitapahtumat(int summa)
{
    StringTapahtuma="Draw";
    StringSumma=QString::number(summa);

    QJsonObject jsonObj;
    jsonObj.insert("Tapahtuma",StringTapahtuma);
    jsonObj.insert("Summa",StringSumma);


    QString base_url="http://localhost:3000/tilitapahtumat";
    QNetworkRequest request((base_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager;
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addTiliTapahtumat(QNetworkReply*)));


    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}
void REST_APIDLL::addTiliTapahtumat(QNetworkReply *reply)
{
    response_data=reply->readAll();
        qDebug()<<response_data;
        reply->deleteLater();
        postManager->deleteLater();
}



void REST_APIDLL::updatetili(int tulos)
{
    QString Tilinumero = "FI123123";

    QJsonObject jsonObj;
    jsonObj.insert("Tilinumero",Tilinumero);
    jsonObj.insert("Saldo",tulos);

    QString base_url="http://localhost:3000/tili/1";
    QNetworkRequest request((base_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateTiliSlot(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
}
void REST_APIDLL::updateTiliSlot(QNetworkReply *reply)
{
        response_data=reply->readAll();
        qDebug()<<response_data;
        reply->deleteLater();
        putManager->deleteLater();
}



const QString &REST_APIDLL::getSaldo() const
{
    return saldo;
}

const QString &REST_APIDLL::gettilitapahtumat() const
{
    return tilitapahtumat;
}

const QString &REST_APIDLL::getAsiakas() const
{
    return asiakas;
}
