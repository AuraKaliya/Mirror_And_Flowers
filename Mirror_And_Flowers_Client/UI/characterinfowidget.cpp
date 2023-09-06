#include "characterinfowidget.h"

CharacterInfoWidget::CharacterInfoWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_nameLabel=new QLabel(this);
    m_nameLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel=new QLabel(this);
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_introductionLabel=new QLabel(this);
    m_introductionLabel->setWordWrap(true);
}

void CharacterInfoWidget::AddWidget(AttributeShowWidget* pWidget)
{
    pWidget->setParent(this);
    m_attributeShowWidgetList.append(pWidget);
    pWidget->setVisible(true);
}

void CharacterInfoWidget::InitWidget()
{
    QRect rect=geometry();
    m_nameLabel->setText(m_characterName);
    m_nameLabel->setStyleSheet(m_nameLabel->styleSheet()+QString("font-size:20px;"));
    m_titleLabel->setText(m_characterTitle);
    m_titleLabel->setStyleSheet(m_titleLabel->styleSheet()+QString("font-size:18px;"));
    m_introductionLabel->setText(m_characterIntroduction);
    m_introductionLabel->setStyleSheet(m_introductionLabel->styleSheet()+QString("font-size:20px;"));
    m_introductionLabel->setFixedWidth(rect.width()-2*ConstNumber::MARGINSMALL);
    m_introductionLabel->adjustSize();

    m_nameLabel->setGeometry(ConstNumber::MARGINSMALL*2,
                             ConstNumber::MARGINSMALL,
                             rect.width()*0.3,
                             ConstNumber::HEIGHTSMALL
                            );
    m_titleLabel->setGeometry(rect.width()*0.6-ConstNumber::MARGINSMALL*2,
                             ConstNumber::MARGINSMALL,
                             rect.width()*0.4,
                             ConstNumber::HEIGHTSMALL
                             );

    for(int i=0;i<m_attributeShowWidgetList.size();++i)
    {
        m_attributeShowWidgetList[i]->setGeometry(ConstNumber::MARGINSMALL,
                                                  ((ConstNumber::MARGINSMALL*3+ConstNumber::HEIGHTSMALL)*(i+1)),
                                                  rect.width()-2*ConstNumber::MARGINSMALL,
                                                  ConstNumber::HEIGHTSMALL+2*ConstNumber::MARGINSMALL
                                                );
        m_attributeShowWidgetList[i]->InitWidget();
    }
    m_introductionLabel->move(
                                ConstNumber::MARGINSMALL,
                              ((ConstNumber::MARGINSMALL*3+ConstNumber::HEIGHTSMALL)*(m_attributeShowWidgetList.size()+1))
                                     );
    adjustSize();
    resize(m_introductionLabel->width()+2*ConstNumber::MARGINSMALL,this->height());

}

void CharacterInfoWidget::SetCharacterName(const QString &newCharacterName)
{
    m_characterName = newCharacterName;
}

void CharacterInfoWidget::SetCharacterTitle(const QString &newCharacterTitle)
{
    m_characterTitle = newCharacterTitle;
}

void CharacterInfoWidget::SetCharacterIntroduction(const QString &newCharacterIntroduction)
{
    m_characterIntroduction = newCharacterIntroduction;
}

void CharacterInfoWidget::wheelEvent(QWheelEvent *e)
{
    int delta=e->angleDelta().y();
    move(this->x(),this->y()+delta);
}
