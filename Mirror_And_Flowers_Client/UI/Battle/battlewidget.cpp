#include "battlewidget.h"

BattleWidget::BattleWidget(QWidget *parent)
    : QWidget{parent}
{
    //setStyleSheet("background-color:red;");
    resize(1600,900);
    m_cardDeckCount=0;
    m_timeCount=30;

    m_Me=nullptr;
    m_Op=nullptr;

    m_myHPBorder=QRect(50,75,600,50);
    m_opHPBorder=QRect(950,75,600,50);
    m_myHPNow=QRect(50,75,600,50);
    m_opHPNow=QRect(950,75,600,50);

    m_myCharacterRect=QRect(150,125,250,450);
    m_opCharacterRect=QRect(1200,125,250,450);

    m_timer=new QTimer(this);
    m_timer->setInterval(1000);
    m_timerLabel=new ClickLabel(this);
    m_timerLabel->setGeometry(700,75,200,50);
    m_timerLabel->setAlignment(Qt::AlignCenter);
    m_timerLabel->setStyleSheet("background-color:white;color: khaki; font-size: 30pt;");



    m_bottomRect=QRect(0,575,1600,325);

    m_talkWidegt=new QTextEdit(this);
    m_talkWidegt->setGeometry(0,575,400,325);
    m_talkWidegt->setReadOnly(true);
    m_talkWidegt->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    m_talkWidegt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_talkWidegt->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    m_handCardWidget=new handCardWidget(this);

    connect(m_handCardWidget,&handCardWidget::cardUsed,[=](Card*card){
        BattleManager::GetInstance()->UseCard(card);
        qDebug()<<"顺利到达这里";
        m_handCardWidget->UpdateHandCard(BattleManager::GetInstance()->GetCardHand());
        qDebug()<<"顺利到达这里2";
        m_handCardWidget->SetSmallState();
    });


    connect(m_talkWidegt, &QTextEdit::textChanged, [=](){
            m_talkWidegt->moveCursor(QTextCursor::End);

        });



    connect(m_timer,&QTimer::timeout,[=](){
        m_timeCount-=1;
        m_timerLabel->setText(QString::number(m_timeCount));
        if(!m_timeCount){
            m_timer->stop();
            m_timeCount=30;
            m_timerLabel->setText(QString::number(m_timeCount));
            BattleManager::GetInstance()->Battle();

        }
    });

    connect(m_timerLabel,&ClickLabel::clicked,[=](){
        m_timer->stop();
        m_timeCount=30;
        m_timerLabel->setText(QString::number(m_timeCount));
        BattleManager::GetInstance()->Battle();

    });

    connect(BattleManager::GetInstance(),&BattleManager::battleInfo,[=](QString str){
        m_talkWidegt->setText(m_talkWidegt->toPlainText()+"\n"+str);
    });


    connect(BattleManager::GetInstance(),&BattleManager::UpdatePlayerState,[=](double me,double op){
        qDebug()<<"***********************"<<me<<"    "<<op;
        m_myHPNow=QRect(50,75,600*me,50);
        m_opHPNow=QRect(950,75,600*op,50);
    });

    connect(BattleManager::GetInstance(),&BattleManager::NextTurn,[=](){
        qDebug()<<"NextTurn";
        m_timer->start();
        BattleManager::GetInstance()->DrawCard();
        UpdateWidgte();
    });

    connect(BattleManager::GetInstance(),&BattleManager::BattleEnd,[=](Character* character){
    m_timer->stop();

    QMessageBox msgBox;
    msgBox.setWindowTitle("战斗结束");
    QString str="战斗的获胜者为："+character->GetName();
    msgBox.setText(str);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.exec();
    UpdateWidgte();
    m_talkWidegt->clear();
    this->close();
    });


}

void BattleWidget::BattleStar()
{

    QPair<Character*,Character*> tmp=BattleManager::GetInstance()->GetCharacter();
    m_Me=tmp.first;
    m_Op=tmp.second;
    qDebug()<<"BattleStar:  ME:"<<m_Me->GetName()<<"  OP:"<<m_Op->GetName();

    BattleManager::GetInstance()->InitBattle();
    UpdateWidgte();
    m_timer->start();

}

void BattleWidget::UpdateWidgte()
{
    m_handCardWidget->UpdateHandCard(BattleManager::GetInstance()->GetCardHand());
    update();

}

void BattleWidget::paintEvent(QPaintEvent *e)
{
    QPainter *painter=new QPainter(this);

    painter->drawPixmap(m_myCharacterRect,QPixmap(m_Me->GetTachieUrl()));
    painter->drawPixmap(m_opCharacterRect,QPixmap(m_Op->GetTachieUrl()));

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::black,2));

    painter->drawRect(m_myHPBorder);
    qDebug()<<m_myHPBorder<<m_opHPBorder;
    painter->setBrush(Qt::green);
    painter->drawRect(m_myHPNow);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(m_opHPBorder);
    painter->setBrush(Qt::red);
    painter->drawRect(m_opHPNow);
    qDebug()<<m_myHPNow<<m_opHPNow;
    painter->end();



}
