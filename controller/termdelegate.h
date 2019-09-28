#ifndef TERMDELEGATE_H
#define TERMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class TermDelegate : public QStyledItemDelegate
{
public:
    TermDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:

};

#endif // TERMDELEGATE_H
