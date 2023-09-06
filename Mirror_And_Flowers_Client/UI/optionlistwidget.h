#ifndef OPTIONLISTWIDGET_H
#define OPTIONLISTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QLabel>

#include "uiwidget.h"
#include "clicklabel.h"
#include "../DATA/constnumber.h"
#include "../PROTOOL/widgetregister.h"

class OptionListWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit OptionListWidget(QWidget *parent = nullptr);
    void AddLabel(ClickLabel* pLabel)override;
private:
    QVector<ClickLabel*> m_optionLabelList;

signals:

};

REGISTER_WIDGET(OptionListWidget);
#endif // OPTIONLISTWIDGET_H
