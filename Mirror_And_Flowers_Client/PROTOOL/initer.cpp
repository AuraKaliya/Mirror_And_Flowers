#include "initer.h"

Initer * Initer::m_instance=nullptr;
Initer *Initer::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new Initer();
    }
    return m_instance;
}

void Initer::Init()
{
    InitData();
    InitUI();
}

void Initer::InitData()
{

}

void Initer::InitUI()
{
//    JsonReader* jsr=JsonReader::GetInstance();
//    QString fileName="./RESOURCE/UI.json";
//    jsr->SetFileName(fileName);
//    jsr->ReadJsonToUI(this);
//    qDebug()<<"currentWidget:"<<this->currentWidget();
}

Initer::Initer()
{

}
