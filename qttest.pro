#-------------------------------------------------
#
# Project created by QtCreator 2017-07-11T23:24:44
#
#-------------------------------------------------

QT += core gui sql xml
QT += core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qttest
TEMPLATE = app

CONFIG += C++11
CONFIG += C++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QWT_DLL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#INCLUDEPATH += /home/tands/prjs/libtest
INCLUDEPATH += $$PWD/qwt/src

SOURCES += \
    main.cpp \
#    cppstd/concurrency/async1.cpp \
#    cppstd/concurrency/async3.cpp \
#    cppstd/concurrency/promise1.cpp \
    mainwindow.cpp \
    testcases.cpp \
    teststd.cpp \
#    plot/CurvePlot.cpp \    templatetest.cpp \
    boosttest.cpp \
    threadtest.cpp \
    ClassA.cpp \
    CodeSegment.cpp \
    qttest.cpp

HEADERS  += mainwindow.h \
    testcases.h \
    teststd.h \
    ComplieTime.h \
#    plot/CurvePlot.h \    templatetest.h \
    ArrayPtr.h \
    boosttest.h \
    threadtest.h \
    ClassA.h \
    CodeSegment.h \
    qttest.h \
    UtilsDef.h

FORMS    += mainwindow.ui

LIBS += -L$$PWD/lib/mingw
CONFIG(debug, debug|release) {
    #LIBS += -lqwtd
    #LIBS += -llibqwtd
}
else {
    #LIBS += -lqwt
    #LIBS += -llibqwt
}

#LIBS += -L/home/tands/prjs/build-libtest-Desktop-Debug -llibtest
