#include "mirror_main.h"
#include "ui_mirror_main.h"
#include "weather/weather.h"

mirror_main::mirror_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mirror_main)
{
    ui->setupUi(this);

    if(set->isClear())
        set->defaultSetup();

    initUI();
}

mirror_main::~mirror_main()
{
    delete ui;
}

void mirror_main::initUI()
{
    /* Load Fonts */

    /* NanumGothic */

    int nanumgothic_id = QFontDatabase::addApplicationFont(":/fonts/Resources/NanumGothic.otf");
    QString nanumgothic_family = QFontDatabase::applicationFontFamilies(nanumgothic_id).at(0);
    nanumgothic = QFont(nanumgothic_family);

    setFont(nanumgothic);

    /* NanumMyeongjo */

    int nanummyeongjo_id = QFontDatabase::addApplicationFont(":/fonts/Resources/NanumMyeongjo.otf");
    QString nanummyeongjo_family = QFontDatabase::applicationFontFamilies(nanummyeongjo_id).at(0);
    nanummyeongjo = QFont(nanummyeongjo_family);

    /* End Load Fonts */

    /* Initialization UI */

    if(!widget_list.isEmpty())
    {
        delete widget_list.first();
    }

    widget_main = new QWidget(this);
    widget_main->show();
    widget_list.clear();
    widget_list.append(widget_main);

    msg_hello = new QLabel(widget_main);
    msg_hello->setText("\"" + set->getUserComment() + "\"");
    msg_hello->setStyleSheet("font: 50px;");
    msg_hello->setFont(nanummyeongjo);
    msg_hello->setAlignment(Qt::AlignCenter);
    msg_hello->show();

    msg_stt = new QLabel(widget_main);
    msg_stt->setText("Say Hello GUI");
    msg_stt->setStyleSheet("font: 20px;");
    msg_stt->setAlignment(Qt::AlignCenter);
    msg_stt->show();

    msg_time = new QLabel(widget_main);
    msg_time->setText("1월 1일 (월) 00:00 AM");
    msg_time->setStyleSheet("font: 50px;");
    msg_time->show();

    weather_widget = new QWidget(widget_main);
    weather_widget->setStyleSheet("image: url(:/weather/Resources/weather-sunny.png);");
    weather_widget->show();

    msg_weather_location = new QLabel(widget_main);
    msg_weather_location->setText("Seoul");
    msg_weather_location->setStyleSheet("font: 50px;");
    msg_weather_location->setAlignment(Qt::AlignCenter);
    msg_weather_location->show();

    /* End Initialization UI */

    /* Start LocationAPI */

    startLocationAPI();

    refreshUI();
}

void mirror_main::refreshUI()
{
    // Widget

    widget_main->resize(size());

    // Welcome Label

    msg_hello->move(msg_hello->x(),((height() / 2) - msg_hello->height()) / 1.25);
    msg_hello->resize(width(), msg_hello->height());

    // End

    // SST Label

    msg_stt->move(msg_stt->x(),(height() / 2) - msg_stt->height());
    msg_stt->resize(width(), msg_stt->height());

    msg_time->move(width() - msg_time->width(), 0);
    msg_time->resize(labelRefreshSize(msg_time->text().size(), msg_time->font()));

    // Weather Widget

    weather_widget->resize(width() / 7, width() / 7);
    weather_widget->move((width() / 20) / 1.5, (weather_widget->height() / 3) / 1.5);

    msg_weather_location->move((((width() / 20) / 1.5) + weather_widget->width()) * 1.25, weather_widget->height() / 3);
    msg_weather_location->resize(labelRefreshSize(msg_weather_location->text().size(), msg_weather_location->font()));

    // End
}

QSize mirror_main::labelRefreshSize(int size, QFont font)
{
    return QSize(size * (font.pixelSize() / 1.95), font.pixelSize());
}

void mirror_main::resizeEvent(QResizeEvent *event)
{
    refreshUI();
}

void mirror_main::startLocationAPI()
{
 // Obtain the location data source if it is not obtained already
 if (!m_pLocationInfo)
 {
 m_pLocationInfo =
 QGeoPositionInfoSource::createDefaultSource(this);

 //Select positioning method
 m_pLocationInfo->setPreferredPositioningMethods(QGeoPositionInfoSource::NonSatellitePositioningMethods);

 // When the position is changed the positionUpdated function is called
 connect(m_pLocationInfo, SIGNAL (positionUpdated(QGeoPositionInfo)),
 this, SLOT (positionUpdated(QGeoPositionInfo)));

 // Start listening for position updates
 m_pLocationInfo->startUpdates();
 }
}

void mirror_main::positionUpdated(QGeoPositionInfo geoPositionInfo)
{
 if (geoPositionInfo.isValid())
 {
 // Get the current location coordinates
 QGeoCoordinate geoCoordinate = geoPositionInfo.coordinate();
 qreal latitude = geoCoordinate.latitude();
 qreal longitude = geoCoordinate.longitude();

 Weather *darksky = new Weather(0,"f3b5dc74001b4d192f037f78dddc64ca",latitude,longitude);
 Weather *openweathermap = new Weather(1,"f936f868f0796c9a233453edd0bb7c2b",latitude,longitude);
 qDebug() << darksky->temperature() << darksky->weatherDescription() << darksky->weatherIcon() << darksky->dayOfWeek();
 qDebug() << openweathermap->temperature() << openweathermap->weatherDescription() << openweathermap->weatherIcon() << openweathermap->dayOfWeek() << openweathermap->city();
 }
}

QList<QString> mirror_main::getWeather(int latitude, int longitude)
{

}

