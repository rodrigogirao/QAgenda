#include "visualizarlog.h"
#include "ui_visualizarlog.h"

VisualizarLog::VisualizarLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizarLog)
{
    ui->setupUi(this);
}

VisualizarLog::~VisualizarLog()
{
    delete ui;
}

void VisualizarLog::setArquivo(QString texto)
{
    ui->plainTextEdit->setPlainText(texto);
}
