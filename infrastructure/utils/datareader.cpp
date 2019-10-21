#include <QFile>
#include <QFileInfo>
#include <QMetaType>
#include <QStringList>
#include <QVariant>
#include <QXmlStreamReader>
#include "infrastructure/utils/datareader.h"

DataReader::DataReader(QString file_name) : fileName(file_name)
{
}

DataCollection *DataReader::read()
{
    DataCollection *data_collection = new DataCollection();
    QFileInfo file_info(fileName);
    if (file_info.exists())
    {
        QXmlStreamReader xml_reader;
        QFile file(fileName);
        QObject *data_object = NULL;
        const char *property_name = NULL;

        file.open(QIODevice::ReadOnly);
        xml_reader.setDevice(&file);

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
                    data_object = reinterpret_cast<QObject *>(void_pointer);
                }
                else if (data_object != NULL)
                {
                    property_name = xml_element.toUtf8();
                }
                break;
            }
            case QXmlStreamReader::Characters:
            {
                if (property_name != NULL)
                {
                    data_object->setProperty(property_name, QVariant(xml_reader.text().toString()));
                }
                break;
            }
            case QXmlStreamReader::EndElement:
            {
                if (property_name != NULL)
                {
                    property_name = NULL;
                }
                else if (data_object != NULL)
                {
                    data_collection->add(data_object);
                    data_object = NULL;
                }
                break;
            }
            default:
                break;
            }
        }
        file.close();
    }
    return data_collection;
}
