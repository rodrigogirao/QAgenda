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
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/AndroidManifest.xml \
    android/version.xml \
    android/res/layout/splash.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-et/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-nb/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-es/strings.xml
