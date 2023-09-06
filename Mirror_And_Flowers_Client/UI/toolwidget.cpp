#include "toolwidget.h"

ToolWidget::ToolWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_isPressed=false;

    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground);
}

void ToolWidget::mouseReleaseEvent(QMouseEvent *e)
{

    m_isPressed=false;
}

void ToolWidget::mousePressEvent(QMouseEvent *e)
{

    if(e->button()==Qt::LeftButton)
    {
        m_isPressed=true;
        m_starPoint=e->globalPosition();
        if(this->parent()!=nullptr)
        {
            m_distancePoint=this->parentWidget()->pos()-m_starPoint;
        }
    }
}

void ToolWidget::mouseMoveEvent(QMouseEvent *e)
{

    if(m_isPressed)
    {
        m_starPoint=e->globalPosition();
        if(this->parent()!=nullptr)
        {
            this->parentWidget()->move(m_starPoint.x()+m_distancePoint.x(),m_starPoint.y()+m_distancePoint.y());
        }
    }
}

void ToolWidget::InitWidget()
{
    QRect rect=this->geometry();
    ClickLabel * closeLabel=new ClickLabel(this);
    closeLabel->setGeometry(rect.width()-ConstNumber::MARGINSMALL-ConstNumber::R30,
                            ConstNumber::MARGINSMALL,
                            ConstNumber::R30,
                            ConstNumber::R30);
    StyleManager::GetInstance()->AddCloseLabel(closeLabel);
    if(this->parent()!=nullptr)
    {
        connect(closeLabel,&ClickLabel::clicked,(QWidget*)this->parent(),&QWidget::hide);
    }else
    {
        qDebug()<<"工具栏-未装载在窗体中";
    }
}

void ToolWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
    //setStyleSheet(this->styleSheet()+QString("border-image:url("+m_backgroundPixUrl+");"));
}

void ToolWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
        painter.setPen(QPen(Qt::white));
        painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl).scaled(QSize(1400,50))));
        //painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }
}
