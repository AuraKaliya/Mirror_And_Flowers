#ifndef ATTRIBUTESHOWWIDGET_H
#define ATTRIBUTESHOWWIDGET_H

#include <QWidget>


#include "uiwidget.h"
#include "clicklabel.h"
#include "../DATA/constnumber.h"
#include "../PROTOOL/widgetregister.h"

class AttributeShowWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit AttributeShowWidget(QWidget *parent = nullptr);
    void SetTitle(QString title)override;
    void InitWidget()override;
    void SetValue(int value)override;
    void UpdateWidgetInfo()override;
signals:
private:
    QString m_linkAttribute;
    int m_attributeValue;
    int m_attributeValueMax;

    QLabel* m_attributeNameLabel;
    QLabel* m_attributeValueLabel;
    QLabel* m_attributeShowLabel;
};

REGISTER_WIDGET(AttributeShowWidget);
#endif // ATTRIBUTESHOWWIDGET_H
