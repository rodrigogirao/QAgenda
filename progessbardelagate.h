#ifndef PROGESSBARDELAGATE_H
#define PROGESSBARDELAGATE_H

#include <QStyledItemDelegate>

class ProgessbarDelagate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ProgessbarDelagate(QObject *parent = 0);
    
signals:
protected:
  void  paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    
public slots:
    
};

#endif // PROGESSBARDELAGATE_H
