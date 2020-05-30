#include "creaturelist.h"

creatureList::creatureList()
{

}

creatureList::creatureList(QVariantMap json_map)
{
    const auto count = json_map.size();
    list.resize(count+1);

    for (int i = 1; i <= count; i++)
    {
        QVariantMap currentMap = json_map[QString::number(i)].toMap();
        QString name = currentMap["Name"].toString();
        int ctg = currentMap["Category"].toInt();
        QString upctgpage = currentMap["Upcategory"].toString();
        QStringList subctgpage = currentMap["Subcategories"].toStringList();
        QString description = currentMap["Description"].toString();
        QString picture = currentMap["Picture"].toString();
        QStringList enemies = currentMap["Enemies"].toStringList();
        QStringList feed = currentMap["Feed"].toStringList();
        QStringList strs = currentMap["Strengths"].toStringList();
        QStringList weaks = currentMap["Weaknesses"].toStringList();
        creatureClass creature(name, ctg, upctgpage, subctgpage, description, picture, enemies, feed, strs, weaks);
        list[i] = creature;
    }
}

creatureList::creatureList(const creatureList &base)
{
    list = base.list;
}

vector<creatureClass> creatureList::getList()
{
    return list;
}
