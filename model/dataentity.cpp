#include "model/dataentity.h"

DataEntity::DataEntity(QString data_term) : term(data_term)
{
}

DataEntity::DataEntity(QString data_term, QString data_definition) : term(data_term), definition(data_definition)
{
}

void DataEntity::setTerm(QString new_term)
{
    term = new_term;
}

void DataEntity::setDefinition(QString new_definition)
{
    definition = new_definition;
}

QString DataEntity::getTerm() const
{
    return term;
}

QString DataEntity::getDefinition() const
{
    return definition;
}
