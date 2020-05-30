#ifndef CONTTAB_H
#define CONTTAB_H

#include <QDialog>

namespace Ui {
class contTab;
}

class contTab : public QDialog
{
    Q_OBJECT

public:
    explicit contTab(QWidget *parent = nullptr);
    ~contTab();

private:
    Ui::contTab *ui;
};

#endif // CONTTAB_H
