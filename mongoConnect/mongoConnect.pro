QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += _ATL_NATIVE_INITIALIZATION
INCLUDEPATH +=  LIBMONGOCXX_INCLUDE_DIR \
                LIBBSONCXX_INCLUDE_DIR \
                /usr/local/include/mongocxx/v_noabi \
                /usr/local/include/bsoncxx/v_noabi \
                /usr/local/include/libmongoc-1.0 \
                /usr/local/include/libbson-1.0 \
                /usr/local/lib


LIBS += LIBMONGOCXX_LIBRARIES \
        LIBBSONCXX_LIBRARIES

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
