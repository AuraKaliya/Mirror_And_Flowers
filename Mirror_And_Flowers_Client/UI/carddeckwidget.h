#ifndef CARDDECKWIDGET_H
#define CARDDECKWIDGET_H

#include <QWidget>
#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"

class CardDeckWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CardDeckWidget(QWidget *parent = nullptr);
    void InitWidget()override;
signals:

};

#endif // CARDDECKWIDGET_H
