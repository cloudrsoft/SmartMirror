#ifndef MIRROR_MAIN_H
#define MIRROR_MAIN_H

#include <QMainWindow>
#include <QLabel>
#include <QtWidgets>
#include <QList>
#include <QDesktopWidget>
#include <QResizeEvent>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>
#include <QDebug>

#include <QFontDatabase>

#include "settings.h"

namespace Ui {
class mirror_main;
}

class mirror_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit mirror_main(QWidget *parent = 0);
    ~mirror_main();

private slots:
    void initUI(); // initUI

    void refreshUI(); // refreshUI

    void resizeEvent(QResizeEvent* event);

    void positionUpdated(QGeoPositionInfo geoPositionInfo);

    void startLocationAPI();

    QSize labelRefreshSize(int size, QFont font);

    QList<QString> getWeather(int latitude, int longitude);

private:
    Ui::mirror_main *ui;

    QGeoPositionInfoSource* m_pLocationInfo;

    QList<QWidget*> widget_list;

    QFont nanumgothic;
    QFont nanummyeongjo;

    /* Widgets */

    QWidget *widget_main;
    QLabel *msg_hello; // Welcome Label
    QLabel *msg_stt; // STT Label
    QLabel *msg_time; // Time Label

    // Weather

    QLabel *msg_weather_location; // Weather Temp Label
    QWidget *weather_widget; // Weather Widget

    settings *set = new settings;
};

#endif // MIRROR_MAIN_H
