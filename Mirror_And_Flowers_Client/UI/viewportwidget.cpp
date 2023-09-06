#include "viewportwidget.h"

#include "../WORKTOOL/checkprinter.h"
ViewPortWidget::ViewPortWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_mousePressed=false;
    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.2);
    setAttribute(Qt::WA_TranslucentBackground);
}

void ViewPortWidget::mouseReleaseEvent(QMouseEvent *e)
{
    m_mousePressed=false;
    RedoMove();
}

void ViewPortWidget::mousePressEvent(QMouseEvent *e)
{

    if(e->button()==Qt::LeftButton)
    {
        m_mousePressed=true;
        QPointF startPoint=e->globalPosition();
        m_widthDistance=startPoint.x()-this->x();

    }

}

void ViewPortWidget::mouseMoveEvent(QMouseEvent *e)
{
    //拖拽
    if(m_mousePressed)
    {
        QPoint desPoint(e->globalPosition().x()-m_widthDistance,this->y());
        move(desPoint);
    }
    //随鼠标移动
    if(m_heightGap!=0)
    {
        double centreY=this->height()/2+this->pos().y();
        double  yMoveFactor=((centreY-e->globalPosition().y())/(m_heightRestriction/2.0))+1.0;
        if(yMoveFactor>2.0)
        {
            yMoveFactor=2.0;
        }
        else if(yMoveFactor<0)
        {
            yMoveFactor=0;
        }
        for(auto it:m_characterShowWidgetList)
        {
            it->move(it->x(),((this->height()-it->height())/2)*(2-yMoveFactor));
        }
    }
}

void ViewPortWidget::InitWidget()
{
    setMouseTracking(true);
    if(m_characterShowWidgetList.size()>0)
    {
        m_heightGap=this->height()-m_characterShowWidgetList[0]->height();
        //qDebug()<<"---------=-----------"<<m_heightGap;
        resize((ConstNumber::MARGINMIDDLE)*(2+m_characterShowWidgetList.size())+(m_characterShowWidgetList.size()*m_characterShowWidgetList[0]->width()),this->height());
        setGeometry(0,50,this->size().width(),this->size().height());
        for(int i=0;i<m_characterShowWidgetList.size();++i)
        {
            m_characterShowWidgetList[i]->move(
                           (i)*(ConstNumber::MARGINMIDDLE+m_characterShowWidgetList[i]->width()),
                             ConstNumber::MARGINSMALL);
            m_characterShowWidgetList[i]->InitWidget();
        }
    }
    else
    {
        m_heightGap=0;
    }
    m_heightRestriction=this->height();

    //--//
    CheckPrinter::GetInstance()->AddCheckWidget(this);
    //--//
}

void ViewPortWidget::AddWidget(UIWidget *pWidget)
{
    pWidget->setParent(this);
    m_characterShowWidgetList.append(pWidget);
    connect(pWidget,&UIWidget::RectChanged,[this](){

        RedoLayout();
    });
    connect(pWidget,&UIWidget::CharacterChoiced,this,[=](Character* character){
        //qDebug()<<"Character:"<<character;
        m_nowCharacter=character;
        emit UIWidget::CharacterChoiced(m_nowCharacter);
            });


    pWidget->setVisible(true);
}

void ViewPortWidget::SetRestriction(int restriction)
{
    m_heightRestriction=restriction;
}

void ViewPortWidget::RedoLayout()
{

    int tmpWidth=0;
    for(auto it:m_characterShowWidgetList)
    {
        tmpWidth+=it->width();
    }
    //qDebug()<<tmpWidth;
    resize((ConstNumber::MARGINMIDDLE)*(2+m_characterShowWidgetList.size())+(tmpWidth),this->height());
    for(int i=1;i<m_characterShowWidgetList.size();++i)
    {
        m_characterShowWidgetList[i]->move(
            ConstNumber::MARGINMIDDLE+m_characterShowWidgetList[i-1]->x()+m_characterShowWidgetList[i-1]->width(),
            ConstNumber::MARGINSMALL);

    }


}

void ViewPortWidget::RedoMove()
{
    int nowX=this->x();
    int nowWidth=this->width();
    int leftLimit=this->parentWidget()->width();
    if((nowX+nowWidth)<leftLimit)
    {
        move(leftLimit-nowWidth,this->y());
    }else if(nowX>0)
    {
        move(0,this->y());
    }


}
