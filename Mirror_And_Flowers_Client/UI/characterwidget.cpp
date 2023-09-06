#include "characterwidget.h"

CharacterWidget * CharacterWidget::m_instance=nullptr;
CharacterWidget *CharacterWidget::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new CharacterWidget();
    }
    return m_instance;
}

void CharacterWidget::InitWidget()
{

}

void CharacterWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
}

void CharacterWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
        painter.setPen(QPen(Qt::white));
        painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl)));
        //painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }
}

CharacterWidget::CharacterWidget(QWidget *parent)
    : UIWidget{parent}
{

    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground);
}
