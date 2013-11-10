#ifndef DIALOGMENSAGE_H
#define DIALOGMENSAGE_H

#include <QDialog>

namespace Ui {
class DialogMensage;
}

class DialogMensage : public QDialog
{
    Q_OBJECT
    QString emailSelecionado;
    
public:
    explicit DialogMensage(QWidget *parent = 0);
    ~DialogMensage();
   void setEmailSelecionado(QString emailSelecionado);
    
private slots:
   void on_buttonBox_accepted();

private:
    Ui::DialogMensage *ui;
};

#endif // DIALOGMENSAGE_H
