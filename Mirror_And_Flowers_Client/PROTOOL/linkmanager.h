#ifndef LINKMANAGER_H
#define LINKMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <QNetworkProxy>
#include <QTimer>
#include "../DATA/machineinformation.h"
#include "../DATA/instructioncontext.h"
#include "Instruction/instructionfactory.h"
#include "Instruction/instructionbase.h"


class LinkManager : public QObject
{
    Q_OBJECT
public:
    static LinkManager*GetInstance(QObject *parent);
    void InitSocket();

signals:

private:
    static LinkManager* m_instance;
    explicit LinkManager(QObject *parent = nullptr);

    QTcpSocket *m_tcpClient;
    MachineInformation* m_machine;
    QTimer * m_flushTimer;
private slots:
    void LinkToServer();
    void ReadData();
    void SendData(InstructionContext);
    void ReadError(QAbstractSocket::SocketError);
    void FlushSocket();
};

#endif // LINKMANAGER_H
