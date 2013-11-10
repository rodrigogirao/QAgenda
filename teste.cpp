#include "teste.h"
#include "ui_teste.h"

teste::teste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teste)
{
    ui->setupUi(this);
}

teste::~teste()
{
    delete ui;
}
