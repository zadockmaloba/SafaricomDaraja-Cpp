/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#include <QCoreApplication>
#include "networkhandler.h"
#include "accesstokenrequest.h"
#include "registerurlrequest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DarajaCpp::NetworkHandler netH;
    //process the request
    //arg1: consumerKey , arg2: consumerSecret
    DarajaCpp::AccessTokenRequest _acc(""/*Enter consumer key*/,""/*Enter consumer secret*/);

    DarajaCpp::RegisterUrlRequest _url(""/*Generated accessToken*/);

    _url.setRequestBody({{"ShortCode",""/*Business ShortCode*/},
                         {"ResponseType",""/*Completed or Canceled*/},
                         {"ConfirmationURL",""/*url to confirmation server*/},
                         {"ValidationURL",""/*url to validation server*/}});

    _acc.renderRequest(&netH);
    _url.renderRequest(&netH);

    return a.exec();
}
