#ifndef INITER_H
#define INITER_H

#include "jsonreader.h"


class Initer
{
public:
    Initer* GetInstance();
    void Init();
    void InitData();
    void InitUI();
private:
    static Initer* m_instance;
    Initer();


};

#endif // INITER_H
