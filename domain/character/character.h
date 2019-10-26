#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QMetaType>
#include <QString>

class Character : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString race READ getRace WRITE setRace)
    Q_PROPERTY(QString class READ getClass WRITE setClass)
public:
    Character() {}
    Character(const Character &character) : QObject(character.parent())
    {
        m_race = character.m_race;
        m_class = character.m_class;
    }
    Character(QString char_race, QString char_class);

    QString getRace() const;
    QString getClass() const;

    void setRace(QString);
    void setClass(QString);

private:
    QString m_race;
    QString m_class;
};

Q_DECLARE_METATYPE(Character)

#endif // CHARACTER_H
