#include "dialogmensage.h"
#include "ui_dialogmensage.h"
#include "qfile.h"
#include "qdebug.h"

DialogMensage::DialogMensage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMensage)
{
    ui->setupUi(this);
    this->setWindowTitle("Mensagem");
}

DialogMensage::~DialogMensage()
{
    delete ui;
}

void DialogMensage::setEmailSelecionado(QString emailSelecionado)
{

    ui->destinatario->setText(emailSelecionado);

}

void DialogMensage::on_buttonBox_accepted()
{
    QString arquivoLido="";
    QFile file(ui->destinatario->text());
    if (QFile::exists(ui->destinatario->text())){

        if (file.open(QIODevice::ReadOnly)) {
            QDataStream streamLer(&file);
            while ( !streamLer.atEnd() ) {
                streamLer >> arquivoLido;
                file.close();
            }
            arquivoLido= arquivoLido+"\n";

        }
    }
    if ( file.open(QIODevice::WriteOnly) ) {
        QDataStream streamEscrever(&file);
        streamEscrever <<arquivoLido +ui->teEnviarMensagem->toPlainText();
        file.close();
    }
}
