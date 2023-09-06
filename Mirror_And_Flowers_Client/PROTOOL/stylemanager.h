#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QVector>
#include <QString>
#include "../UI/clicklabel.h"
#include "../UI/uiwidget.h"
#include "../DATA/style.h"

class StyleManager
{
public:
    static StyleManager* GetInstance();

    void UpdateHeadWidgetStyle();
    void UpdateTitleLabelStyle(Style);
    void SetCloseLabelImage(QString imageUrl);
    void AddCloseLabel(ClickLabel* label);
private:
    static StyleManager* m_instance;
    StyleManager();

    QVector<ClickLabel*>m_closeLabelList;
};

#endif // STYLEMANAGER_H
