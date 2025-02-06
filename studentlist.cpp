#include "studentlist.h"
#include "ui_studentlist.h"

studentlist::studentlist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::studentlist)
{
    ui->setupUi(this);
}

studentlist::~studentlist()
{
    delete ui;
}
