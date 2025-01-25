#include "studentinfomation.h"
#include "./ui_studentinfomation.h"

StudentInfomation::StudentInfomation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentInfomation)
{
    ui->setupUi(this);
    this->setWindowTitle("学生成绩管理系统");


    //数据库名：StudentsInfomation
    //表名：studentsinfo
    stud.setDatabaseName("StudentsInfomation");

    InitDatabase();

    // 创建主窗口和布局
    QWidget window;
    QVBoxLayout layout(&window);

    // 创建 QListView 和 QSqlQueryModel
    QSqlQueryModel model;

    // 初始化模型并显示初始数据
    // Update(&model);
    model.setQuery("SELECT id, name, age FROM users");
    ui->studentsinfolist->setModel(&model);

}

StudentInfomation::~StudentInfomation()
{
    delete ui;
}

void StudentInfomation::InitDatabase()
{
    if(!stud.open())
    {
        qDebug()<<"数据库链接错误！";
        qDebug()<<stud.lastError().text();
        return;
    }
    else
    {
        qDebug()<<"数据库链接成功！";
        qDebug()<<stud.databaseName();
        qDebug()<<stud.connectionName();
    }

    // QSqlQuery students;//表示使用QSqlQuery来执行创建表的sql语句
    // CREATE TABLE IF NOT EXISTS studentsinfo:如果表studentsinfo不存在时则创建表studentsinfo
    // id INT PRIMARY KEY QUTOINCREMENT：id表示字段，int表示类型，PRIMARY KEY表示这个字段为主键，AUTOINCREMENT启动了自动递增功能
    // 主键的类型一定是INTEGER PRIMARY KEY，不能是INT，其他的是可以的
    QString createTable=R"(CREATE TABLE IF NOT EXISTS studentsinfo
                            (
                                id INTEGER PRIMARY KEY AUTOINCREMENT,
                                studentid INT PRIMARY KEY,
                                name TEXT NOT NULL,
                                grades INTEGER NOT NULL
                            ))";
    if(!students.exec(createTable))//执行创建表的sql语句
    {
        qDebug()<<"创建表失败:"<<students.lastError().text();
    }
    else
    {
        qDebug()<<"创建表成功！";
    }
}

void StudentInfomation::on_insertbutton_clicked()//添加
{
    QString tempid;
    QString tempgrades;
    tempid=ui->id->toPlainText();
    studentid=tempid.toInt();
    name=ui->name->toPlainText();
    tempgrades=ui->grades->toPlainText();
    grades=tempgrades.toFloat();

    qDebug()<<"id::"<<studentid;
    qDebug()<<"name:"<<name;
    qDebug()<<"grades:"<<grades;

    Add(studentid,name,grades);

    ui->name->setText("");
    ui->id->setText(0);
    ui->grades->setText(0);

}


void StudentInfomation::on_changebutton_clicked()//修改
{
    // QString tempid;
    // tempid=ui->select->toPlainText();

    // QString selectTable="SELECT studentid, name, grades from studentsinfo";
    // if(!students.exec(selectTable))
    // {
    //     qDebug()<<"表查询失败:"<<students.lastError().text();
    // }
    // else
    // {
    //     qDebug()<<"表内容:";
    //     while(students.next())
    //     {
    //         studentid=students.value(0).toUInt();
    //         name=students.value(1).toString();
    //         grades=students.value(2).toInt();
    //         if(students.value(0).toString()==tempid)
    //         {

    //             qDebug()<<"学号："<<studentid<<"名字："<<name<<"成绩："<<grades;
    //         }

    //     }
    // }
}


void StudentInfomation::on_selectbutton_clicked()//查询
{
    QString temp;
    temp=ui->select->toPlainText();
    int flag=0;
    if(temp!="")
    {
        flag=1;
    }

    QString selectTable="SELECT studentid, name, grades from studentsinfo";
    if(!students.exec(selectTable))
    {
        qDebug()<<"表查询失败:"<<students.lastError().text();
    }
    else
    {
        qDebug()<<"表内容:";
        while(students.next())
        {
            studentid=students.value(0).toUInt();
            name=students.value(1).toString();
            grades=students.value(2).toInt();
            if(students.value(1).toString()==temp)
            {
                qDebug()<<"学号："<<studentid<<"名字："<<name<<"成绩："<<grades;
            }
            if(flag==0)
            {
                qDebug()<<"学号："<<studentid<<"名字："<<name<<"成绩："<<grades;
            }
        }
    }
}

void StudentInfomation::on_deletebutton_clicked()//删除
{
}


void StudentInfomation::on_clearbutton_clicked()//清空表
{
    if(!students.exec("DELETE FROM studentsInfo"))
    {
        qDebug()<<"清空失败:"<<students.lastError();
    }
    else
    {
        qDebug()<<"清空成功！";
    }
}

void StudentInfomation::Add(const int studentid, const QString studentname, const int studentgrades)
{
    if(studentid==0||studentname==""||studentgrades==0)
    {
        return;
    }
    students.prepare("INSERT INTO studentsinfo (studentid,name,grades) VALUES (:studentid,:name,:grades)");
    students.bindValue(":studentid",studentid);
    students.bindValue(":name",studentname);
    students.bindValue(":grades",studentgrades);
    if(!students.exec())
    {
        qDebug()<<"插入数据失败:"<<students.lastError().text();
    }
    else
    {
        qDebug()<<"插入数据成功！";
    }
}

void StudentInfomation::Update(const int studentid, const QString studentname, const int studentgrades)
{
}

