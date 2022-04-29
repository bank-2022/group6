#ifndef REST_APIDLL_H
#define REST_APIDLL_H
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "REST_APIDLL_global.h"
#include <QObject>

class REST_APIDLL_EXPORT REST_APIDLL : public QObject
{
    Q_OBJECT

public:
    REST_APIDLL();
    ~REST_APIDLL();
    void tiedot();
    void tiliTiedot();
    void tiliTapahtumat();

    const QString &getAsiakas() const;
    const QString &getSaldo() const;
    const QString &gettilitapahtumat() const;

signals:
    void pois();
    void pois2();
    void pois3();

private slots:
    void getAsiakas(QNetworkReply *reply);
    void getTili(QNetworkReply *reply);
    void getTiliTapahtumat(QNetworkReply *reply);

private:
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString asiakas;
    QString saldo;
    QString tilitapahtumat;
};

#endif // REST_APIDLL_H
