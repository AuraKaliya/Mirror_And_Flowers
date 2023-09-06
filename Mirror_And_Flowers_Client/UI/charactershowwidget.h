#ifndef CHARACTERSHOWWIDGET_H
#define CHARACTERSHOWWIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
//#include <QParallelAnimationGroup>

#include "clicklabel.h"
#include "uiwidget.h"
#include "characterinfowidget.h"
#include "../PROTOOL/widgetregister.h"
#include "PROTOOL/characterhub.h"
#include "attributeshowwidget.h"
class CharacterShowWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CharacterShowWidget(QWidget *parent = nullptr);
    void SetLinkCharacter(Character* character)override;
    void SetSize(QSize normalSize)override;
    void InitWidget()override;

signals:

private:
    ClickLabel* m_tachieLabel;
    CharacterInfoWidget* m_infoWidget;

    Character* m_linkCharacter;
    QSize m_normalSize;
    QSize m_expandSize;
    bool m_nowState;
    int m_widgetIndex;
};
REGISTER_WIDGET(CharacterShowWidget);
#endif // CHARACTERSHOWWIDGET_H
