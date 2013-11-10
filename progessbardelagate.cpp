#include "progessbardelagate.h"
#include <QApplication>
#include <QPainter>
ProgessbarDelagate::ProgessbarDelagate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

void ProgessbarDelagate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if (index.column() == 2) {
        int progressPercentage = index.model()->data(index, Qt::DisplayRole).toInt();

         QStyleOptionProgressBarV2 progressBarOption;
         progressBarOption.rect = QRect(option.rect.x(), option.rect.y() + 5 , option.rect.width(), option.rect.height() / 1.5);
         progressBarOption.minimum = 0;
         progressBarOption.maximum = 100;
         progressBarOption.progress = progressPercentage;
//         progressBarOption.textVisible = true;
//         QPalette pal = progressBarOption.palette;
//         QColor col = QColor(35, 35,25);
//         pal.setColor(QPalette::Highlight, col); // or QPalette::Window doesnt matter
//         progressBarOption.palette = pal;

         if(option.state & QStyle::State_Selected) {

         }
         painter->save();
         QColor c = Qt::black;
         painter->setPen(c);
         painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
         painter->background();;
         painter->restore();
         QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);

     } else QStyledItemDelegate::paint(painter, option, index);

}
