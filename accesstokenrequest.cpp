#include "accesstokenrequest.h"

/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

namespace DarajaCpp {
AccessTokenRequest::AccessTokenRequest(QString consumerKey, QString consumerSecret)
    : m_consumerKey(consumerKey),
      m_consumerSecret(consumerSecret),
      m_authUrl("https://sandbox.safaricom.co.ke/oauth/v1/generate?grant_type=client_credentials"),
      m_succeeded(false)
{
    this->m_httpRequest.setUrl(this->m_authUrl);
    this->m_httpRequest.setRawHeader("Content-Type", "application/json; charset=utf8");
    this->m_httpRequest.setRawHeader("Authorization","Basic QXpzMktlalUxQVJ2SUw1SmRKc0FSYlYyZ0RyV21wT0I6aGlwR3ZGSmJPeHJpMzMwYw==");
    this->m_httpRequest.setRawHeader("Cookie",
                                     "incap_ses_1024_2742146=ukhlWrBitErUp67HLPs1Du4WcWIAAAAAxaCfuY88C1+UAaE98pBonA==; "
                                     "visid_incap_2742146=EPpdLH1HRTCGDXJgry4FTsRAUGIAAAAAQUIPAAAAAAB6fJ+waBY2//+5ypBHW7PQ");
}

const QString &AccessTokenRequest::consumerSecret() const {return m_consumerSecret;}

void AccessTokenRequest::setConsumerSecret(const QString &newConsumerSecret){ m_consumerSecret = newConsumerSecret; }

const QString &AccessTokenRequest::consumerKey() const{ return m_consumerKey; }

void AccessTokenRequest::setConsumerKey(const QString &newConsumerKey){ m_consumerKey = newConsumerKey; }

const QNetworkRequest &AccessTokenRequest::httpRequest() const
{
    return m_httpRequest;
}
}
