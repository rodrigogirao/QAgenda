#ifndef DECORARTABELADELAGATE_H
#define DECORARTABELADELAGATE_H

#include <QStyledItemDelegate>

class DecorarTabelaDelagate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit DecorarTabelaDelagate(QObject *parent = 0);
    
signals:
protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    
public slots:
    
};

#endif // DECORARTABELADELAGATE_H
