#include "instructionregister.h"

InstructionRegister::InstructionRegister()
{

}

InstructionRegister::InstructionRegister(const QString &insName, InstructionBase *insClass)
{
    InstructionFactory * factory=InstructionFactory::GetInstance();
    factory->RegisterInstruction(insName,insClass);
}
