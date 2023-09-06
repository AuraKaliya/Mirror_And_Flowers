#ifndef STYLE_H
#define STYLE_H

#include <QObject>
#include <QString>
#
class Style
{
public:
    Style();
    void InitStyle(const QJsonObject &obj);
    QString GetStyle();
private:
    QString m_styleName;
    QString m_styleSheet;
//    QString m_textFont;
//    QString m_textAligent;
//    QString m_textColor;
//    QString m_widgetBackground;
//    QString m_showLabelTextAligent;
//    QString m_tshowLabelTextColor;
};

#endif // STYLE_H
