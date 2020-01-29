#include "data.h"

date::date(unsigned int g, unsigned int m, unsigned int a): giorno(g), mese(m), anno(a){}

unsigned int date::getGiorno() const
{
    return giorno;
}

unsigned int date::getMese() const
{
    return mese;
}

unsigned int date::getAnno() const
{
    return anno;
}

void date::setGiorno(const unsigned int &g)
{
    giorno=g;
}

void date::setMese(const unsigned int &m)
{
    mese=m;
}

void date::setAnno(const unsigned int &a)
{
    anno=a;
}

std::string date::convertToString() const
{
    std::string str;
    return str.append(std::to_string(static_cast<int>(getGiorno()))+ "/").append(std::to_string(static_cast<int>(getMese()))+ "/").append(std::to_string(static_cast<int>(getAnno())));
}

std::ostream &operator <<(std::ostream &os, const date& d)
{
    return os << d.getGiorno() << "-" << d.getMese() << "-" << d.getAnno();
}
