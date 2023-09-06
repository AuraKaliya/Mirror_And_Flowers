#ifndef CHARACTERINFOWIDGET_H
#define CHARACTERINFOWIDGET_H

#include <QWidget>
#include <QVector>


#include "uiwidget.h"

#include "../PROTOOL/widgetregister.h"
#include "attributeshowwidget.h"
class CharacterInfoWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CharacterInfoWidget(QWidget *parent = nullptr);
    void AddWidget(AttributeShowWidget* pWidget)override;
    void InitWidget()override;


    void SetCharacterName(const QString &newCharacterName);
    void SetCharacterTitle(const QString &newCharacterTitle);
    void SetCharacterIntroduction(const QString &newCharacterIntroduction);
    void wheelEvent(QWheelEvent* e)override;
signals:
private:
    QString m_characterName;
    QString m_characterTitle;
    QString m_characterIntroduction;
    QLabel* m_nameLabel;
    QLabel* m_titleLabel;
    QLabel* m_introductionLabel;
    QVector<AttributeShowWidget*>m_attributeShowWidgetList;
};

REGISTER_WIDGET(CharacterInfoWidget);
#endif // CHARACTERINFOWIDGET_H
