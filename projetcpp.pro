QT       += core gui
QT       += core gui charts
QT       += core network
QT       += core network networkauth
QT       += network
QT       +=sql
QT       +=serialport
QT       +=multimedia

LIBS += -LC:/OpenSSL-Win64/bin
LIBS += -LC:/OpenSSL-Win64/lib -llibssl -llibcrypto
INCLUDEPATH += C:/OpenSSL-Win64/include/openssl

#LIBS += -LC:/OpenSSL-Win64/bin
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11
TARGET = plotting
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnementcode.cpp \
    agent.cpp \
    cartesolde.cpp \
    client.cpp \
    coli.cpp \
    conge2.cpp \
    connexion.cpp \
    courrier.cpp \
    login.cpp \
    mailing.cpp \
    main.cpp \
    mainwindow.cpp \
    moral.cpp \
    parkingcode.cpp \
    physique.cpp \
    qcustomplot.cpp \
    smtp.cpp \
    stat_no.cpp \
    statistique.cpp

HEADERS += \
    abonnementcode.h \
    agent.h \
    cartesolde.h \
    client.h \
    coli.h \
    conge2.h \
    connexion.h \
    courrier.h \
    login.h \
    mailing.h \
    mainwindow.h \
    moral.h \
    parkingcode.h \
    physique.h \
    qcustomplot.h \
    smtp.h \
    stat_no.h \
    statistique.h

FORMS += \
    login.ui \
    mailing.ui \
    mainwindow.ui \
    stat_no.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/print.jpg \
    img/unnamed.png

RESOURCES += \
    res.qrc
