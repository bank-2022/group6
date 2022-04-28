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

    const QString &getAsiakas() const;

private slots:
    void getAsiakas(QNetworkReply *reply);

private:
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString asiakas;
};

#endif // REST_APIDLL_H
