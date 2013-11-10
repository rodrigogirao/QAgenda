#include "visualizarlog.h"
#include "ui_visualizarlog.h"

VisualizarLog::VisualizarLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizarLog)
{
    ui->setupUi(this);
    this->setWindowTitle("Mensagens Enviadas");
}

VisualizarLog::~VisualizarLog()
{
    delete ui;
}

void VisualizarLog::setArquivo(QString texto)
{
    ui->plainTextEdit->setPlainText(texto);
}

void VisualizarLog::setDestinatario(QString texto)
{
    ui->destinatario->setText(texto);
}
