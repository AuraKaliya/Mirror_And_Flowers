#include "instructioncontext.h"

InstructionContext::InstructionContext()
{
}

void InstructionContext::initInstructionContext(QString instructionText)
{
    m_instructionText=instructionText ;
    QStringList tmpList=m_instructionText.split("|");
    QList<QString> contextTextList;
    for(auto it:tmpList)
    {
        contextTextList.append(it);
    }
    for(int i=contextTextList.size()-1;i<5;++i)
    {
        contextTextList.append("0");
    }

    SetInsSender(contextTextList[0]);
    SetInsReceiver(contextTextList[1]);
    SetInsType(contextTextList[2]);
    SetInsObject(contextTextList[3]);
    SetInsValue(contextTextList[4]);

    QString tmpStr="Instruction_"+contextTextList[2]+"_"+contextTextList[3];
    SetInstructionName(tmpStr);
}

QString InstructionContext::GetInstructionText()
{
    QString tmpStr="";
    tmpStr+=GetInsSender();
    tmpStr+="|";
    tmpStr+=GetInsReceiver();
    tmpStr+="|";
    tmpStr+=GetInsType();
    tmpStr+="|";
    tmpStr+=GetInsObject();
    tmpStr+="|";
    tmpStr+=GetInsValue();
    return tmpStr;
}

QString InstructionContext::GetInsSender() const
{
    return m_insSender;
}

void InstructionContext::SetInsSender(const QString& sender)
{
    m_insSender = sender;
}

QString InstructionContext::GetInsReceiver() const
{
    return m_insReceiver;
}

void InstructionContext::SetInsReceiver(const QString& receiver)
{
    m_insReceiver = receiver;
}

QString InstructionContext::GetInsType() const
{
    return m_insType;
}

void InstructionContext::SetInsType(const QString& type)
{
    m_insType = type;
}

QString InstructionContext::GetInsObject() const
{
    return m_insObject;
}

void InstructionContext::SetInsObject(const QString& object)
{
    m_insObject = object;
}

QString InstructionContext::GetInsValue() const
{
    return m_insValue;
}

void InstructionContext::SetInsValue(const QString& value)
{
    m_insValue = value;
}

void InstructionContext::SetInstructionName(const QString &newInstructionName)
{
    m_instructionName = newInstructionName;
}

QString InstructionContext::GetInstructionName() const
{
    return m_instructionName;
}
