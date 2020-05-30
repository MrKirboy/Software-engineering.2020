#include "creature.h"
#include "ui_creature.h"
#include "creatureclass.h"
#include "creaturelist.h"

Creature::Creature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Creature)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/fonts/baseFont5.ttf");
    QFont titleFont("Beyond Wonderland", 45);
    QFont fancyFont("Beyond Wonderland", 33);
    QFont baseFont("Beyond Wonderland", 18);

    this->setFont(baseFont);
    ui->name->setFont(titleFont);
    ui->subList->setFont(fancyFont);
    ui->subTitle->setFont(fancyFont);

    ui->enemList->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    ui->enemList->setTextFormat(Qt::RichText);
    ui->enemList->setOpenExternalLinks(false);

    ui->description->setWordWrap(true);

    this->setWindowFlag(Qt::FramelessWindowHint);

    QPixmap bkgnd(":/images/Others/Back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    if (!QDir(QDir::currentPath() + "/Sounds").exists())
    {
        QDir().mkdir(QDir::currentPath() + "/Sounds");
    }
    QFile::copy(":/sounds/SwappingPage.wav", QDir::currentPath() + "/Sounds/SwappingPage.wav");
    QFile::copy(":/sounds/Close.wav", QDir::currentPath() + "/Sounds/Close.wav");

    currentPage = 0;
    try
    {
        QString linker = ":/JSONs/Bestiary.json";
        JSON_reader read(linker);
        creatureList newList(read.getMap());
        list = newList.getList();
    }
    catch (const char* err)
    {
        QMessageBox::critical(this, "Error", err);
        exit(0);
    }

    showCreature(currentPage);
}



Creature::~Creature()
{
    delete ui;
}

void Creature::showContList()
{
    uiManager(false);

    QString contList = "";

    for (size_t i = 1; i < list.size(); i++)
    {
        QString part = "";
        int sizeCheck = 0, pageNum = i*2-1;
        QString spacer = "";
        if (list[i].getCtg() == 1)
        {
            spacer = "";
            sizeCheck = 76;
        }
        else if (list[i].getCtg() == 2)
        {
            spacer = "&#160;&#160;&#160;&#160;";
            sizeCheck = 98;
        }
        else if (list[i].getCtg() == 3)
        {
            spacer = "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;";
            sizeCheck = 118;
        }

        part += spacer + makeHyperLink(i, list[i].getName());
        for (int j = part.size(); j != sizeCheck; j++)
        {
            part += "...";
        }
        contList += part + QString::number(pageNum);
        if (i != list.size())
        {
            contList += "<br>";
        }
    }

    ui->List->setText(contList);

    QPixmap pix(":/Pictures/ContList.png");
    int w = ui->Pic->width();
    int h = ui->Pic->height();

    ui->Pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->Pic->setAlignment(Qt::AlignCenter);
}

QString Creature::makeHyperLink(int page, QString str)
{
    QString link = "";
    link += "<a href=\"" + QString::number(page) + "\" style=\"color: #9C0000;\">" + str + "</a>";
    return link;
}

QString Creature::makeHyperLinkList(QStringList convList, QString separator)
{
    QString newList = "";
    for (int i = 0; i < convList.size(); i++)
    {
        for (size_t j = 0; j < list.size(); j++)
        {
            if (list[j].getName() == convList.at(i))
            {
                newList += makeHyperLink(j, convList.at(i));
                if (i != convList.size()-1)
                {
                    newList += separator;
                }
                break;
            }
        }
    }
    return newList;
}

int Creature::findCat(QString name)
{
    int catPage = 0;
    for (size_t j = 0; j < list.size(); j++)
    {
        if (list[j].getName() == name)
        {
            catPage = j;
            break;
        }
    }
    return catPage;
}

void Creature::uiManager(bool lowestCtg)
{
    if (currentPage == 0)
    {
        ui->subList->stackUnder(ui->List);
        ui->enemList->stackUnder(ui->List);
        ui->subTitle->clear();
        ui->eTitle->clear();
        ui->sTitle->clear();
        ui->wTitle->clear();
        ui->fTitle->clear();
        ui->dTitle->clear();
        ui->Page1->clear();
        ui->Page2->clear();
        ui->name->setText("List of Contents");
        ui->description->clear();
        ui->enemList->clear();
        ui->subList->clear();
        ui->strengthList->clear();
        ui->weakList->clear();
        ui->feedList->clear();
    }
    else
    {
        if (!lowestCtg)
        {
            ui->List->stackUnder(ui->subList);
            ui->enemList->stackUnder(ui->subList);
            ui->subTitle->setText("Kinds of " + list[currentPage].getName());
            ui->eTitle->clear();
            ui->sTitle->clear();
            ui->wTitle->clear();
            ui->fTitle->clear();
            ui->dTitle->clear();
        }
        if (lowestCtg)
        {
            ui->subList->stackUnder(ui->enemList);
            ui->List->stackUnder(ui->enemList);
            ui->subTitle->clear();
            ui->eTitle->setText("Enemies:");
            ui->sTitle->setText("Strengths:");
            ui->wTitle->setText("Weaknesses:");
            ui->fTitle->setText("Feed:");
            ui->dTitle->setText("Description:");
        }
    }

    ui->swapList->setEnabled(true);
    ui->swapCat->setEnabled(true);
    ui->swapLeft->setEnabled(true);
    ui ->swapRight->setEnabled(true);
    if (currentPage == list.size() - 1)
    {
        ui ->swapRight->setEnabled(false);
    }
    else if (currentPage == 0)
    {
        ui->swapList->setEnabled(false);
        ui->swapCat->setEnabled(false);
        ui->swapLeft->setEnabled(false);
    }
}

void Creature::showCreature(int page)
{   
    currentUpCat = 0;
    currentPage = page;
    QSound::play(QDir::currentPath() + "/Sounds/SwappingPage.wav");
    if (currentPage == 0)
    {
        showContList();
    }
    else
    {
        QString strs = (list[currentPage].getStrs()).join(", ");
        QString weaks = (list[currentPage].getWeaks()).join(", ");
        QString feed = (list[currentPage].getFeed()).join(", ");
        QString enemies = makeHyperLinkList(list[currentPage].getEnemies(), "; ");
        QString subCtgs = makeHyperLinkList(list[currentPage].getSubCtg(), ";<br>");
        currentUpCat = findCat(list[currentPage].getUpCtg());

        ui->List->clear();
        if (subCtgs != "")
        {
            uiManager(false);
        }
        else
        {
            uiManager(true);
        }

        ui->name->setText(list[currentPage].getName());
        ui->description->setText(list[currentPage].getDescription());
        ui->enemList->setText(enemies);
        ui->strengthList->setText(strs);
        ui->weakList->setText(weaks);
        ui->feedList->setText(feed);
        ui->subList->setText(subCtgs);

        ui->Page1->setText(QString::number(currentPage*2-1));
        ui->Page2->setText(QString::number(currentPage*2));

        QPixmap pix(list[currentPage].getPic());
        int w = ui->Pic->width();
        int h = ui->Pic->height();
        ui->Pic->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        ui->Pic->setAlignment(Qt::AlignCenter);
    }
}

void Creature::on_enemList_linkActivated(const QString &link)
{
    showCreature(link.toInt());
}

void Creature::mousePressEvent(QMouseEvent *event){
    mpos = event->pos();
}

void Creature::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;

        this->move(newpos);
    }
}

void Creature::on_subList_linkActivated(const QString &link)
{
    showCreature(link.toInt());
}

void Creature::on_List_linkActivated(const QString &link)
{
    showCreature(link.toInt());
}

void Creature::on_swapList_clicked()
{
    currentPage = 0;
    showCreature(currentPage);
}

void Creature::on_swapRight_clicked()
{
    currentPage ++;
    showCreature(currentPage);
}

void Creature::on_swapLeft_clicked()
{
    currentPage --;
    showCreature(currentPage);
}

void Creature::on_swapCat_clicked()
{
    showCreature(currentUpCat);
}

void Creature::on_pushButton_2_clicked()
{
    QSound::play(QDir::currentPath() + "/Sounds/Close.wav");
    this->close();
}
