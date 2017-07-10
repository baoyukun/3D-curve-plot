QT       += core gui opengl printsupport widgets

TARGET = Yukun_BAO
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    myglwidget.cpp \
    qcustomplot.cpp

HEADERS  += widget.h \
    myglwidget.h \
    qcustomplot.h

FORMS    += widget.ui
