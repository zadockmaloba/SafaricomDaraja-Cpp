#ifndef ACCESSEQUENCE_H
#define ACCESSEQUENCE_H

/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>

namespace  DarajaCpp{
class AccesSequence : public QObject
{
    Q_OBJECT
public:
    AccesSequence(QString consumerKey, QString consumerSecret);

    const QString &consumerSecret() const;
    void setConsumerSecret(const QString &newConsumerSecret);

    const QString &consumerKey() const;
    void setConsumerKey(const QString &newConsumerKey);

    const QNetworkRequest &httpRequest() const;

public slots:
    void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void onEncrypted(QNetworkReply *reply);
    void onFinished(QNetworkReply *reply);
    void onPreSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void onProxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void onSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:
    QNetworkAccessManager m_httpHandler;
    QNetworkRequest m_httpRequest;
    QString m_consumerKey, m_consumerSecret;
    QUrl m_authUrl;
};
}

#endif // ACCESSEQUENCE_H
