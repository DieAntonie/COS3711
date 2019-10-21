#ifndef DATACOLLECTION_H
#define DATACOLLECTION_H

#include <QList>
#include "model/dataentity.h"

class DataCollection
{
public:
    DataCollection();
    DataCollection(DataCollection *);
    ~DataCollection();

    void add(QObject *);
    QList<QObject *> *toList();

private:
    QList<QObject *> *list;
};

#endif // DATACOLLECTION_H
