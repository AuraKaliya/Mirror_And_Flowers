#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QWidget>
#include <QVector>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
#include "../DATA/constnumber.h"

class ModifyWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ModifyWidget(QWidget *parent = nullptr);
    void AddWidget(UIWidget* pWidget) override;
private:
    QVector<QWidget*>m_modifyOptionList;
signals:

};
REGISTER_WIDGET(ModifyWidget);
#endif // MODIFYWIDGET_H
