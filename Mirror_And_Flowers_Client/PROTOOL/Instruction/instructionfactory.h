#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include <QString>
#include <QMap>
#include "instructionbase.h"

class InstructionFactory
{
public:
    static InstructionFactory* GetInstance();
    void RegisterInstruction(const QString &insName,InstructionBase*insClass);
    InstructionBase* createInstruction(const QString &insName);
private:
    static InstructionFactory* m_instance;
    InstructionFactory();

    QMap<QString,InstructionBase*>m_NameToInsDictionary;
};

#endif // INSTRUCTIONFACTORY_H
