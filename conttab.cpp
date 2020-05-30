#include "conttab.h"
#include "ui_conttab.h"

contTab::contTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contTab)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/images/Others/Back.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

contTab::~contTab()
{
    delete ui;
}
