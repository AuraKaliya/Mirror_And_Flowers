#ifndef CHECKTOOL_H
#define CHECKTOOL_H

#include <QObject>
#include <QString>

//Base
#pragma execution_character_set("utf-8")
class CheckTool
{

public:
    explicit CheckTool();
    virtual void SoluteCheck(QString modName,bool flag)=0;

signals:

};

#endif // CHECKTOOL_H
