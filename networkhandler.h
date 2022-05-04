/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#define _NETWORK_HANDLER_MSG_(x) qInfo() <<"[NETWORK_HANDLER]: "<< x

#include <QThread>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>

namespace DarajaCpp{
class NetworkHandler : public QThread
{
    Q_OBJECT
public:
    NetworkHandler();
    const QNetworkAccessManager &httpHandler() const;
    const QNetworkRequest &httpRequest() const;

public: //methods
    void get(const QNetworkRequest* request);
    void post(const QNetworkRequest* request, const QByteArray &data);

private slots://NetworkReply
    void onReadyRead();

private slots:// NetworkManager
    void onAuthenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void onEncrypted(QNetworkReply *reply);
    void onFinished(QNetworkReply *reply);
    void onPreSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void onProxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void onSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:
    QNetworkAccessManager m_httpHandler;
    QNetworkRequest m_httpRequest;
};
}
#endif // NETWORKHANDLER_H
