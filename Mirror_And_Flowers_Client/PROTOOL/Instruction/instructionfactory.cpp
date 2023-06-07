#include "instructionfactory.h"

InstructionFactory* InstructionFactory::m_instance=nullptr;
InstructionFactory *InstructionFactory::GetInstance()
{
    if(m_instance==nullptr)
        m_instance=new InstructionFactory();
    return m_instance;
}

void InstructionFactory::RegisterInstruction(const QString &insName, InstructionBase *insClass)
{
    m_NameToInsDictionary[insName]=insClass;
}

InstructionBase *InstructionFactory::createInstruction(const QString &insName)
{
    auto it=m_NameToInsDictionary.find(insName);
    if(it!=m_NameToInsDictionary.end())return it.value();
    else return nullptr;
}

InstructionFactory::InstructionFactory()
{

}
