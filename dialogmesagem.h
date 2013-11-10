#ifndef DIALOGMESAGEM_H
#define DIALOGMESAGEM_H

#include <QDialog>

namespace Ui {
class DialogMesagem;
}

class DialogMesagem : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogMesagem(QWidget *parent = 0);
    ~DialogMesagem();
    
private:
    Ui::DialogMesagem *ui;
};

#endif // DIALOGMESAGEM_H
