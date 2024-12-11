QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += G:\yueqian\QT\QtProject\park_server\Windows_aisound_exp1226_63241576\include

LIBS += -LG:\yueqian\QT\QtProject\park_server\Windows_aisound_exp1226_63241576\bin -lmsc_x64

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tts_offline_sample.c

HEADERS += \
    mainwindow.h \
    tts_offline_sample.h \
    Windows_aisound_exp1226_63241576/include/msp_cmn.h \
    Windows_aisound_exp1226_63241576/include/msp_errors.h \
    Windows_aisound_exp1226_63241576/include/msp_types.h \
    Windows_aisound_exp1226_63241576/include/qtts.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc

RC_FILE += logo.rc

DISTFILES +=
