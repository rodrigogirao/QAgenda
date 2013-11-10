#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "adddialog.h"
#include "addcontatodialog.h"
#include "qabstractitemmodel.h"
#include "qstandarditemmodel.h"
#include <QDeclarativeEngine>

#define DATAFILE "DATA.BIN"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
   AddContatoDialog *ACD;

   struct Pessoa{

       QString nome;
       QString email;
       int nivelAmizade;
       QString foto;
   };

   QList<Pessoa> pessoas;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void reloadListaPessoas();
   void carregarArquivo();
   QList<Pessoa> getPessoasAtuais();
    
private slots:
    void on_actionAdicionar_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_actionSalvar_triggered();

    void on_actionRemover_triggered();

    void on_actionEnviar_msg_triggered();

    void on_actionLog_MSG_triggered();

private:
    Ui::MainWindow *ui;
    // QDeclarativeView *ui;
    QStandardItemModel *model;
};

#endif // MAINWINDOW_H
