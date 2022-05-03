/*
 * Author: Zadock Maloba
 * E-mail: zadockmaloba@outlook.com
 * Twitter: zadock_254
 * copyright: Zadock Maloba, 2022
*/

#include <QCoreApplication>
#include "accesstoken.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DarajaCpp::AccessToken _acc("K79W9GwaxIrSEfbpbdodzeUc03j60BqG","ULuAkt8Xjb3VLHds");

    return a.exec();
}
