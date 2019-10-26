#include "domain/character/character.h"

Character::Character(QString char_race, QString char_class) : m_race(char_race), m_class(char_class)
{
}

void Character::setRace(QString char_race)
{
    m_race = char_race;
}

void Character::setClass(QString char_class)
{
    m_class = char_class;
}

QString Character::getRace() const
{
    return m_race;
}

QString Character::getClass() const
{
    return m_class;
}
