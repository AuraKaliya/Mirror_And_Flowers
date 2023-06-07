#ifndef INSTRUCTIONBASE_H
#define INSTRUCTIONBASE_H

#include "../../DATA/instructioncontext.h"

class InstructionBase
{
public:
    InstructionBase();
    virtual void ExcuteInstruction(InstructionContext context)=0;
private:

};

#endif // INSTRUCTIONBASE_H
