#include "xdeploy.h"
#include <QDebug>
#include <QCoreApplication>

XDeploy::XDeploy(QObject *parent) : QObject(parent)
{

}


void XDeploy::deploy(QString sourcePath, QString destPath)
{
    QDir().mkdir(destPath);
    QString cmd("ldd ");
    cmd.append(sourcePath);
    this->process.start(cmd);
    this->process.waitForFinished();
    QString output(this->process.readAllStandardOutput());
    QStringList list = output.split("\n");
    QStringList libs;
    for(int i = 0; i < list.length(); i++) {
        QStringList array = list[i].split("=>");
        if(array.length() == 2) {
            libs.append(array[1]);
        }
    }

    QStringList libPaths;
    for(int i = 0; i<libs.length(); i++) {
        QStringList array = libs[i].split(" ");
        for(int j = 0; j < array.length(); j++) {
            if(!array[j].contains("(") && array[j] != "") {
                //qDebug() << "copy <<<"<<array[j]<< "to "<<destPath;
//                QFile::copy("/path/file", "/path/copy-of-file");
                QString cmd("sudo cp ");
                cmd.append(array[j]);
                cmd.append(" ");
                cmd.append(destPath);
                qDebug() << cmd;
                this->process.execute(cmd);
            }
        }
    }

    qDebug() << "end process";
    exit(0);
}
