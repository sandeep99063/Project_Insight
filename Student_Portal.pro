#-------------------------------------------------
#
# Project created by QtCreator 2015-03-09T02:13:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Student_Portal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sign_up.cpp \
    portal.cpp \
    question_view.cpp \
    quest.cpp \
    stud_info.cpp \
    changepass.cpp \
    updates.cpp \
    prof_pre_info.cpp \
    proff_portal.cpp

HEADERS  += mainwindow.h \
    sign_up.h \
    portal.h \
    question_view.h \
    quest.h \
    stud_info.h \
    changepass.h \
    updates.h \
    prof_pre_info.h \
    proff_portal.h

FORMS    += mainwindow.ui \
    sign_up.ui \
    portal.ui \
    question_view.ui \
    quest.ui \
    stud_info.ui \
    changepass.ui \
    updates.ui \
    prof_pre_info.ui \
    proff_portal.ui

RESOURCES += \
    images.qrc
