#ifndef ADDCONTATODIALOG_H
#define ADDCONTATODIALOG_H

#include <QDialog>

namespace Ui {
class AddContatoDialog;
}

class AddContatoDialog : public QDialog
{
    Q_OBJECT
    QString imagem;
    
public:
    explicit AddContatoDialog(QWidget *parent = 0);
    ~AddContatoDialog();
public:
    QString getEmail();
    QString getFoto();
    int getNivelAmizade();
    void setEmail(QString email);
    void setNivelAmizade(int valor);
    void setFoto(QString foto);
    
private slots:
   void on_commandLinkButton_clicked();

private:
    Ui::AddContatoDialog *ui;
};

#endif // ADDCONTATODIALOG_H
