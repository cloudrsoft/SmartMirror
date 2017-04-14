#-------------------------------------------------
#
# Project created by QtCreator 2016-11-19T20:43:34
#
#-------------------------------------------------

QT       += core gui network positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartMirror
TEMPLATE = app

SOURCES += main.cpp\
        mirror_main.cpp \
    weather/darksky_weather.cpp \
    weather/weather.cpp \
    weather/openweathermap_weather.cpp \
    settings.cpp

HEADERS  += mirror_main.h \
    weather/darksky_weather.h \
    weather/weather.h \
    weather/openweathermap_weather.h \
    settings.h \
    config.h

FORMS    += mirror_main.ui

RESOURCES += \
    resources.qrc
