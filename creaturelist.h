#ifndef CREATURELIST_H
#define CREATURELIST_H

#include <vector>
#include <creatureclass.h>
#include <QDebug>

using namespace std;

class creatureList
{
public:
    creatureList ();
    creatureList(QVariantMap json_map);
    creatureList (const creatureList &base);

    vector<creatureClass> getList();

private:
    vector <creatureClass> list;
};

#endif // CREATURELIST_H
