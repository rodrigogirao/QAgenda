
#include "ui_addDialog.h"
#include "adddialog.h"

adddialog::adddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{

   ui->setupUi(this);
}

adddialog::~adddialog()
{
    delete ui;
}
