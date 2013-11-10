#ifndef VISUALIZARLOG_H
#define VISUALIZARLOG_H

#include <QWidget>

namespace Ui {
class VisualizarLog;
}

class VisualizarLog : public QWidget
{
    Q_OBJECT
    
public:
    explicit VisualizarLog(QWidget *parent = 0);
    ~VisualizarLog();
    void setArquivo(QString texto);
    void setDestinatario(QString texto);
    
private:
    Ui::VisualizarLog *ui;
};

#endif // VISUALIZARLOG_H
