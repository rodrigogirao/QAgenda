#ifndef TESTE_H
#define TESTE_H

#include <QDialog>

namespace Ui {
class teste;
}

class teste : public QDialog
{
    Q_OBJECT
    
public:
    explicit teste(QWidget *parent = 0);
    ~teste();
    
private:
    Ui::teste *ui;
};

#endif // TESTE_H
