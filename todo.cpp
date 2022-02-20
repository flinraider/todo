#include "todo.h"
#include "ui_todo.h"

Todo::Todo(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Todo){
    ui->setupUi(this);
    start();
    db.setDatabaseName( user );
    db.open() ? std::cout << "Ok\n"  : std::cout << "Banco de dados não encontrado\n";
    show_data();
}

Todo::~Todo(){
    delete ui;
}

void Todo::start(){
    QFile quser( user );
    if( !quser.exists() ){
        QFile::copy( dir, user );
        system("chmod 600 ~/.config/todo.db");
        std::cout << "O arquivo foi copiado" << '\n';
    }
}

void Todo::show_data(){
    QSqlQuery query;
    QString sql = "select * from todos;";
    query.prepare( sql );
    if( query.exec() ){

        int i = 0;
        ui->tableWidget->setColumnCount( 3 );
        while( query.next() ){
        ui->tableWidget->insertRow( i );
        ui->tableWidget->setItem( i, 0, new QTableWidgetItem( query.value( 0 ).toString() ) );
        ui->tableWidget->setItem( i, 1, new QTableWidgetItem( query.value( 1 ).toString() ) );
        ui->tableWidget->setItem( i, 2, new QTableWidgetItem( query.value( 2 ).toString() ) );
        i++;
        }
        QStringList headers {"Id","Tarefas","Data/Hora"};
        ui->tableWidget->setHorizontalHeaderLabels( headers );
        ui->tableWidget->setColumnWidth(0, 60);
        ui->tableWidget->setColumnWidth(1, 600);
        ui->tableWidget->setColumnWidth(2, 200);

        while( i < ui->tableWidget->rowCount() ){
            ui->tableWidget->removeRow( i );
        }

        ui->tableWidget->verticalHeader()->setVisible( false);
//        ui->statusbar->showMessage("ok");
//        QTimer::singleShot( 2000, [&](){ ui->statusbar->showMessage("");});
    }else{
        std::cout << "Error\n";
    }
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

void Todo::on_btn_add_clicked(){
    if( ui->field_task->text() == "" ){
        QMessageBox::warning( this, "Erro", "Preecha o campo");
        return;
    }
    if( ! db.isOpen() ){
        QMessageBox::warning( this, "Erro", "Falha ao conectar ao banco de dados");
    }

    QSqlQuery query;
    QString sql = "insert into todos (todos) values ('"+ ui->field_task->text() +"');";
    query.prepare( sql );
    if( query.exec() ){
        ui->statusbar->showMessage("Dados inseridos!");
        QTimer::singleShot( 2000, [&](){ ui->statusbar->showMessage("");});
        ui->field_task->clear();
        ui->field_task->setFocus();
        ui->tableWidget->clear();
        show_data();
    }else{
        ui->statusbar->showMessage("Erro ao inserir dados!");
    }
}

void Todo::on_tableWidget_cellClicked(int row, int column){

    column = 0;
    int id = ui->tableWidget->item(row , column)->text().toInt();
    QString todo =  ui->tableWidget->item(row , 1)->text();
    Editar e(this, id, todo);
    e.exec();
    show_data();
}



























