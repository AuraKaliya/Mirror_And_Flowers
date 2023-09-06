#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPainter>

#include "../WORKTOOL/checkprinter.h"
#include "../PROTOOL/characterhub.h"
#include "../PROTOOL/cardhub.h"

#pragma execution_character_set("utf-8")
class QLabel;
class ClickLabel;

class AttributeShowWidget;
class UIWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UIWidget(QWidget *parent = nullptr);

    virtual void InitWidget(const QJsonObject &obj){};
    virtual void InitWidget(){};
    virtual void SetBackgroundPixUrl(QString pixUrl);
    virtual void SetLabelPixUrl(QString pixUrl){};
    virtual void SetStyle(QString styleSheetStr);
    virtual void SetTitle(QString title){};
    virtual void SetRect(QRect rect);
    virtual void SetSize(QSize size);
    virtual void SetCard(Card*card){};
    virtual void SetValue(int value){};
    virtual void SetMask(QString mask){};
    virtual void SetRestriction(int restriction){};
    virtual void SetLinkCharacter(Character* character){};
    virtual void AddLabel(QLabel* pLabel){};
    virtual void AddWidget(QWidget* pWidget){};
    virtual void AddWidget(UIWidget* pWidget){};
    virtual void AddWidget(AttributeShowWidget* pWidget){};
    virtual void AddLabel(ClickLabel* pLabel){};
    virtual void UpdateUserInfo(QString headImageUrl,QString userName,QString userIP){};
    virtual void UpdateWidgetInfo(){};
    virtual bool IsSingle();
    virtual void RedoMove(){};
    void paintEvent(QPaintEvent* e)override;
signals:
    //AttributeEditWidget
    void AttributeChanged(QString);

    //CharacterShowWidget
    void WidgetIndex(int index);
    void CharacterChoiced(Character*);
    void CharacterClicked();
    void RectChanged();
protected:
    QString m_backgroundPixUrl;
};

#endif // UIWIDGET_H
