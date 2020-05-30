#ifndef JSON_READER_H
#define JSON_READER_H
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>


class JSON_reader
{
public:
    JSON_reader(QString linker);

    QVariantMap getMap();

private:
    QVariantMap json_map;
};

#endif // JSON_READER_H
