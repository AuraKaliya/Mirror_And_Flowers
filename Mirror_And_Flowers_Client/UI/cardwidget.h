#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
#include "clicklabel.h"

class CardWidget : public UIWidget
{
    Q_OBJECT
public:
    static CardWidget* GetInstance();
    void InitWidget()override;

private:
    static CardWidget* m_instance;
    explicit CardWidget(QWidget *parent = nullptr);
    UIWidget* m_linkWidget;
    ClickLabel* m_findCardDeckLabel;

signals:

};
REGISTER_WIDGET_SINGLE(CardWidget);
#endif // CARDWIDGET_H
