#include "decorartabeladelagate.h"
#include <QPainter>

DecorarTabelaDelagate::DecorarTabelaDelagate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void DecorarTabelaDelagate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
        painter->save();
        QColor c = Qt::black;
        painter->setPen(c);
        painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
        painter->background();;
        painter->restore();

        // Now paint the normal cell contents
        this->QStyledItemDelegate::paint(painter, option, index);
}
