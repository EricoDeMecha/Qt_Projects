QT       += core gui printsupport sql
requires(qtConfig(filedialog))
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    record.cpp \
    register.cpp \
    sqlitehandler.cpp

HEADERS += \
    login.h \
    mainwindow.h \
    qcustomplot.h \
    record.h \
    register.h \
    sql.h \
    sqlitehandler.h

FORMS += \
    login.ui \
    mainwindow.ui \
    record.ui \
    register.ui


RC_ICONS = app_icon.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
