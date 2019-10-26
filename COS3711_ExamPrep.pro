#-------------------------------------------------
#
# Project created by QtCreator 2019-09-12T19:41:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COS3711_ExamPrep
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        application/view/mainwindow.cpp \
        application/model/dataentity.cpp \
        application/model/datacollection.cpp \
        infrastructure/utils/datareader.cpp \
        infrastructure/utils/datawriter.cpp \
        application/controller/termdelegate.cpp \
        domain/character/character.cpp \
        domain/environment/environment.cpp \
    application/characterform.cpp

HEADERS += \
        application/view/mainwindow.h \
        application/model/dataentity.h \
        application/model/datacollection.h \
        infrastructure/utils/datareader.h \
        infrastructure/utils/datawriter.h \
        application/controller/termdelegate.h \
        domain/character/character.h \
        domain/environment/environment.h \
    application/characterform.h

FORMS += \
        application/view/mainwindow.ui \
    application/characterform.ui
