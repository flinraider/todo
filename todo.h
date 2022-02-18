#ifndef TODO_H
#define TODO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Todo; }
QT_END_NAMESPACE

class Todo : public QMainWindow{
    Q_OBJECT

public:
    Todo(QWidget *parent = nullptr);
    QString home = getenv("HOME");
    void start();
    QString dir = ":/../database/todo.db";
    QString user = home + "/.config/todo.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void show_data();
    ~Todo();

private slots:
    void on_actionSair_triggered();

    void on_actionInfo_triggered();

private:
    Ui::Todo *ui;
};
#endif // TODO_H
