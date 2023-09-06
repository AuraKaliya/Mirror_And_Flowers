#include "cardinfowidget.h"

CardInfoWidget::CardInfoWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_viewWidget=new QWidget(this);
    m_cardImageLabel=new QLabel(m_viewWidget);
//    m_cardATKLabel=new QLabel(m_viewWidget);
//    m_cardDEFLabel=new QLabel(m_viewWidget);
//    m_cardDHPLabel=new QLabel(m_viewWidget);
    m_cardNameLabel=new QLabel(m_viewWidget);
    m_cardNameLabel->setAlignment(Qt::AlignCenter);
    m_cardCategtoryLabel=new QLabel(m_viewWidget);
    m_cardCategtoryLabel->setAlignment(Qt::AlignCenter);
    m_addToDeckLabel=new ClickLabel(m_viewWidget);
    m_addToDeckLabel->setAlignment(Qt::AlignCenter);

    //ATK
    AttributeShowWidget* ATKWidget=new AttributeShowWidget(m_viewWidget);
    ATKWidget->SetTitle("DATK");
    ATKWidget->SetValue(0);
    AddWidget(ATKWidget);

    //DEF
    AttributeShowWidget* DEFWidget=new AttributeShowWidget(m_viewWidget);
    DEFWidget->SetTitle("DDEF");
    DEFWidget->SetValue(0);
    AddWidget(DEFWidget);

    //DHP
    AttributeShowWidget* DHPWidget=new AttributeShowWidget(m_viewWidget);
    DHPWidget->SetTitle("DHP");
    DHPWidget->SetValue(0);
    AddWidget(DHPWidget);
    m_addToDeckLabel->setText("加入卡组");
}

void CardInfoWidget::InitWidget()
{
    int myWidth=geometry().width();
    //qDebug()<<"233333";
    m_cardImageLabel->setGeometry((myWidth-ConstNumber::CARDMIDLEW)/2,
                                  ConstNumber::MARGINSMALL,
                                  ConstNumber::CARDMIDLEW,
                                  ConstNumber::CARDMIDLEH
                                  );

    m_cardNameLabel->setGeometry(ConstNumber::MARGINSMALL,
                                 ConstNumber::CARDMIDLEH+ConstNumber::MARGINSMALL*2,
                                 myWidth*0.4+ConstNumber::MARGINSMALL,
                                 ConstNumber::HEIGHTSMALL
                                 );
    m_cardCategtoryLabel->setGeometry(myWidth*0.6-ConstNumber::MARGINSMALL,
                                      ConstNumber::CARDMIDLEH+ConstNumber::MARGINSMALL*2,
                                      myWidth*0.4+ConstNumber::MARGINSMALL,
                                      ConstNumber::HEIGHTSMALL
                                      );
    //qDebug()<<"2333334";
    for(int i=0;i<m_attributeWidgetList.size();++i)
    {
        m_attributeWidgetList[i]->setGeometry(0,
                                              ConstNumber::CARDMIDLEH+ ConstNumber::HEIGHTSMALL*(1+i)+ConstNumber::MARGINSMALL*(2+i*2),
                                              myWidth,
                                              ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL
                                              );
        //qDebug()<<m_attributeWidgetList[i]<<"233333666";
        m_attributeWidgetList[i]->InitWidget();
    }
    //qDebug()<<"2333336";
    m_addToDeckLabel->setGeometry(myWidth*0.6-ConstNumber::MARGINSMALL,
                                  ConstNumber::CARDMIDLEH+ ConstNumber::HEIGHTSMALL*(1+m_attributeWidgetList.size())+ConstNumber::MARGINSMALL*(2+m_attributeWidgetList.size()*2),
                                  myWidth*0.4+ConstNumber::MARGINSMALL,
                                  ConstNumber::HEIGHTSMALL
                                  );
    m_viewWidget->adjustSize();
    //qDebug()<<"2333338";
}

void CardInfoWidget::SetCard(Card *card)
{
    m_nowCard=card;
    UpdateWidgetInfo();
}

void CardInfoWidget::UpdateWidgetInfo()
{

    m_attributeWidgetList[0]->SetValue(m_nowCard->GetATK());
    m_attributeWidgetList[1]->SetValue(m_nowCard->GetDEF());
    m_attributeWidgetList[2]->SetValue(m_nowCard->GetDHP());
    m_cardImageLabel->setStyleSheet("border-image:url("+m_nowCard->GetImageUrl()+");");
    m_cardNameLabel->setText(m_nowCard->GetName());
    m_cardCategtoryLabel->setText(m_nowCard->GetCategory());
    InitWidget();

}

void CardInfoWidget::AddWidget(AttributeShowWidget *pWidget)
{
    pWidget->setParent(m_viewWidget);
    m_attributeWidgetList.append(pWidget);
    pWidget->setVisible(true);
}

void CardInfoWidget::wheelEvent(QWheelEvent *e)
{
    int delta=e->angleDelta().y();
    m_viewWidget->move(m_viewWidget->x(),m_viewWidget->y()+delta);
    RedoMove();
}

void CardInfoWidget::RedoMove()
{
    int nowY=m_viewWidget->y();
    int heightLimit=this->height();
    if(nowY+m_viewWidget->height()<heightLimit)
    {
        m_viewWidget->move(m_viewWidget->x(),heightLimit-m_viewWidget->height());
    }
    else if(nowY>0)
    {
         m_viewWidget->move(m_viewWidget->x(),0);
    }
}
