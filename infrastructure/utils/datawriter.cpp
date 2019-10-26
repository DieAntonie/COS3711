#include <QFile>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include "infrastructure/utils/datawriter.h"

DataWriter::DataWriter(QString file_name) : fileName(file_name)
{
}

void DataWriter::write(DataCollection *data_collection)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    xml_writer.setDevice(&file);
    xml_writer.setAutoFormatting(true);
    xml_writer.writeStartDocument();
    xml_writer.writeStartElement("datacollection");

    foreach (QObject *data_object, *data_collection->toList())
    {
        const QMetaObject *meta_object = data_object->metaObject();
        xml_writer.writeStartElement(meta_object->className());

        for (int property_index = meta_object->propertyOffset(); property_index < meta_object->propertyCount(); property_index++)
        {
            const char *property_name = meta_object->property(property_index).name();
            QString property_value = data_object->property(property_name).toString();
            xml_writer.writeTextElement(property_name, property_value);
        }

        xml_writer.writeEndElement();
    }

    xml_writer.writeEndElement();
    xml_writer.writeEndDocument();
    file.close();
}
