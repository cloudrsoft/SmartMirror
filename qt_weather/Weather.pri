TEMPLATE = lib

QT += core network

SOURCES += weather/darksky_weather.cpp \
    weather/weather.cpp \
    weather/openweathermap_weather.cpp

HEADERS  += weather/darksky_weather.h \
    weather/weather.h \
    weather/openweathermap_weather.h
