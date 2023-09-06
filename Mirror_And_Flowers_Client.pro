QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += network
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
 QMAKE_CXXFLAGS += -std:c++17 /Zc:__cplusplus
 QMAKE_CXXFLAGS += -std=c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DATA/card.cpp \
    DATA/carddeck.cpp \
    DATA/character.cpp \
    DATA/constnumber.cpp \
    DATA/instructioncontext.cpp \
    DATA/machineinformation.cpp \
    DATA/player.cpp \
    DATA/style.cpp \
    DATA/userinformation.cpp \
    PROTOOL/Instruction/instructionbase.cpp \
    PROTOOL/Instruction/instructionfactory.cpp \
    PROTOOL/Instruction/instructionregister.cpp \
    PROTOOL/Label/labelfactory.cpp \
    PROTOOL/Label/labelregister.cpp \
    PROTOOL/battlemanager.cpp \
    PROTOOL/carddeckhub.cpp \
    PROTOOL/cardhub.cpp \
    PROTOOL/characterhub.cpp \
    PROTOOL/initer.cpp \
    PROTOOL/jsonreader.cpp \
    PROTOOL/linkmanager.cpp \
    PROTOOL/stylemanager.cpp \
    PROTOOL/widgetfactory.cpp \
    PROTOOL/widgetmanager.cpp \
    PROTOOL/widgetregister.cpp \
    UI/Battle/battlewidget.cpp \
    UI/Battle/handcardwidget.cpp \
    UI/attributeeditwidget.cpp \
    UI/attributeshowwidget.cpp \
    UI/carddeckshowwidget.cpp \
    UI/carddeckwidget.cpp \
    UI/cardhubwidget.cpp \
    UI/cardinfowidget.cpp \
    UI/cardlabel.cpp \
    UI/cardwidget.cpp \
    UI/characterinfowidget.cpp \
    UI/charactershowwidget.cpp \
    UI/characterwidget.cpp \
    UI/clicklabel.cpp \
    UI/headwidget.cpp \
    UI/jumplabel.cpp \
    UI/mainwidget.cpp \
    UI/modifywidget.cpp \
    UI/openlabel.cpp \
    UI/optionlistwidget.cpp \
    UI/toolwidget.cpp \
    UI/uiwidget.cpp \
    UI/userinfowidget.cpp \
    UI/viewportwidget.cpp \
    WORKTOOL/checkprinter.cpp \
    WORKTOOL/checktool.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    DATA/card.h \
    DATA/carddeck.h \
    DATA/character.h \
    DATA/constnumber.h \
    DATA/instructioncontext.h \
    DATA/machineinformation.h \
    DATA/player.h \
    DATA/style.h \
    DATA/userinformation.h \
    PROTOOL/Instruction/instructionbase.h \
    PROTOOL/Instruction/instructionfactory.h \
    PROTOOL/Instruction/instructionregister.h \
    PROTOOL/Label/labelfactory.h \
    PROTOOL/Label/labelregister.h \
    PROTOOL/battlemanager.h \
    PROTOOL/carddeckhub.h \
    PROTOOL/cardhub.h \
    PROTOOL/characterhub.h \
    PROTOOL/initer.h \
    PROTOOL/jsonreader.h \
    PROTOOL/linkmanager.h \
    PROTOOL/stylemanager.h \
    PROTOOL/widgetfactory.h \
    PROTOOL/widgetmanager.h \
    PROTOOL/widgetregister.h \
    UI/Battle/battlewidget.h \
    UI/Battle/handcardwidget.h \
    UI/attributeeditwidget.h \
    UI/attributeshowwidget.h \
    UI/carddeckshowwidget.h \
    UI/carddeckwidget.h \
    UI/cardhubwidget.h \
    UI/cardinfowidget.h \
    UI/cardlabel.h \
    UI/cardwidget.h \
    UI/characterinfowidget.h \
    UI/charactershowwidget.h \
    UI/characterwidget.h \
    UI/clicklabel.h \
    UI/headwidget.h \
    UI/jumplabel.h \
    UI/mainwidget.h \
    UI/modifywidget.h \
    UI/openlabel.h \
    UI/optionlistwidget.h \
    UI/toolwidget.h \
    UI/uiwidget.h \
    UI/userinfowidget.h \
    UI/viewportwidget.h \
    WORKTOOL/checkprinter.h \
    WORKTOOL/checktool.h \
    widget.h

FORMS += \
    widget.ui

TRANSLATIONS += \
    Mirror_And_Flowers_Client_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
win32: {
    QMAKE_CXXFLAGS += /permissive-
}

MSVC: {
    QMAKE_CXXFLAGS += /permissive-
}
