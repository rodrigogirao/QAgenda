#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "QDialog"
#include "qdebug.h"
#include <QQuickItem>
#include <QtDeclarative/QDeclarativeView>
#include <QObject>
#include "dialogmensage.h"
#include "visualizarlog.h"
#include <QString>
#include "decorartabelaimagem.h"
#include "progessbardelagate.h"
#include "decorartabeladelagate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this);

    QStringList cabecalho;
    cabecalho << "Foto" << "E-mail" << "Nivel Amizade";

    model->setHorizontalHeaderLabels(cabecalho);

    ui->tbIniciar->setItemDelegateForColumn(0, new DecorarTabelaImagem(this));
    ui->tbIniciar->setItemDelegateForColumn(2, new ProgessbarDelagate(this));
    ui->tbIniciar->setItemDelegate(new DecorarTabelaDelagate(this));
    ui->tbIniciar->verticalHeader()->setDefaultSectionSize(100);
    //ui->tbIniciar->setStyleSheet(" QTableView {selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,stop: 0 #FF92BB, stop: 1 white); }");
    //ui->tbIniciar->setShowGrid(false);
    ACD = new AddContatoDialog(this);
    carregarArquivo();
    reloadListaPessoas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reloadListaPessoas()
{
    model->clear();
    QStringList cabecalho;
    cabecalho << "Foto" << "E-mail" << "Nivel Amizade";

    model->setHorizontalHeaderLabels(cabecalho);
    int i =0;
    foreach (Pessoa p, pessoas) {
        int j =0;

        model->setItem(i,j,new QStandardItem(p.foto));
        model->setItem(i,++j,new QStandardItem(p.email));
        model->setItem(i,++j,new QStandardItem(QString::number(p.nivelAmizade)));

        i++;

    }
    ui->tbIniciar->setModel(model);
}

void MainWindow::carregarArquivo()
{
    if ( !QFile::exists(DATAFILE) ) return;
    QFile file(DATAFILE);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);

        pessoas.clear();
        while ( !stream.atEnd() ) {
            Pessoa pessoa;
            stream >>  pessoa.foto
                    >> pessoa.email
                    >> pessoa.nivelAmizade;
            pessoas << pessoa;
        }

        file.close();
    }

}

QList<MainWindow::Pessoa> MainWindow::getPessoasAtuais()
{
    return pessoas;
}

void MainWindow::on_actionAdicionar_triggered()
{
    ACD->exec();

    if (ACD->result() == QDialog::Accepted) {
        Pessoa pessoa;
        pessoa.foto = ACD->getFoto();
        pessoa.email = ACD->getEmail();
        qDebug() << "saiu o resultado "+ACD->getEmail();
        // pessoa.telefone = ACD->getTelefone();
        pessoa.nivelAmizade = ACD->getNivelAmizade();
        pessoas << pessoa;
        reloadListaPessoas();
    }

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{

    Pessoa pessoa = pessoas.at( index.row() );

    QString info = QString("Nome: %1\n"
                           "Email: %2"
                           "Telefone: %3")
            .arg(pessoa.nome)
            .arg(pessoa.email)
            .arg(pessoa.nivelAmizade);

}

void MainWindow::on_actionSalvar_triggered()
{

    if (QFile::exists(DATAFILE))
        QFile::remove(DATAFILE);
    QFile file(DATAFILE);

    if ( file.open(QIODevice::WriteOnly) ) {
        QDataStream stream(&file);

        foreach (Pessoa pessoa, pessoas) {
            stream << pessoa.foto
                   << pessoa.email
                   << pessoa.nivelAmizade;
        }

        file.close();
    }

}

void MainWindow::on_actionRemover_triggered()
{

    QModelIndex index;
    index = ui->tbIniciar->currentIndex();
    pessoas.removeAt(index.row());
    reloadListaPessoas();
    on_actionSalvar_triggered();
}

void MainWindow::on_actionEnviar_msg_triggered()
{
    Pessoa p;
    QModelIndex index;
    DialogMensage *dm = new DialogMensage;
    index = ui->tbIniciar->currentIndex();
    p = pessoas.at(index.row());

    qDebug() << "passou aqui" + QString::number(index.row());
    dm->setEmailSelecionado(p.email);
    dm->exec();
}

void MainWindow::on_actionLog_MSG_triggered()
{
    VisualizarLog *vl = new VisualizarLog;
    QString texto;
    Pessoa p;
    QModelIndex index;
    index = ui->tbIniciar->currentIndex();
    p = pessoas.at(index.row());

    QFile file(p.email);

    if ( file.open(QIODevice::ReadOnly) ) {
        QDataStream stream(&file);

        stream >> texto;


        file.close();
    }
    vl->setArquivo(texto);
    vl->setDestinatario(p.email);
    vl->show();

}
