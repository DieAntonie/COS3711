#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#include <QList>
#include "dataentity.h"

class DataCollection
{
public:
    explicit DataCollection();
    explicit DataCollection(DataCollection *);
    ~DataCollection();

    void add(QObject *);
    QList<QObject *> *toList();

private:
    QList<QObject *> *list;
};

#endif // DATACOLLECTION_H
