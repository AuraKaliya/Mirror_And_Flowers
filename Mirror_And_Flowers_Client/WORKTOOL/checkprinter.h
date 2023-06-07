#ifndef CHECKPRINTER_H
#define CHECKPRINTER_H

#include "checktool.h"
#include <QDebug>

class CheckPrinter:public CheckTool
{
public:
    static CheckPrinter* GetInstance();
    virtual void SoluteCheck(QString modName,bool flag) override;
private:
    static CheckPrinter* m_instance;
    CheckPrinter();

};

#endif // CHECKPRINTER_H
