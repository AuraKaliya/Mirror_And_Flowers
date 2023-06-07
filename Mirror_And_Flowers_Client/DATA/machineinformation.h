#ifndef MACHINEINFORMATION_H
#define MACHINEINFORMATION_H
#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSysInfo>
#include "QSettings"
#include "QDebug"
//#include <QDesktopWidget>
#include <QFileInfoList>
#include <QDir>
#include <QLibrary>
#include <QTimer>
#include <QHostInfo>

#include <QString>

#include "../WORKTOOL/checkprinter.h"
#pragma execution_character_set("utf-8")
class MachineInformation
{
public:
    static MachineInformation* GetInstance();

    bool InitMachineInformation();
    bool UpdateMachineInformation();

    QString GetMachineName();
    void SetMachineName(const QString &machineName);
    bool UpdateMachineName();

    QString GetMachineMac();
    bool UpdateMachineMac();

    QString GetDestServerIP();
    void SetDestServerIP(QString destServerIP);

    int GetDestServerPort();
    void SetDestServerPort(int destServerPort);
private:
    static MachineInformation* m_instance;
    MachineInformation();
    QString m_machineName;
    QString m_machineMac;
    QString m_destServerIP;
    int m_destServerPort;

};

#endif // MACHINEINFORMATION_H
