#ifndef DECORARTABELAIMAGEM_H
#define DECORARTABELAIMAGEM_H

#include <QStyledItemDelegate>

class DecorarTabelaImagem : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DecorarTabelaImagem(QObject *parent = 0);
    
signals:
protected:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

public slots:
    
};

#endif // DECORARTABELAIMAGEM_H
