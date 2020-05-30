#include "creatureclass.h"

creatureClass::creatureClass()
{
}

creatureClass::creatureClass(QString nameC, int ctgC, QString upctgC, QStringList subctgC,
                             QString descriptionC, QString pictureC, QStringList enemiesC,
                             QStringList feedC, QStringList strsC, QStringList weaksC)
{
    name = nameC;
    ctg = ctgC;
    upctg = upctgC;
    subctg = subctgC ;
    description = descriptionC;
    picture = pictureC;
    enemies = enemiesC;
    feed = feedC;
    strs = strsC;
    weaks = weaksC;
}

creatureClass::creatureClass(const creatureClass &v)
    : name(v.name)
{
    name = v.name;
    ctg = v.ctg;
    upctg = v.upctg;
    subctg = v.subctg ;
    description = v.description;
    picture = v.picture;
    enemies = v.enemies;
    feed = v.feed;
    strs = v.strs;
    weaks = v.weaks;
}

creatureClass::~creatureClass()
{

}

QString creatureClass::getName ()
{
    return name;
}

int creatureClass::getCtg ()
{

    return  ctg;
}

QString creatureClass::getUpCtg()
{
    return upctg;
}

QStringList creatureClass::getSubCtg()
{
    return subctg;
}

QString creatureClass::getDescription ()
{
    return description;
}

QStringList creatureClass::getEnemies ()
{
    return enemies;
}

QStringList creatureClass::getFeed ()
{
    return feed;
}

QStringList creatureClass::getStrs ()
{
    return strs;
}

QStringList creatureClass::getWeaks ()
{
    return weaks;
}

QString creatureClass::getPic()
{
    return picture;
}
