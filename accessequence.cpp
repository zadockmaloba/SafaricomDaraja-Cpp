#include "accessequence.h"

/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

namespace DarajaCpp {
AccesSequence::AccesSequence(QString consumerKey, QString consumerSecret)
    : m_consumerKey(consumerKey),
      m_consumerSecret(consumerSecret),
      m_authUrl("https://sandbox.safaricom.co.ke/oauth/v1/generate?grant_type=client_credentials")
{
    this->m_httpRequest.setUrl(this->m_authUrl);
    //this->m_httpRequest.setTransferTimeout();
    this->m_httpRequest.setRawHeader("Content-Type", "application/json; charset=utf8");
    this->m_httpRequest.setRawHeader("Authorization","Basic QXpzMktlalUxQVJ2SUw1SmRKc0FSYlYyZ0RyV21wT0I6aGlwR3ZGSmJPeHJpMzMwYw==");
    this->m_httpRequest.setRawHeader("Cookie",
                                     "incap_ses_1024_2742146=ukhlWrBitErUp67HLPs1Du4WcWIAAAAAxaCfuY88C1+UAaE98pBonA==; "
                                     "visid_incap_2742146=EPpdLH1HRTCGDXJgry4FTsRAUGIAAAAAQUIPAAAAAAB6fJ+waBY2//+5ypBHW7PQ");

    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::finished, this, &AccesSequence::onFinished);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::authenticationRequired, this, &AccesSequence::onAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::encrypted, this, &AccesSequence::onEncrypted);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &AccesSequence::onPreSharedKeyAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::proxyAuthenticationRequired, this, &AccesSequence::onProxyAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::sslErrors, this, &AccesSequence::onSslErrors);

    m_httpHandler.get(m_httpRequest);
}

const QString &AccesSequence::consumerSecret() const {return m_consumerSecret;}

void AccesSequence::setConsumerSecret(const QString &newConsumerSecret)
{ m_consumerSecret = newConsumerSecret; }

const QString &AccesSequence::consumerKey() const
{ return m_consumerKey; }

void AccesSequence::setConsumerKey(const QString &newConsumerKey)
{ m_consumerKey = newConsumerKey; }

const QNetworkRequest &AccesSequence::httpRequest() const {return m_httpRequest;}

void AccesSequence::onAuthenticationRequired([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]QAuthenticator *authenticator)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"AUTHENTICATION REQUIRED";
}

void AccesSequence::onEncrypted([[maybe_unused]]QNetworkReply *reply)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"Data is encrypted";
}

void AccesSequence::onFinished(QNetworkReply *reply)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"Request finished";
    qDebug() << "[RESPONSE]: "<< reply->readAll();
}

void AccesSequence::onPreSharedKeyAuthenticationRequired([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]QSslPreSharedKeyAuthenticator *authenticator)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"PreShared Key Authentication required";
}

void AccesSequence::onProxyAuthenticationRequired([[maybe_unused]]const QNetworkProxy &proxy, [[maybe_unused]]QAuthenticator *authenticator)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"Proxy Authentication required";
}

void AccesSequence::onSslErrors([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]const QList<QSslError> &errors)
{
    qDebug() << "[REQUEST_HANDLER]: "<<"ENCOUNTERED SSL ERRORS";
}
}
