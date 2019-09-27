#ifndef DATAWRITER_H
#define DATAWRITER_H

#include <QString>
#include "model/datacollection.h"

class DataWriter
{
public:
    DataWriter(QString file_name);
    void write(DataCollection *data_collection);

private:
    QString fileName;
};

#endif // DATAWRITER_H
