#include "charactershowwidget.h"

CharacterShowWidget::CharacterShowWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_nowState=false;
    m_infoWidget=new CharacterInfoWidget(this);
    m_tachieLabel=new ClickLabel(this);

}

void CharacterShowWidget::SetLinkCharacter(Character *character)
{
    m_linkCharacter=character;
}

void CharacterShowWidget::SetSize(QSize normalSize)
{
    m_normalSize=normalSize;
    m_expandSize=QSize(m_normalSize.width()*2,m_normalSize.height());

    resize(m_normalSize);

}

void CharacterShowWidget::InitWidget()
{
    m_nowState=false;

    m_tachieLabel->setGeometry(0,0,m_normalSize.width(),m_normalSize.height());
    m_infoWidget->setGeometry(0,0,m_normalSize.width(),m_normalSize.height());
    m_tachieLabel->raise();
    if(m_linkCharacter!=nullptr)
    {
        m_tachieLabel->SetImage(m_linkCharacter->GetTachieUrl());
        m_infoWidget->SetCharacterName(m_linkCharacter->GetName());
        m_infoWidget->SetCharacterTitle(m_linkCharacter->GetTitle());
        m_infoWidget->SetCharacterIntroduction(m_linkCharacter->GetIntroduction());

        //ATK
        AttributeShowWidget* atkWidget=new AttributeShowWidget(m_infoWidget);
        atkWidget->SetTitle("ATK");
        atkWidget->SetValue(m_linkCharacter->GetATK());
        m_infoWidget->AddWidget(atkWidget);
        //atkWidget->InitWidget();   只能调用下一级的Init，不能越位初始化
        //DEF
        AttributeShowWidget* defWidget=new AttributeShowWidget(m_infoWidget);
        defWidget->SetTitle("DEF");
        defWidget->SetValue(m_linkCharacter->GetDEF());
        m_infoWidget->AddWidget(defWidget);
        //HP
        AttributeShowWidget* hpWidget=new AttributeShowWidget(m_infoWidget);
        hpWidget->SetTitle("HP");
        hpWidget->SetValue(m_linkCharacter->GetHP());
        m_infoWidget->AddWidget(hpWidget);

        m_infoWidget->InitWidget();
    }

    connect(m_tachieLabel,&ClickLabel::clicked,this,[=](){
        if(m_nowState==false)
        {
            //resize(m_expandSize.width(),m_expandSize.height());



            QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
            animation->setDuration(200);
            connect(animation,&QPropertyAnimation::finished,[this](){
                m_nowState=true;
                emit UIWidget::CharacterChoiced(m_linkCharacter);
            });
            connect(animation,&QPropertyAnimation::valueChanged,[this](){
                m_infoWidget->move(this->width()-m_infoWidget->width(),m_infoWidget->y());
                //qDebug()<<"foriiii3";
                emit UIWidget::RectChanged();
            });
            animation->setStartValue(this->geometry());
            QRect desRect(this->geometry().x(),this->geometry().y(),m_expandSize.width(),m_expandSize.height());
            animation->setEndValue(desRect);
            animation->start(QAbstractAnimation::DeleteWhenStopped);

        }else
        {

            QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
            animation->setDuration(200);
            connect(animation,&QPropertyAnimation::finished,[this](){
                m_nowState=false;

            });
            connect(animation,&QPropertyAnimation::valueChanged,[this](){
                m_infoWidget->move(this->width()-m_infoWidget->width(),m_infoWidget->y());
                //qDebug()<<"foriiii";
                emit UIWidget::RectChanged();
            });
            animation->setStartValue(this->geometry());
            QRect desRect(this->geometry().x(),this->geometry().y(),m_normalSize.width(),m_normalSize.height());
            animation->setEndValue(desRect);
            animation->start(QAbstractAnimation::DeleteWhenStopped);
        }
    });

    //--//
    CheckPrinter::GetInstance()->AddCheckWidget(this);
    //--//
}
