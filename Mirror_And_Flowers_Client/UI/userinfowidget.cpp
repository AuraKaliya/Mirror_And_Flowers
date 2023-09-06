#include "userinfowidget.h"

UserInfoWidget* UserInfoWidget::m_instance=nullptr;
UserInfoWidget *UserInfoWidget::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new UserInfoWidget();
    }
    return m_instance;
}

void UserInfoWidget::InitWidget(const QJsonObject &obj)
{


}

void UserInfoWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
}

void UserInfoWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
        painter.setPen(QPen(Qt::black));
        painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl)));
        //painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }
}

UserInfoWidget::UserInfoWidget(QWidget *parent)
    : UIWidget{parent}
{
    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground);
}
