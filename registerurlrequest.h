#ifndef REGISTERURLREQUEST_H
#define REGISTERURLREQUEST_H

#include <QObject>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>
#include "networkhandler.h"

namespace DarajaCpp {
class RegisterUrlRequest : public QObject
{
    Q_OBJECT
public:
    RegisterUrlRequest();
    explicit RegisterUrlRequest(QString accessToken);
    RegisterUrlRequest(QString accessToken, QString hostAddr, QString hostPort);
    QNetworkRequest *renderRequest(NetworkHandler* netH);

    const QNetworkRequest &httpRequest() const;
    const QUrl &authUrl() const;
    void setAuthUrl(const QUrl &newAuthUrl);
    const QString &accessToken() const;
    void setAccessToken(const QString &newAccessToken);
    const QString &hostAddr() const;
    void setHostAddr(const QString &newHostAddr);
    const QString &getHostPort() const;
    void setHostPort(const QString &newHostPort);

    const QMap<QString, QString> &requestBody() const;
    void setRequestBody(const QMap<QString, QString> &newRequestBody);

private:
    QNetworkRequest m_httpRequest;
    QUrl m_authUrl;
    QString m_accessToken, m_hostAddr, m_hostPort;
    QMap <QString, QString> m_requestBody;
};
}

#endif // REGISTERURLREQUEST_H
