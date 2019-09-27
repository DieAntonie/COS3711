#include "model/datacollection.h"

DataCollection::DataCollection()
{
    list = new QList<QObject *>();
}

DataCollection::DataCollection(DataCollection *data_collection)
{
    list = data_collection->list;
}

DataCollection::~DataCollection()
{
    qDeleteAll(*list);
    list->clear();
    delete list;
}

void DataCollection::add(QObject *data_object)
{
    list->append(data_object);
}

QList<QObject *> *DataCollection::toList()
{
    return list;
}
