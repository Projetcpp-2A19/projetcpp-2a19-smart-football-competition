#ifndef SMSSERVICE_H
#define SMSSERVICE_H

#include <QObject>
#include <QString>

class SmsService : public QObject
{
    Q_OBJECT

public:
    explicit SmsService(QObject *parent = nullptr);

    bool sendSms(const QString &phoneNumber, const QString &message);

    // Optional: Add signals for status updates
signals:
    void smsSentSuccessfully(const QString &phoneNumber);
    void smsFailed(const QString &phoneNumber, const QString &error);
};

#endif // SMSSERVICE_H
