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
    DATA/character.cpp \
    DATA/instructioncontext.cpp \
    DATA/machineinformation.cpp \
    DATA/player.cpp \
    PROTOOL/Instruction/instructionbase.cpp \
    PROTOOL/Instruction/instructionfactory.cpp \
    PROTOOL/Instruction/instructionregister.cpp \
    PROTOOL/cardhub.cpp \
    PROTOOL/characterhub.cpp \
    PROTOOL/jsonreader.cpp \
    PROTOOL/linkmanager.cpp \
    WORKTOOL/checkprinter.cpp \
    WORKTOOL/checktool.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    DATA/card.h \
    DATA/character.h \
    DATA/instructioncontext.h \
    DATA/machineinformation.h \
    DATA/player.h \
    PROTOOL/Instruction/instructionbase.h \
    PROTOOL/Instruction/instructionfactory.h \
    PROTOOL/Instruction/instructionregister.h \
    PROTOOL/cardhub.h \
    PROTOOL/characterhub.h \
    PROTOOL/jsonreader.h \
    PROTOOL/linkmanager.h \
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
