#include "settings.h"

QSettings set("SmartMirror", "settings");

settings::settings()
{

}

/* Program */

bool settings::isClear()
{
    bool temp;

    if(getVersion().isNull())
        temp = true;
    else
        temp = false;

    return temp;
}

void settings::defaultSetup()
{
    QFile file(":/text/Resources/defaultUserComment");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    setVersion(VERSION);
    setBuildVersion(BUILD_VERSION);
    setUserComment(file.readAll());

    file.close();
}

void settings::setVersion(QString version)
{
    set.beginGroup("main");
    set.setValue("Version", version);
    set.endGroup();
}

QString settings::getVersion()
{
    QString temp;

    set.beginGroup("main");
    temp = set.value("Version").toString();
    set.endGroup();

    return temp;
}

void settings::setBuildVersion(QString build)
{
    set.beginGroup("main");
    set.setValue("BuildVersion", build);
    set.endGroup();
}

QString settings::getBuildVersion()
{
    QString temp;

    set.beginGroup("main");
    temp = set.value("BuildVersion").toString();
    set.endGroup();

    return temp;
}

/* End Program */

/* Main UI */

void settings::setUserComment(QString string)
{
    set.beginGroup("main");
    set.setValue("UserComment", string);
    set.endGroup();
}

QString settings::getUserComment()
{
    QString temp;

    set.beginGroup("main");
    temp = set.value("UserComment").toString();
    set.endGroup();

    return temp;
}

/* End Main UI */
