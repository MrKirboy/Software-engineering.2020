#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "creature.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    QPixmap bkgnd(":/images/Others/Cover.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);

    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();

    Creature creature;
    creature.exec();

    this->show();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    mpos = event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - mpos;
        QPoint newpos = this->pos() + diff;

        this->move(newpos);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
