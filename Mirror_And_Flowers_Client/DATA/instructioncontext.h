#ifndef INSTRUCTIONCONTEXT_H
#define INSTRUCTIONCONTEXT_H

#include <QString>
#include <QStringList>
#include <QList>



//------------------------------指令格式-------------------------//
//          发送者|接收者（主机名+机器码前五位）|指令类型|指令名|指令值
//         AuraKaliye70:1A|Sever|Match|JoinGame
//         Sever|AuraKaliye70:1A|Match|Succeeded|Monkey20:3B#Luwies
//         AuraKaliye70:1A|Sever|Battle|UseCard|10002
//         Sever|AuraKaliye70:1A|Battle|Messages|Opponent#Card@恢复魔瓶
//         Sever|AuraKaliye70:1A|Battle|Process|Me#NowHP@800,NowATK@300,NowDEF@400
//         AuraKaliye70:1A|Sever|Battle|End
//         Sever|AuraKaliye70:1A|Battle|Result|Winner@Me
//         AuraKaliye70:1A|Sever|Battle|UseCard|10002
//         Sever|AuraKaliye70:1A|Battle|NowTime|30
//         Sever|AuraKaliye70:1A|Battle|NowTime|29
//         Sever|AuraKaliye70:1A|Battle|OppoEnd
//         Sever|AuraKaliye70:1A|Battle|NewTurn
//------------------------------指令格式-------------------------//
class InstructionContext
{
public:
    InstructionContext();

    void initInstructionContext(QString instructionText);
    QString GetInstructionText();

    QString GetInsSender() const;
    void SetInsSender(const QString& sender);
    QString GetInsReceiver() const;
    void SetInsReceiver(const QString& receiver);
    QString GetInsType() const;
    void SetInsType(const QString& type);
    QString GetInsObject() const;
    void SetInsObject(const QString& object);
    QString GetInsValue() const;
    void SetInsValue(const QString& value);
    void SetInstructionName(const QString &newInstructionName);
    QString GetInstructionName() const;

private:
    QString m_instructionText;
    QString m_instructionName;
    QString m_insSender;
    QString m_insReceiver;
    QString m_insType;
    QString m_insObject;
    QString m_insValue;
};

#endif // INSTRUCTIONCONTEXT_H
