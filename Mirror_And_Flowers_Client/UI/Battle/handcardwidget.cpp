#include "handcardwidget.h"

handCardWidget::handCardWidget(QWidget *parent)
    : QWidget{parent}
{
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(palette);
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("background:white;");

    m_choiced=true;
    m_smallState=QRect(450,575,800,325);
    m_largeState=QRect(200,100,1200,700);
    m_smallCardSize=QSize(170,300);
    m_largeCardSize=QSize(170,300);

    infoLabel=new QLabel(this);
    infoLabel->setGeometry(450,500,300,100);

    m_yesButton=new QPushButton("使用",this);
    m_yesButton->setGeometry(500,625,75,50);
    m_noButton=new QPushButton("取消",this);
    m_noButton->setGeometry(625,625,75,50);

    connect(m_yesButton,&QPushButton::clicked,[=](){
        if(m_nowCard!=nullptr){
            emit cardUsed(m_nowCard);
            m_nowCard=nullptr;
            infoLabel->setText("");
        }
    });

    connect(m_noButton,&QPushButton::clicked,[=](){

            m_nowCard=nullptr;
            infoLabel->setText("");
            SetSmallState();
    });

    m_yesButton->setVisible(false);
    m_noButton->setVisible(false);
    SetSmallState();
}

void handCardWidget::SetSmallState()
{
    if(m_choiced==false) return;
    m_choiced=false;
    setGeometry(m_smallState);
    m_yesButton->setVisible(false);
    m_noButton->setVisible(false);
    ResetHandCard();

}

void handCardWidget::SetLargeState()
{
    if(m_choiced==true) return;

    m_choiced=true;
    setGeometry(m_largeState);
    m_yesButton->setVisible(true);
    m_noButton->setVisible(true);
    SortHandCard();

    update();
}

void handCardWidget::ResetHandCard()
{
    //450,575,800,325   --170,300

    for(auto it:m_proxyGroup)
    {
        it->resetTransform();
        it->setWidget(this);

    }
    for(auto it:m_proxyGroup) m_proxyGroup.pop_front();

    for(auto it :m_sceneGroup) it->deleteLater();
    for(auto it:m_sceneGroup) m_sceneGroup.pop_front();

    for(auto it : m_viewGroup) it->deleteLater();
    for(auto it: m_viewGroup)  m_viewGroup.pop_front();

    for(int i=0;i<m_handCard.size();i++)
    {

        m_handCard[i]->setParent(this);
        m_handCard[i]->resize(m_smallCardSize);
        m_handCard[i]->move(100+50*i,10);
        m_handCard[i]->raise();
        m_handCard[i]->setVisible(true);

    }




}

void handCardWidget::SortHandCard()
{


    m_scene=new QGraphicsScene(this);
    m_view= new QGraphicsView(m_scene,this);

    QPoint O(m_largeState.width()/2,m_largeState.height());

    int R=300;

    for(auto it:m_handCard)
    {
        it->move(0,0);
        it->resize(m_largeCardSize.width(),m_largeCardSize.height());
        it->setParent(nullptr);
    }
      //考虑做成一个动画

    for(int i=0;i<m_handCard.size();i++)
    {


        QGraphicsProxyWidget* tmpProxy=m_scene->addWidget(m_handCard[i]);
        QPointF tmpPoint(m_largeCardSize.width()/2,m_largeCardSize.height()+R);


        tmpProxy->setTransformOriginPoint(tmpPoint);
        if(m_handCard.size()>1)
        {
            tmpProxy->setRotation(-75+((150*i)/(m_handCard.size()>0?m_handCard.size():1)));
            m_handCard[i]->move(O.x()-m_largeCardSize.width()/2,O.y()-R-m_largeCardSize.height());

        }
        else
        {
           tmpProxy->setRotation(0);
           m_view->move(O.x()-m_largeCardSize.width()/2,O.y()-R-m_largeCardSize.height());

        }


        tmpProxy->setVisible(true);
        m_proxyGroup.append(tmpProxy);

    }

    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setWindowOpacity(0);
    m_view->setStyleSheet("background:transparent;border:0px;");
    m_view->setWindowFlags(Qt::FramelessWindowHint);
    m_view->setVisible(true);

    m_sceneGroup.append(m_scene);
    m_viewGroup.append(m_view);
}

void handCardWidget::UpdateHandCard(QVector<Card *> handCard)
{
    for(auto it:m_handCard)
    {
        it->deleteLater();
        m_handCard.pop_front();
    }
    m_handCard.clear();

    for(auto it:handCard)
    {
        CardLabel* tmp = new CardLabel(this);
        tmp->SetCard(it);
        tmp->resize(m_smallCardSize);
        tmp->SetImage(it->GetImageUrl());
        m_handCard.append(tmp);
        connect(tmp,&CardLabel::cardClicked,[=](Card* card){
            UpdateNowCard(card);
        });
    }
    ResetHandCard();
}


void handCardWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        if(m_choiced==false)
        {
            SetLargeState();
        }
    }
}

void handCardWidget::UpdateNowCard(Card* card)
{
    m_nowCard=card;
    QString str="[";
    str+=m_nowCard->GetName();
    str+="] ";
    str+=m_nowCard->GetCategory();
    str+=" ATK:";
    str+=QString::number(m_nowCard->GetATK());
    str+=" DEF:";
    str+=QString::number(m_nowCard->GetDEF());
    str+=" DHP:";
    str+=QString::number(m_nowCard->GetDHP());
    infoLabel->setText(str);

}
