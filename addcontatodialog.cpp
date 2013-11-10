#include "addcontatodialog.h"
#include "ui_addcontatodialog.h"
#include "qfile.h"
#include "qfiledialog.h"
#include "qdebug.h"
#include <QMessageBox>

AddContatoDialog::AddContatoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContatoDialog)
{

    ui->setupUi(this);
    ui->horizontalSlider->setStyleSheet("QSlider::handle:horizontal { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);border: 1px solid #5c5c5c;width: 18px;margin: -2px 0; border-radius: 3px;}");
    ui->horizontalSlider->setStyleSheet("QSlider::sub-page:vertical { background: pink;}");
    ui->horizontalSlider->repaint();
}

AddContatoDialog::~AddContatoDialog()
{
    delete ui;
}

QString AddContatoDialog::getEmail()
{
    return ui->leemail->text();
}

QString AddContatoDialog::getFoto()
{
    return imagem;
}

int AddContatoDialog::getNivelAmizade()
{
    return ui->horizontalSlider->value();
}

void AddContatoDialog::setEmail(QString email)
{
    ui->leemail->setText(email);
}

void AddContatoDialog::setFoto(QString foto)
{
    imagem = foto;
    if (imagem!=""){
        QFile arquivo(imagem);

        if (arquivo.open(QIODevice::ReadOnly)) {
            ui->lbfoto->setPixmap(QPixmap(imagem));
        }
        arquivo.close();
    }else{
        ui->lbfoto->setPixmap(QPixmap(":/new/prefix1/10693_64x64.png"));
    }
}

void AddContatoDialog::setNivelAmizade(int valor)
{
    ui->horizontalSlider->setValue(valor);
}



void AddContatoDialog::on_commandLinkButton_clicked()
{
    imagem = QFileDialog::getOpenFileName(this,"Abrir Imagem",tr("Arquivo"));
    QFile arquivo(imagem);

    if (arquivo.open(QIODevice::ReadOnly)) {
        ui->lbfoto->setPixmap(QPixmap(imagem));
    }else {
        QMessageBox::critical(this,"Erro","Erro ao abrir arquivo!");
    }
}
