#-------------------------------------------------
#
# Project created by QtCreator 2018-09-01T11:36:19
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = gallery-core
TEMPLATE = lib

DEFINES += GALLERYCORE_LIBRARY

SOURCES += album.cpp \
    picture.cpp \
    databasemanager.cpp \
    albumdao.cpp \
    picturedao.cpp

HEADERS += album.h\
        gallery-core_global.h \
    picture.h \
    databasemanager.h \
    albumdao.h \
    picturedao.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
