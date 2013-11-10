#ifndef DECORARDELEGATE_H
#define DECORARDELEGATE_H

#include <QItemDelegate>

class decorarDelegate : public QItemDelegate
{
    Q_OBJECT
    struct Pessoa{

        QString nome;
        QString email;
        QString telefone;
        QPixmap foto;
    };

public:
    explicit decorarDelegate(QObject *parent = 0);
    QWidget   *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    
signals:
    
public slots:

};

#endif // DECORARDELEGATE_H
