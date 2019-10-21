#ifndef DATAENTITY_H
#define DATAENTITY_H

#include <QObject>
#include <QMetaType>
#include <QString>

class DataEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString term READ getTerm WRITE setTerm)
    Q_PROPERTY(QString definition READ getDefinition WRITE setDefinition)
public:
    DataEntity() {}
    DataEntity(const DataEntity& data_entity) : QObject(data_entity.parent()) {term = data_entity.term; definition = data_entity.definition;}
    DataEntity(QString term);
    DataEntity(QString term, QString definition);

    QString getTerm() const;
    QString getDefinition() const;

    void setTerm(QString);
    void setDefinition(QString);

private:
    QString term;
    QString definition;
};

Q_DECLARE_METATYPE(DataEntity)

#endif // DATAENTITY_H
