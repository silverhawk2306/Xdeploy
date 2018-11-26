#ifndef XDEPLOY_H
#define XDEPLOY_H

#include <QObject>
#include <QProcess>
#include <QDir>

class XDeploy : public QObject
{
    Q_OBJECT
public:
    explicit XDeploy(QObject *parent = 0);
    void deploy(QString sourcePath, QString destPath);
signals:

public slots:

private:
    QProcess process;
};

#endif // XDEPLOY_H
