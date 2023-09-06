#include "machineinformation.h"


MachineInformation* MachineInformation::m_instance=nullptr;

MachineInformation *MachineInformation::GetInstance()
{
    if(m_instance==nullptr)
        m_instance=new MachineInformation();
    return m_instance;
}

bool MachineInformation::InitMachineInformation()
{
    bool flag=true;
    QString funcName;

    flag=UpdateMachineName();
    funcName="UpdateMachineName";
    CheckPrinter::GetInstance()->SoluteCheck(funcName,flag);

    flag=UpdateMachineMac();
    funcName="UpdateMachineMac";
    CheckPrinter::GetInstance()->SoluteCheck(funcName,flag);


    return flag;
}

bool MachineInformation::UpdateMachineInformation()
{
    //====================================待添加=========================================================//
    //检查功能
    //====================================待添加=========================================================//
    return true;
}

QString MachineInformation::GetMachineName()
{
    return m_machineName;
}

void MachineInformation::SetMachineName(const QString &machineName)
{
    m_machineName=machineName;
}

bool MachineInformation::UpdateMachineName()
{

    QString machineName=QHostInfo::localHostName();
    //====================================待添加=========================================================//
    //错误提示
    //====================================待添加=========================================================//
    if (machineName=="")
        return false;
    m_machineName=machineName;
    return true;
}

QString MachineInformation::GetMachineMac()
{
    QString tmpStr="";
    QStringList tmpL=m_machineMac.split(":");
    for(int i=0;i<3;++i)
    {
        tmpStr+=tmpL[i];
    }
    return tmpStr;
}

bool MachineInformation::UpdateMachineMac()
{
    QString strMac;

    QList<QNetworkInterface> netList = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface item, netList)
    {
        if((QNetworkInterface::IsUp & item.flags()) && (QNetworkInterface::IsRunning & item.flags()))
        {
            if(strMac.isEmpty() || strMac < item.hardwareAddress())
            {
                strMac = item.hardwareAddress();
            }
        }
    }
    //====================================待添加=========================================================//
    //错误提示
    //====================================待添加=========================================================//
    if(strMac=="")
        return false;
    m_machineMac=strMac;
    return true;
}

QString MachineInformation::GetDestServerIP()
{
    return m_destServerIP;
}

void MachineInformation::SetDestServerIP(QString destServerIP)
{
    m_destServerIP=destServerIP;
}

int MachineInformation::GetDestServerPort()
{
    return m_destServerPort;
}

void MachineInformation::SetDestServerPort(int destServerPort)
{
    m_destServerPort=destServerPort;
}

MachineInformation::MachineInformation()
{

}
