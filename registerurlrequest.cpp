#include "registerurlrequest.h"

namespace DarajaCpp {
RegisterUrlRequest::RegisterUrlRequest()
    :m_authUrl("https://sandbox.safaricom.co.ke/mpesa/c2b/v1/registerurl")
{
    this->m_httpRequest.setUrl(this->m_authUrl);
    //TODO: implement
}

RegisterUrlRequest::RegisterUrlRequest(QString accessToken) //Recommended: Use this constructor
    : m_authUrl("https://sandbox.safaricom.co.ke/mpesa/c2b/v1/registerurl"),
      m_accessToken(accessToken)
{
    this->m_httpRequest.setUrl(this->m_authUrl);
    //TODO: implement
}

RegisterUrlRequest::RegisterUrlRequest(QString accessToken, QString hostAddr, QString hostPort)
    : m_authUrl("https://sandbox.safaricom.co.ke/mpesa/c2b/v1/registerurl"),
      m_accessToken(accessToken),
      m_hostAddr(hostAddr),
      m_hostPort(hostPort)
{
    this->m_httpRequest.setUrl(this->m_authUrl);
    //TODO: implement
}

QNetworkRequest *RegisterUrlRequest::renderRequest(NetworkHandler* netH)
{
    QJsonObject jsObject;
    for( const auto &v : m_requestBody.keys()) jsObject.insert(v, QJsonValue(m_requestBody[v]));
    auto const jsByte = QJsonDocument(jsObject).toJson();
    qDebug() << jsByte;

    this->m_httpRequest.setRawHeader("Authorization",QByteArray("Bearer ").append(m_accessToken.toUtf8()));
    this->m_httpRequest.setRawHeader("Content-Type", "application/json");
    this->m_httpRequest.setRawHeader("Content-Length", QString::number(jsByte.size()).toUtf8());

    netH->post(&m_httpRequest, jsByte);
    return &m_httpRequest;
}

const QNetworkRequest &RegisterUrlRequest::httpRequest() const{ return m_httpRequest; }

const QUrl &RegisterUrlRequest::authUrl() const{ return m_authUrl; }

void RegisterUrlRequest::setAuthUrl(const QUrl &newAuthUrl){ m_authUrl = newAuthUrl; }

const QString &RegisterUrlRequest::accessToken() const{ return m_accessToken; }

void RegisterUrlRequest::setAccessToken(const QString &newAccessToken){ m_accessToken = newAccessToken; }

const QString &RegisterUrlRequest::hostAddr() const{ return m_hostAddr; }

void RegisterUrlRequest::setHostAddr(const QString &newHostAddr){ m_hostAddr = newHostAddr; }

const QString &RegisterUrlRequest::getHostPort() const{ return m_hostPort; }

void RegisterUrlRequest::setHostPort(const QString &newHostPort){ m_hostPort = newHostPort; }

const QMap<QString, QString> &RegisterUrlRequest::requestBody() const{ return m_requestBody; }

void RegisterUrlRequest::setRequestBody(const QMap<QString, QString> &newRequestBody){ m_requestBody = newRequestBody; }

}
