#ifndef CARDHUBWIDGET_H
#define CARDHUBWIDGET_H

#include <QWidget>
#include <QVector>

#include "cardlabel.h"
#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
#include "../DATA/constnumber.h"
class CardHubWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CardHubWidget(QWidget *parent = nullptr);
    void AddLabel(ClickLabel*)override;
    void InitWidget()override;
    void wheelEvent(QWheelEvent* e)override;
    void RedoMove()override;
signals:
private:
    QWidget* m_viewWidget;
    QVector<ClickLabel*> m_cardList;

};

REGISTER_WIDGET(CardHubWidget);
#endif // CARDHUBWIDGET_H
