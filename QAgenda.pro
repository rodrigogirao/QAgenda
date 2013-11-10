#-------------------------------------------------
#
# Project created by QtCreator 2013-10-10T09:27:15
#
#-------------------------------------------------

QT       += core gui
QT  +=quick-private
QT       += core gui declarative
QML2_IMPORT_PATH =/opt/qt5/imports

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAgenda
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addcontatodialog.cpp \
    dialogmensage.cpp \
    visualizarlog.cpp \
    decorartabelaimagem.cpp \
    progessbardelagate.cpp \
    decorartabeladelagate.cpp

HEADERS  += mainwindow.h \
    addcontatodialog.h \
    dialogmensage.h \
    visualizarlog.h \
    decorartabelaimagem.h \
    progessbardelagate.h \
    decorartabeladelagate.h

FORMS    += mainwindow.ui \
    addcontatodialog.ui \
    dialogmensage.ui \
    visualizarlog.ui

RESOURCES += \
    icones.qrc

OTHER_FILES += \
    ui.qml
