#include "constnumber.h"


QMap<QString,ConstNumber::Battle> ConstNumber::m_battleAttributeDictionary={
    {"ATK", ConstNumber::ATKMAX},
    {"DEF", ConstNumber::DEFMAX},
    {"HP", ConstNumber::HPMAX},
    {"DHP", ConstNumber::DHPMAX},
    {"DATK", ConstNumber::DATKMAX},
    {"DDEF", ConstNumber::DDEFMAX},
};

ConstNumber::ConstNumber()
{

}

ConstNumber::Battle ConstNumber::GetAttributeMax(QString attribute)
{

    auto it =m_battleAttributeDictionary.find(attribute);
    if(it != m_battleAttributeDictionary.end())
    {
        return it.value();
    }else
    {
        return ConstNumber::ERROR;
    }
}
