#include "editar.h"
#include "ui_editar.h"

Editar::Editar(QWidget *parent, int id, QString todo) : QDialog(parent), ui(new Ui::Editar){
    ui->setupUi(this);
    ui->label->setText(QString::number( id ) );
    ui->lineEdit->setText( todo );
}

Editar::~Editar(){
    delete ui;
}

void Editar::on_btn_edit_clicked(){
    if( ui->lineEdit->text() == ""){
        QMessageBox::warning( this, "Erro", "Campo não pode ser Vazio!");
        return;
    }
    QString id {ui->label->text()};

    QSqlQuery query;
    QString sql {"update todos set todos ='"+ ui->lineEdit->text() +"'where id = "+id};
    query.prepare( sql );
    if( query.exec() ){
          close();
    }else{
        QMessageBox::warning( this, "Erro", "Dados não alterados");
    }
}

void Editar::on_btn_delete_clicked(){

    QString id {ui->label->text()};
    QSqlQuery query;
    QString sql {"delete from todos where id="+id};
    query.prepare( sql );
    if( query.exec() ){
          close();
    }else{
        QMessageBox::warning( this, "Erro", "Dados não Excluidos");
    }
}
