#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include <QObject>
#include <QPushButton>
#include "WORKTOOL/checkprinter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Mirror_And_Flowers_Client_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Widget w;
    w.show();


//    QWidget* ww=new QWidget();
//    QPushButton * btn=new QPushButton(ww);
//    btn->setGeometry(0,0,100,50);
//    QObject::connect(btn,&QPushButton::clicked,[=](){
//        CheckPrinter::GetInstance()->SoluteCheckWidgets();
//    });
//    ww->adjustSize();
//    ww->show();



    return a.exec();
}
