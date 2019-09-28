#include "controller/termdelegate.h"

TermDelegate::TermDelegate()
{

}

void TermDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int row = index.row();
    int column = index.column();
    const QAbstractItemModel *data = index.model();
    QString string_data = index.data().toString();
    painter->drawText(option.rect, string_data);
}
