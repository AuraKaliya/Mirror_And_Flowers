#ifndef ATTRIBUTEEDITWIDGET_H
#define ATTRIBUTEEDITWIDGET_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>

#include "uiwidget.h"
#include "clicklabel.h"
#include "../DATA/constnumber.h"
#include "../PROTOOL/widgetregister.h"

#pragma execution_character_set("utf-8")
class AttributeEditWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit AttributeEditWidget(QWidget *parent = nullptr);

    void SetLinkAttribute(const QString &newLinkAttribute);
    void SetTitle(QString title)override;
    void InitWidget()override;

signals:

private:
    QLineEdit*  m_lineEdit;
    ClickLabel* m_btnLabel;
    QString m_linkAttribute;
};

REGISTER_WIDGET(AttributeEditWidget);
#endif // ATTRIBUTEEDITWIDGET_H
