#ifndef DIALOGINFOR_H
#define DIALOGINFOR_H

#include <QDialog>
#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QQmlEngine>


namespace Ui {
class DialogInfor;
}

class DialogInfor : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogInfor(QWidget *parent = 0);
    ~DialogInfor();
    
private:
   // Ui::DialogInfor *ui;

    QDeclarativeView *ui;
};

#endif // DIALOGINFOR_H
