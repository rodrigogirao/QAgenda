#include "dialogmensage.h"
#include "ui_dialogmensage.h"
#include "qfile.h"
#include "qdebug.h"

DialogMensage::DialogMensage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMensage)
{
    ui->setupUi(this);
}

DialogMensage::~DialogMensage()
{
    delete ui;
}

void DialogMensage::setEmailSelecionado(QString emailSelecionado)
{

    ui->label->setText(emailSelecionado);

}

void DialogMensage::on_buttonBox_accepted()
{
   QFile file(ui->label->text());
   qDebug() << "passou aqui " + ui->label->text();
    if ( file.open(QIODevice::WriteOnly) ) {
        QDataStream stream(&file);


            stream << ui->leenviarMensagem->text();


        file.close();
    }

}
