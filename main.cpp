/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#include <QCoreApplication>
#include "networkhandler.h"
#include "accesstokenrequest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DarajaCpp::NetworkHandler netH;
    //process the request
    //arg1: consumerKey , arg2: consumerSecret
    DarajaCpp::AccessTokenRequest _acc("K79W9GwaxIrSEfbpbdodzeUc03j60BqG","ULuAkt8Xjb3VLHds");

    netH.get(&_acc.httpRequest());

    return a.exec();
}
