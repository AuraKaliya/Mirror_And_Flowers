#include "carddeckshowwidget.h"

CardDeckShowWidget::CardDeckShowWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_cardsNumberLabel=new QLabel(this);
}

void CardDeckShowWidget::InitWidget()
{

    m_cardDeckMe=CardDeckHub::GetInstance()->GetCardDeckByName("Me");
    InitCardWidget();

}

void CardDeckShowWidget::InitCardWidget()
{
    m_cardsNumberLabel->setGeometry(
        ConstNumber::MARGINSMALL,
        ConstNumber::MARGINSMALL,
        this->width()- ConstNumber::MARGINSMALL*2,
        ConstNumber::HEIGHTSMALL
        );

    int tmpWidth=this->width();
    for(int i=0;i<m_cardDeckMe->GetContains().size();++i)
    {
        QWidget* tmpWidget=new QWidget(this);

        m_cardWidget.append(tmpWidget);
        tmpWidget->setGeometry(
            (0.2*tmpWidth/3)+(i%2)*(0.4*tmpWidth+0.2*tmpWidth/3),
            (i/2+1)*(ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL)+(i/2)*ConstNumber::MARGINSMALL,
              0.4*tmpWidth,
            ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL
            );


        QLabel* tmpLabel=new QLabel(tmpWidget);
        tmpLabel->setGeometry(ConstNumber::MARGINSMALL,
                               ConstNumber::MARGINSMALL,
                              ConstNumber::HEIGHTSMALL,
                              ConstNumber::HEIGHTSMALL);

        QString tmpStr=CardHub::GetInstance()->GetCardByID(m_cardDeckMe->GetContains()[i].toInt())->GetCategory();
        if(tmpStr=="Equipment")
        {
            tmpStr="武";
        }
        else
        {
            tmpStr="道";
        }
        tmpLabel->setText(tmpStr);

        QLabel * tmpLabel2=new QLabel(tmpWidget);
        tmpLabel2->setGeometry( ConstNumber::MARGINSMALL*2+ConstNumber::HEIGHTSMALL,
                                   ConstNumber::MARGINSMALL,
                                 tmpWidth*0.2,
                                ConstNumber::HEIGHTSMALL
                                  );
        tmpStr=CardHub::GetInstance()->GetCardByID(m_cardDeckMe->GetContains()[i].toInt())->GetName();
        tmpLabel2->setText(tmpStr);



        ClickLabel* tmpLabel3=new ClickLabel(tmpWidget);

        tmpLabel3->setGeometry( ConstNumber::MARGINSMALL*3+ConstNumber::HEIGHTSMALL+ tmpWidth*0.2,
                               ConstNumber::MARGINSMALL,
                               ConstNumber::HEIGHTSMALL,
                               ConstNumber::HEIGHTSMALL
                               );

        connect(tmpLabel3,&ClickLabel::me,[=](ClickLabel* label){
            m_cardDeckMe->DeleteCard(CardHub::GetInstance()->GetCardByName(tmpStr)->GetID());
            m_cardWidget.removeOne(label->parentWidget());
            delete label->parentWidget();
            RedoMove();
        });


    }
}

void CardDeckShowWidget::RedoMove()
{
    int tmpWidth=this->width();
    for(int i=0;i<m_cardWidget.size();++i)
    {
        QWidget* tmpWidget=m_cardWidget[i];

        tmpWidget->setGeometry(
            (0.2*tmpWidth/3)+(i%2)*(0.4*tmpWidth+0.2*tmpWidth/3),
            (i/2+1)*(ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL)+(i/2)*ConstNumber::MARGINSMALL,
            0.4*tmpWidth,
            ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL
            );
    }

    m_cardsNumberLabel->setText(QString::number(m_cardWidget.size())+"/"+QString::number(CardDeck::CARDNUMBER));

}
