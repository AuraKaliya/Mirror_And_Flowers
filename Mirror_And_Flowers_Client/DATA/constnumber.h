#ifndef CONSTNUMBER_H
#define CONSTNUMBER_H

#include <QMap>

class ConstNumber
{
public:
    ConstNumber();

    enum  MARGIN{MARGINSMALL=10,MARGINMIDDLE=30,MARGINLONG=50};
    enum  LABELSIZE{WIDTHSMALL=250,HEIGHTSMALL=60,WIDTHMIDDLE=400};
    enum  R{R30=30,R50=50,R70=70,R80=80,R100=100,R130=130,R150=150};
    enum  Battle{ERROR=0,HPMAX=3000,ATKMAX=1500,DEFMAX=1500,DATKMAX=1000,DDEFMAX=1000,DHPMAX=1000};

    enum  CardSize{CARDSMALLW=180,CARDSMALLH=320,CARDMIDLEW=360,CARDMIDLEH=640};
    //p:初始值改动  d：临时值改动  e：装备改动
    enum  BattleInstruction{ATKp,DEFp,HPp,ATKd,DEFd,HPd,ATKe,DEFe,HPe};
    static Battle GetAttributeMax(QString attribute);

private:
    static QMap<QString,ConstNumber::Battle> m_battleAttributeDictionary;
};


#endif // CONSTNUMBER_H
