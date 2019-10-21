#ifndef DATAREADER_H
#define DATAREADER_H

#include <QString>
#include "application/model/datacollection.h"

class DataReader
{
public:
    DataReader(QString file_name);
    DataCollection *read();

private:
    QString fileName;
};

#endif // DATAREADER_H
