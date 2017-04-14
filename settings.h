#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QStandardPaths>
#include <QString>
#include <QFile>

#include "config.h"

class settings
{
public:
    settings();

    bool isClear(); // 설정이 없는가
    void defaultSetup(); // 기본 설정으로 되돌리기
    void setVersion(QString version); // 버전을 설정
    QString getVersion(); // 버전을 가져오기
    void setBuildVersion(QString build); // 빌드 버전을 설정
    QString getBuildVersion(); // 빌드 버전을 가져오기

    void setUserComment(QString string); // 미러를 처음 시작할 시 보일 단어
    QString getUserComment(); // 사용자 정의 단어를 가져온다
};

#endif // SETTINGS_H
