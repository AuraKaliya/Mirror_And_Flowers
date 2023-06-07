#include "jsonreader.h"

JsonReader* JsonReader::m_instance=nullptr;
JsonReader *JsonReader::GetInstance(QObject *parent)
{
    if (m_instance==nullptr)
        m_instance=new JsonReader(parent);
    return m_instance;
}

JsonReader::JsonReader(QObject *parent)
    : QObject{parent}
{

}
