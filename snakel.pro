QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    huarongdao.cpp \
    huarongdaogamepanelwidget.cpp \
    huarongdaolevelselectwidget.cpp \
    main.cpp \
    saolei-item.cpp \
    saolei.cpp \
    saoleidialog.cpp \
    shuerte.cpp \
    shuertegamepanelwidget.cpp \
    shuertelevelselectwidget.cpp \
    snakel.cpp \
    twozerofoureight.cpp

HEADERS += \
    huarongdao.h \
    huarongdaogamepanelwidget.h \
    huarongdaolevelselectwidget.h \
    saolei-item.h \
    saolei.h \
    saoleidialog.h \
    shuerte.h \
    shuertegamepanelwidget.h \
    shuertelevelselectwidget.h \
    snakel.h \
    twozerofoureight.h

FORMS += \
    huarongdao.ui \
    huarongdaolevelselectwidget.ui \
    saolei.ui \
    saoleidialog.ui \
    shuerte.ui \
    shuertelevelselectwidget.ui \
    snakel.ui \
    twozerofoureight.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myimage.qrc

