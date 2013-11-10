#include "decorartabelaimagem.h"
#include <QLabel>
#include <QPainter>

DecorarTabelaImagem::DecorarTabelaImagem(QObject *parent) :
    QStyledItemDelegate(parent)
{

}

QWidget *DecorarTabelaImagem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLabel* label = new QLabel(parent);
    return label;
}

void DecorarTabelaImagem::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->drawRect(option.rect);
    painter->drawPixmap(option.rect, QPixmap(index.data().toString()));
    painter->save();
    QColor c = Qt::black;
    painter->setPen(c);
    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
    painter->background();;
    painter->restore();
}

void DecorarTabelaImagem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLabel *label = static_cast <QLabel*> (editor);
    label->setPixmap(QPixmap(index.data().toString()));

}

void DecorarTabelaImagem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLabel *label = static_cast <QLabel*> (editor);
    model->setData(index, label->pixmap());
}

void DecorarTabelaImagem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     editor->setGeometry(option.rect);
}
