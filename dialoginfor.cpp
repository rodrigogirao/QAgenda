#include "dialoginfor.h"
#include "ui_dialoginfor.h"
#include "QVBoxLayout"


DialogInfor::DialogInfor(QWidget *parent) :
    QDialog(parent)
   // ui(new Ui::DialogInfor)
{


    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet("background:transparent;");

     /* turn off window decorations */
     setWindowFlags(Qt::FramelessWindowHint);

     ui = new QDeclarativeView;
     ui->setSource(QUrl("qrc:/ui.qml"));

    QVBoxLayout *layout = new QVBoxLayout;
    //QLayout *l = new QLayout;

    // layout->addSpacing(400);
    layout->SetMaximumSize;

     layout->setContentsMargins(1,1,1,1);

        layout->addWidget(ui);
        this->setLayout(layout);

      //setCentralWidget(ui);
     //setCentralWidget(ui);


}

DialogInfor::~DialogInfor()
{
    delete ui;
}
