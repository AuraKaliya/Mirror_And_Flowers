#include "cardwidget.h"

CardWidget* CardWidget::m_instance=nullptr;
CardWidget *CardWidget::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new CardWidget();
    }
    return m_instance;
}

void CardWidget::InitWidget()
{
    m_linkWidget=new UIWidget(this);
    m_linkWidget->setGeometry(0,700,480,50);

    m_findCardDeckLabel=new ClickLabel(m_linkWidget);
    m_findCardDeckLabel->setGeometry(0,0,480,50);
    m_findCardDeckLabel->setText("查看卡组");
    m_findCardDeckLabel->setAlignment(Qt::AlignCenter);

}

CardWidget::CardWidget(QWidget *parent)
    : UIWidget{parent}
{
    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground);
}
