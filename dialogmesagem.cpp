#include "dialogmesagem.h"
#include "ui_dialogmesagem.h"

DialogMesagem::DialogMesagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMesagem)
{
    ui->setupUi(this);
}

DialogMesagem::~DialogMesagem()
{
    delete ui;
}
