#ifndef INSTRUCTIONREGISTER_H
#define INSTRUCTIONREGISTER_H

#include <QString>

#include "instructionfactory.h"
#include "instructionbase.h"

class InstructionRegister
{
public:
    InstructionRegister();
    InstructionRegister(const QString & insName,InstructionBase * insClass);
};


#define REGISTER_INSTRUCTION(insName) \
static InstructionBase * CreateInstruction##insName() \
{ \
    InstructionBase* obj =new insName(); \
    return obj; \
} \
static InstructionRegister insRegister##insName(#insName,CreateInstruction##insName());


#endif // INSTRUCTIONREGISTER_H
