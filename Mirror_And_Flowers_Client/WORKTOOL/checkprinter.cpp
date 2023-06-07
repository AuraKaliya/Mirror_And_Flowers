#include "checkprinter.h"

CheckPrinter* CheckPrinter::m_instance=nullptr;

CheckPrinter* CheckPrinter::GetInstance()
{
    if(m_instance==nullptr)
        m_instance=new CheckPrinter();
    return m_instance;
}

void CheckPrinter::SoluteCheck(QString modName, bool flag)
{
    if(flag)
    {
        qDebug()<<modName<<"is Passed";
    }
    else
    {
        qDebug()<<modName<<"is Blocked";
    }
}

CheckPrinter::CheckPrinter()
{

}
