#include "smsservice.h"
#include <QDebug>
#include <QTimer>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>  // Added this include
#include <QUrlQuery>
#include <QByteArray>     // Added this include

SmsService::SmsService(QObject *parent) : QObject(parent) {}

bool SmsService::sendSms(const QString &phoneNumber, const QString &message)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QString accountSid = "AC699af13b9066a40b6866bf04680ceba3";
    QString authToken = "150e23b97f019abfc1d91492ad5b70cd";
    QString twilioNumber = "+15076877337";
    // Temporarily add this debug output
    qDebug() << "Attempting to send SMS to:" << phoneNumber;
    qDebug() << "Using Account SID:" << accountSid.left(5) + "..."; // Show first 5 chars only
    qDebug() << "Twilio Number:" << twilioNumber;

    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/AC699af13b9066a40b6866bf04680ceba3/Messages.json").arg(accountSid));

    QUrlQuery params;
    params.addQueryItem("To", phoneNumber);
    params.addQueryItem("From", twilioNumber);
    params.addQueryItem("Body", message);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Fixed the authorization header
    QByteArray auth = QString("%1:%2").arg(accountSid).arg(authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth);

    QNetworkReply *reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

    connect(reply, &QNetworkReply::finished, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            qDebug() << "Twilio Response:" << reply->readAll();
            emit smsSentSuccessfully(phoneNumber);
        } else {
            qDebug() << "SMS Error:" << reply->errorString();
            qDebug() << "Detailed Error:" << reply->readAll();
            emit smsFailed(phoneNumber, reply->errorString());
        }
        reply->deleteLater();
        manager->deleteLater();
    });

    return true;
}



