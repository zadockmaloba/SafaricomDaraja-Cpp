/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#include "networkhandler.h"

namespace DarajaCpp {
NetworkHandler::NetworkHandler()
{
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::finished, this, &NetworkHandler::onFinished);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::authenticationRequired, this, &NetworkHandler::onAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::encrypted, this, &NetworkHandler::onEncrypted);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &NetworkHandler::onPreSharedKeyAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::proxyAuthenticationRequired, this, &NetworkHandler::onProxyAuthenticationRequired);
    QObject::connect(&this->m_httpHandler, &QNetworkAccessManager::sslErrors, this, &NetworkHandler::onSslErrors);
}

const QNetworkAccessManager &NetworkHandler::httpHandler() const
{
    return m_httpHandler;
}

const QNetworkRequest &NetworkHandler::httpRequest() const
{
    return m_httpRequest;
}

void NetworkHandler::get(const QNetworkRequest* request)
{
    auto const _reply = m_httpHandler.get(*request);
    QObject::connect(_reply, &QNetworkReply::readyRead, this, &NetworkHandler::onReadyRead);
    _reply->waitForReadyRead(3000);
}

void NetworkHandler::put(const QNetworkRequest* request)
{
    auto const _reply = m_httpHandler.get(*request);
    QObject::connect(_reply, &QNetworkReply::readyRead, this, &NetworkHandler::onReadyRead);
    _reply->waitForReadyRead(3000);
}

void NetworkHandler::onReadyRead()
{
    auto const _reply = qobject_cast<QNetworkReply*> (sender());
    qDebug() << _reply->readAll();
}

void NetworkHandler::onAuthenticationRequired([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]QAuthenticator *authenticator)
{
    _NETWORK_HANDLER_MSG_("AUTHENTICATION REQUIRED");
}

void NetworkHandler::onEncrypted([[maybe_unused]]QNetworkReply *reply)
{
    _NETWORK_HANDLER_MSG_("Request Encrypted");
}

void NetworkHandler::onFinished([[maybe_unused]]QNetworkReply *reply)
{
    _NETWORK_HANDLER_MSG_("Request Finished");
    delete reply;
}

void NetworkHandler::onPreSharedKeyAuthenticationRequired([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]QSslPreSharedKeyAuthenticator *authenticator)
{
    _NETWORK_HANDLER_MSG_("PreShared Key Authentication Required");
}

void NetworkHandler::onProxyAuthenticationRequired([[maybe_unused]]const QNetworkProxy &proxy, [[maybe_unused]]QAuthenticator *authenticator)
{
    _NETWORK_HANDLER_MSG_("Proxy Authentication Required");
}

void NetworkHandler::onSslErrors([[maybe_unused]]QNetworkReply *reply, [[maybe_unused]]const QList<QSslError> &errors)
{
    _NETWORK_HANDLER_MSG_("SSL ERRORS ENCOUNTERED");
}
}
