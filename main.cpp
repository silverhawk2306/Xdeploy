#include <QCoreApplication>
#include "xdeploy.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XDeploy xdeploy;
    xdeploy.deploy(argv[1], argv[2]);

    return a.exec();
}

