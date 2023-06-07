#include "linkmanager.h"

LinkManager* LinkManager::m_instance=nullptr;
LinkManager *LinkManager::GetInstance(QObject *parent)
{
    if(m_instance==nullptr)
        m_instance=new LinkManager(parent);
    return m_instance;
}

void LinkManager::InitSocket()
{
    m_flushTimer=new QTimer(this);
    connect(m_flushTimer,&QTimer::timeout,this,&LinkManager::FlushSocket);
}

LinkManager::LinkManager(QObject *parent)
    : QObject{parent}
{
    m_machine=MachineInformation::GetInstance();

    m_tcpClient=new QTcpSocket(parent);
    m_tcpClient->setProxy(QNetworkProxy::NoProxy);
    connect(m_tcpClient,&QTcpSocket::readyRead,this,&LinkManager::ReadData);
    connect(m_tcpClient,SIGNAL(errorOccurred(QAbstractSocket::SocketError)),this,SLOT(ReadError(QAbstractSocket::SocketError)));


}

void LinkManager::LinkToServer()
{
    QString tmpServerIP=m_machine->GetDestServerIP();
    int tmpServerPort=m_machine->GetDestServerPort();
    m_tcpClient->abort();
    m_tcpClient->connectToHost(QHostAddress(tmpServerIP),tmpServerPort);

    if(!m_tcpClient->waitForConnected(10000))
    {
        //====================================待添加=========================================================//
        //错误提示
        //====================================待添加=========================================================//
        return;
    }
    //====================================待添加=========================================================//
    //连接成功的提示
    //后续操作
    //====================================待添加=========================================================//



}

void LinkManager::ReadData()
{
    QByteArray buffer=m_tcpClient->readAll();
    //====================================待添加=========================================================//
    //检查语句
    //====================================待添加=========================================================//
    if(!buffer.isEmpty())
    {
        QString tmpStr=tr(buffer);
        //====================================待添加=========================================================//
        //检查语句
        //====================================待添加=========================================================//
        InstructionContext context;
        context.initInstructionContext(tmpStr);
        InstructionBase* instruction=InstructionFactory::GetInstance()->createInstruction(context.GetInstructionName());
        instruction->ExcuteInstruction(context);
    }
}

void LinkManager::SendData(InstructionContext context)
{
    QString instructionText=context.GetInstructionText();
    m_tcpClient->write(instructionText.toUtf8());
    m_flushTimer->start(25);
}


void LinkManager::ReadError(QAbstractSocket::SocketError)
{

}

void LinkManager::FlushSocket()
{
    m_flushTimer->stop();
    m_tcpClient->flush();
}
