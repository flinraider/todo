#include "todo.h"
#include "ui_todo.h"

Todo::Todo(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Todo){
    ui->setupUi(this);
}

Todo::~Todo(){
    delete ui;
}


void Todo::on_actionSair_triggered(){
    close();
}

void Todo::on_actionInfo_triggered(){
    QMessageBox::about( this, "Sobre este Projeto", "<h1>Todo V-1.0</h1><br>"
                                                    "<b>Desenvolvido Por Consoletech</p><br><br>"
                                                    "Aplicativo para organização de tarefas.<br>"
                                                    "<a href='https://github.com/flinraider/todo/'>Acesse para mais informações do projeto.</a>"
                                                    "<br>");
}
