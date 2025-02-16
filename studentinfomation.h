#ifndef STUDENTINFOMATION_H
#define STUDENTINFOMATION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class StudentInfomation;
}
QT_END_NAMESPACE

class StudentInfomation : public QWidget
{
    Q_OBJECT

public:
    StudentInfomation(QWidget *parent = nullptr);
    ~StudentInfomation();

private slots:
    void InitDatabase();
    void InitTableList();

    void on_insertbutton_clicked();

    void on_changebutton_clicked();

    void on_selectbutton_clicked();

    void on_deletebutton_clicked();

    void on_clearbutton_clicked();

    void Add(const int studentid,const QString studentname,const int studentgrades);//添加至数据库
    void AddRow();//添加至列表后显示

    void Update(const int studentid,const QString studentname,const int studentgrades);

private:
    Ui::StudentInfomation *ui;

    std::map<int,std::pair<std::string,float>> student;
    QSqlDatabase stud=QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery students;//表示使用QSqlQuery来执行创建表的sql语句

    int studentid;
    QString name;
    float grades;
};
#endif // STUDENTINFOMATION_H
