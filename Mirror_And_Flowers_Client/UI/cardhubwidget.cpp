#include "cardhubwidget.h"

CardHubWidget::CardHubWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_viewWidget=new QWidget(this);
}

void CardHubWidget::AddLabel(ClickLabel * pLabel)
{
    pLabel->setParent(m_viewWidget);
    m_cardList.append(pLabel);
    pLabel->setVisible(m_viewWidget);
}

void CardHubWidget::InitWidget()
{
    QRect rect =this->geometry();
    //qDebug()<<"hahahahhahaaaaaaaaaaaaaaaaaaa  "<<m_cardList.size();
    for(int i=0;i<m_cardList.size();++i)
    {
        int tmpW=m_cardList[0]->width();
        int tmpH=m_cardList[0]->height();
        int tmpX=ConstNumber::MARGINLONG+((tmpW+ConstNumber::MARGINLONG)*(i%3));
        int tmpY=ConstNumber::MARGINLONG+((tmpH+ConstNumber::MARGINLONG)*(i/3));
        m_cardList[i]->setGeometry(tmpX,tmpY,tmpW,tmpH);

        connect(m_cardList[i],&ClickLabel::cardClicked,[this](Card* card){
            if(this->parentWidget()!=nullptr)
                {
                UIWidget* tmpWidget=(UIWidget*)this->parentWidget();
                for(auto it :tmpWidget->children())
                {
                    UIWidget* pW=(UIWidget*)it;
                    pW->SetCard(card);
                }
            }
        });
    }
    m_viewWidget->adjustSize();
    //--//
    CheckPrinter::GetInstance()->AddCheckWidget(this);
    //--//
}

void CardHubWidget::wheelEvent(QWheelEvent *e)
{
    //竖着
    int delta=e->angleDelta().y();
    m_viewWidget->move(m_viewWidget->x(),m_viewWidget->y()+delta);
    RedoMove();
}

void CardHubWidget::RedoMove()
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
