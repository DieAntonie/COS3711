#include <QBuffer>
#include <QFile>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include "infrastructure/utils/xmlserializer.h"

QIODevice *XmlSerializer::serialize(QObject *data_object)
{
    QIODevice *output_data = new QBuffer();
    const QMetaObject *meta_object = data_object->metaObject();

    xml_writer.setDevice(output_data);
    xml_writer.setAutoFormatting(true);
    xml_writer.writeStartDocument();
    xml_writer.writeStartElement(meta_object->className());

    for (int property_index = meta_object->propertyOffset(); property_index < meta_object->propertyCount(); property_index++)
    {
        const char *property_name = meta_object->property(property_index).name();
        QString property_value = data_object->property(property_name).toString();
        xml_writer.writeTextElement(property_name, property_value);
    }

    xml_writer.writeEndElement();
    xml_writer.writeEndDocument();
    
    emit serialized(output_data);
    return output_data;
}

QObject *XmlSerializer::deserialize(QIODevice *data_source)
{
    QObject *output_data = NULL;
    const char *property_name = NULL;

    xml_reader.setDevice(data_source);

    while (!xml_reader.atEnd())
    {
        switch (xml_reader.readNext())
        {
        case QXmlStreamReader::StartElement:
        {
            QString xml_element = xml_reader.name().toString();
            int meta_type_ref = QMetaType::type(xml_element.toUtf8());

            if (meta_type_ref > 0)
            {
                void *void_pointer = QMetaType::construct(meta_type_ref);
                output_data = reinterpret_cast<QObject *>(void_pointer);
            }
            else if (output_data != NULL)
            {
                property_name = xml_element.toUtf8();
            }
            break;
        }
        case QXmlStreamReader::Characters:
        {
            if (property_name != NULL)
            {
                output_data->setProperty(property_name, QVariant(xml_reader.text().toString()));
            }
            break;
        }
        case QXmlStreamReader::EndElement:
        {
            if (property_name != NULL)
            {
                property_name = NULL;
            }
            break;
        }
        default:
            break;
        }
    }

    emit deserialized(output_data);
    return output_data;
}
