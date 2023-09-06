#include "battlemanager.h"

Player* BattleManager::s_player1=nullptr;
Player* BattleManager::s_player2=nullptr;
BattleManager* BattleManager::m_instance=nullptr;

BattleManager::BattleManager()
{


    m_CardSolution.insert("Prop",BattleManager::SolveCardProp);
    m_CardSolution.insert("Deprop",BattleManager::SolveCardDeprop);
    m_CardSolution.insert("Equipment",BattleManager::SolveCardEquipment);
    m_battleFlag=false;
}

BattleManager *BattleManager::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new BattleManager();
    }
    return m_instance;
}

void BattleManager::SolveCardProp(Card *card)
{
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::ATKd,card->GetATK());
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::DEFd,card->GetDEF());
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::HPd,card->GetDHP());
}

void BattleManager::SolveCardDeprop(Card *card)
{
    BattleManager::GetInstance()->UpdatePlayer(s_player2,ConstNumber::ATKd,card->GetATK());
    BattleManager::GetInstance()->UpdatePlayer(s_player2,ConstNumber::DEFd,card->GetDEF());
    BattleManager::GetInstance()->UpdatePlayer(s_player2,ConstNumber::HPd,card->GetDHP());
}

void BattleManager::SolveCardEquipment(Card *card)
{
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::ATKe,card->GetATK());
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::DEFe,card->GetDEF());
    BattleManager::GetInstance()->UpdatePlayer(s_player1,ConstNumber::HPe,card->GetDHP());
}

void BattleManager::InitBattle()
{
    for(int i=0;i<m_cardHand.size();i++)
    {
        m_cardHand.removeFirst();
    }
    m_cardHand.clear();

    if(s_player1!=nullptr) delete s_player1;
    if(s_player2!=nullptr) delete s_player2;
    s_player1=new Player();
    s_player2=new Player();

    s_player1->SetOpponent(s_player2);
    s_player2->SetOpponent(s_player1);

    if(m_myCharacter!=nullptr&&m_opCharacter!=nullptr)
    {

        qDebug()<<"InitBattle:  Set Players Protility.";
        s_player1->SetHPMax(m_myCharacter->GetHP());
        qDebug()<<"********@@@@@"<<m_myCharacter->GetHP();
        s_player1->SetHPNow(s_player1->GetHPMax());
        qDebug()<<"********@@@@@"<<s_player1->GetHPMax();
        s_player1->SetATK(m_myCharacter->GetATK());
        s_player1->SetDEF(m_myCharacter->GetDEF());

        s_player2->SetHPMax(m_opCharacter->GetHP());
        s_player2->SetHPNow(s_player2->GetHPMax());
        s_player2->SetATK(m_opCharacter->GetATK());
        s_player2->SetDEF(m_opCharacter->GetDEF());


        s_player1->show();
        s_player2->show();
        qDebug()<<"InitBattle:  Set Players Protility. end";
    }else
    {
        qDebug()<<"Character信息错误";
    }

    qDebug()<<"InitBattle: CardDeck Init.";
    QVector<int>tmpCardDeck;
    QVector<QString>tmpVector= CardDeckHub::GetInstance()->GetNowCardDeck()->GetContains();
    for(auto it:tmpVector)
    {
        tmpCardDeck.append(it.toInt());

    }
    qDebug()<<tmpCardDeck;



    m_cardDeck=CardHub::GetInstance()->GetCardListByID(tmpCardDeck);


    for(auto it:m_cardDeck) qDebug()<< "CardName: "<<it->GetName()<<" CardImage:"<<it->GetImageUrl();
    qDebug()<<"InitBattle: CardDeck Init.end";

    DrawCard();
    DrawCard();
    DrawCard();

    m_battleFlag=true;
    //emit battleStar();
    emit UpdatePlayerState(1,1);
    QString str("[SY] 战斗开始,当前对战角色："+m_myCharacter->GetName()+"(Me)对战"+m_opCharacter->GetName()+"(Op)。");
    emit battleInfo(str);
}

void BattleManager::InitCardDeck(QVector<Card *> cardDeck)
{


}


void BattleManager::DrawCard()
{
    qDebug()<<"DrawCard: "<<m_cardDeck;
    int rand=QRandomGenerator::global()->bounded(0,m_cardDeck.size());


    Card* card=m_cardDeck[rand];
    qDebug()<<"Rand:"<<rand<<"---CardId:"<<card->GetID();
    qDebug()<<"NowCard(rand):"<<card->GetName()<<" is null:"<<(card==nullptr);

    m_cardDeck.removeAt(rand);
    qDebug()<<"NowCard(rand):"<<card->GetName()<<" is null:"<<(card==nullptr);
    m_cardHand.append(card);
    qDebug()<<"NowCard(hand):"<<m_cardHand;
}

void BattleManager::SetOpCharacter(Character *character)
{
    qDebug()<<"BattleManager::SetOpCharacter"<<character->GetName();
    m_opCharacter=character;
}

void BattleManager::UseCard(Card *card)
{
    // 根据card类型获取相应instruction，根据card数值进行player更新。
    QString category=card->GetCategory();


    m_CardSolution.value(category)(card);

    m_cardHand.removeOne(card);

    QString battleInformation="[Me] ";
    battleInformation+=m_myCharacter->GetName();
    battleInformation+="使用了 ";
    battleInformation+=card->GetName();
    battleInformation+="(";
    battleInformation+=card->GetCategory();
    battleInformation+=") 。";
    emit battleInfo(battleInformation);



}

void BattleManager::UpdatePlayer(Player *p, ConstNumber::BattleInstruction ins, int value)
{
    switch (ins) {
    case ConstNumber::ATKd:
        p->SetTmpATK(p->GetTmpATK()+value);
        break;
    case ConstNumber::DEFd:
         p->SetTmpDEF(p->GetTmpDEF()+value);
        break;
    case ConstNumber::HPd:
        p->SetTmpHP(p->GetTmpHP()+value);
        break;
    case ConstNumber::ATKe:
        p->SetEquipATK(value);
        break;
    case ConstNumber::DEFe:
        p->SetEquipDEF(value);
        break;
    case ConstNumber::HPe:
        p->SetEquipHP(value);
        break;
    default:
        qDebug()<<"无此更新选项";
        break;
    }


}

void BattleManager::Battle()
{
    //一个回合结束，进行攻守模拟和战斗结果判定--测试用

    //计算本体攻击总值与对手防御总值
    int mySumATK=s_player1->GetATK()+s_player1->GetEquipATK()+s_player1->GetTmpATK();
    int opSumDEF=s_player2->GetDEF()+s_player2->GetEquipDEF()+s_player2->GetTmpDEF();

    //攻守模拟和进行战斗结果判定
    int  tmpHP=mySumATK-opSumDEF;
    if(tmpHP>=0)
    {
        s_player2->SetHPNow(s_player2->GetHPNow()-tmpHP);
        qDebug()<<"s_player2 NOWHP"<<s_player2->GetHPNow();
    }else
    {
        tmpHP=0;
        QString tmpStr="[Me] "+m_myCharacter->GetName()+"的攻击未破防。";
        emit battleInfo(tmpStr);
       // qDebug()<<"你的攻击未破防";
    }
    QString str1="[SY] "+m_myCharacter->GetName()+"对"+m_opCharacter->GetName()+"造成"+QString::number(tmpHP)+"点伤害。";
    emit battleInfo(str1);
    AttackEnd();
    //模拟对手回合

    //计算本体攻击总值与对手防御总值
    int mySumATK2=s_player2->GetATK()+s_player2->GetEquipATK()+s_player2->GetTmpATK();
    int opSumDEF2=s_player1->GetDEF()+s_player1->GetEquipDEF()+s_player1->GetTmpDEF();

    //攻守模拟和进行战斗结果判定
    int  tmpHP2=mySumATK2-opSumDEF2;
    if(tmpHP2>=0)
    {
        s_player1->SetHPNow(s_player1->GetHPNow()-tmpHP2);

    }else
    {
        tmpHP2=0;
        //qDebug()<<"对手的攻击未破防";
    }
    QString str2="[SY] "+m_opCharacter->GetName()+"对"+m_myCharacter->GetName()+"造成"+QString::number(tmpHP2)+"点伤害。";
    emit battleInfo(str2);
    AttackEnd();

    if(m_battleFlag==true)
    {
        QString tmpStr="[SY] 当前回合结束。";
        emit battleInfo(tmpStr);
         emit NextTurn();
    }

}

void BattleManager::AttackEnd()
{
    qDebug()<<"================2222==========="<<(s_player1->GetHPNow()*1.0)/s_player1->GetHPMax()<<"===="<<(s_player2->GetHPNow()*1.0)/s_player2->GetHPMax();
    qDebug()<<s_player1->GetHPNow()<<" "<<s_player1->GetHPMax();
    qDebug()<<s_player2->GetHPNow()<<" "<<s_player2->GetHPMax();

    if(m_battleFlag==false) return;

    if(s_player1->GetHPNow()<=0)
    {
         m_battleFlag=false;
         for(int i=0;i<m_cardHand.size();i++)
         {
             m_cardHand.removeFirst();
         }
         m_cardHand.clear();
         emit BattleEnd(m_opCharacter);

    }
    else if(s_player2->GetHPNow()<=0)
    {
         m_battleFlag=false;
         for(int i=0;i<m_cardHand.size();i++)
         {
             m_cardHand.removeFirst();
         }
         m_cardHand.clear();
         emit BattleEnd(m_myCharacter);
    }

    if(m_battleFlag==true)
    emit UpdatePlayerState((s_player1->GetHPNow()*1.0)/s_player1->GetHPMax(),(s_player2->GetHPNow()*1.0)/s_player2->GetHPMax());
}

QVector<Card *> BattleManager::GetCardDeck()
{
    return m_cardDeck;
}

QVector<Card *> BattleManager::GetCardHand()
{
    return m_cardHand;
}

QPair<Character *, Character *> BattleManager::GetCharacter()
{
    return QPair<Character *, Character *>(m_myCharacter,m_opCharacter);
}

void BattleManager::CharacterChanged(Character *character)
{
    qDebug()<<"BattleManager::CharacterChanged"<<character->GetName();
    m_myCharacter=character;
}
