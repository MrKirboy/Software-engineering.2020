#ifndef CRETURECLASS_H
#define CRETURECLASS_H

#include <QString>
#include <QList>
//#include <QStringList>


class creatureClass
{
public:
    creatureClass();
    creatureClass(QString nameC, int ctgC, QString upctgC, QStringList subctgC,
                 QString descriptionC, QString pictureC, QStringList enemiesC,
                 QStringList feedC, QStringList strsC, QStringList weaksC);
    creatureClass(const creatureClass &v);

    ~creatureClass ();

    QString getName ();
    int getCtg ();
    QString getUpCtg();
    QStringList getSubCtg();
    QString getDescription ();
    QStringList getEnemies ();
    QStringList getFeed ();
    QStringList getStrs ();
    QStringList getWeaks ();
    QString getPic();

private:
    QString name = "";
    int ctg = 0;
    QString upctg = "";
    QString description = "";
    QString picture = "";

    QStringList subctg;
    QStringList enemies;
    QStringList feed;
    QStringList strs;
    QStringList weaks;
};

#endif // CRETURECLASS_H
