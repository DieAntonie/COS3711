#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

class XmlSerializer : public QProcess
{
    Q_OBJECT
public:
    XmlSerializer();

signals:
    void serialized(QIODevice *);
    void deserialized(QObject *);

public slots:
    QIODevice *serialize(QObject *data_object);
    QObject *deserialize(QIODevice *data_source);

private:
    QXmlStreamWriter xml_writer;
    QXmlStreamReader xml_reader;
};

#endif // XMLSERIALIZER_H
