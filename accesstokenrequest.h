/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#ifndef ACCESSTOKENREQUEST_H
#define ACCESSTOKENREQUEST_H

#include <QObject>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

namespace  DarajaCpp{
class AccessTokenRequest : public QObject
{
    Q_OBJECT
public:
    AccessTokenRequest(QString consumerKey, QString consumerSecret);

    const QString &consumerSecret() const;
    void setConsumerSecret(const QString &newConsumerSecret);

    const QString &consumerKey() const;
    void setConsumerKey(const QString &newConsumerKey);

    const QNetworkRequest &httpRequest() const;

private:
    QNetworkRequest m_httpRequest;
    QString m_consumerKey, m_consumerSecret, m_accessTokenString;
    QUrl m_authUrl;
    bool m_succeeded;
};
}

#endif // ACCESSTOKENREQUEST_H
