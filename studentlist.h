#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QWidget>

namespace Ui {
class studentlist;
}

class studentlist : public QWidget
{
    Q_OBJECT

public:
    explicit studentlist(QWidget *parent = nullptr);
    ~studentlist();

private:
    Ui::studentlist *ui;
};

#endif // STUDENTLIST_H
