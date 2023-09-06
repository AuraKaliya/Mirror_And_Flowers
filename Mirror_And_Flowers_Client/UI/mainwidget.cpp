#include "mainwidget.h"

MainWidget* MainWidget::m_instance=nullptr;
MainWidget::MainWidget(QWidget *parent)
    : UIWidget{parent}
{
//    QPalette pal(this->palette());
//    pal.setColor(QPalette::Window, Qt::white);
//    setAutoFillBackground(true);
//    setPalette(pal);
}

MainWidget *MainWidget::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new MainWidget();
    }
    return m_instance;

}

void MainWidget::InitWidget(const QJsonObject &obj)
{

}

void MainWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
}

void MainWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
       // painter.setPen(QPen(Qt::white));
        //painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl)));
        painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        //painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }

}

bool MainWidget::IsSingle()
{
    return true;
}
