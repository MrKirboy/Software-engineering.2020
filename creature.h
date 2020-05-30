#ifndef CREATURE_H
#define CREATURE_H

#include <QDialog>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QSound>
#include <QMouseEvent>
#include <QVariantMap>
#include <QDir>
#include <QFont>
#include <QFontDatabase>

#include "creatureclass.h"
#include "creaturelist.h"
#include "json_reader.h"


namespace Ui {
class Creature;
}

class Creature : public QDialog
{
    Q_OBJECT

public:
    explicit Creature(QWidget *parent = nullptr);

    ~Creature();

    void showCreature (int page);
    void showContList ();
    QString makeHyperLink(int, QString);
    QString makeHyperLinkList (QStringList, QString);
    int findCat(QString);
    void uiManager (bool lowestCtg);

private slots:
    void on_enemList_linkActivated(const QString &link);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_subList_linkActivated(const QString &link);

    void on_List_linkActivated(const QString &link);

    void on_swapList_clicked();

    void on_swapRight_clicked();

    void on_swapLeft_clicked();

    void on_swapCat_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Creature *ui;

    QString linker;
    QPoint mpos;
    size_t currentPage, currentUpCat;
    vector<creatureClass> list;

};



#endif // CREATURE_H
