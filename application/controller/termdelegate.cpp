#include "application/controller/termdelegate.h"

TermDelegate::TermDelegate()
{

}

void TermDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QString string_data = index.data().toString();
    painter->drawText(option.rect, string_data);
}
