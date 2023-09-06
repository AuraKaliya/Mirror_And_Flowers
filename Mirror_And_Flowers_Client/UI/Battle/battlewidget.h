#ifndef BATTLEWIDGET_H
#define BATTLEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QRect>
#include <QTextEdit>
#include <Qpainter>
#include <QMessageBox>
#include "../../PROTOOL/battlemanager.h"
#include "../../PROTOOL/cardhub.h"

#include "../clicklabel.h"
#include "handcardwidget.h"

class BattleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BattleWidget(QWidget *parent = nullptr);
    void BattleStar();
    void UpdateWidgte();
    void paintEvent(QPaintEvent* e) override;

private:
    int m_cardDeckCount;
    int m_timeCount;
    Character* m_Me;
    Character* m_Op;
    QRect m_myHPBorder;
    QRect m_opHPBorder;
    QRect m_myHPNow;
    QRect m_opHPNow;
    QRect m_myCharacterRect;
    QRect m_opCharacterRect;
    QTimer* m_timer;
    ClickLabel* m_timerLabel;
    QRect m_bottomRect;
    QTextEdit* m_talkWidegt;
    handCardWidget* m_handCardWidget;
    QLabel* m_cardDeckLabel;


signals:

};

#endif // BATTLEWIDGET_H
