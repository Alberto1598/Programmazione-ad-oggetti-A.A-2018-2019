#ifndef DATA_H
#define DATA_H
#include <ostream>
#include <QDate>
class date
{
public:
    date(unsigned int =0, unsigned int =0, unsigned int =0 );
    unsigned int getGiorno() const;
    unsigned int getMese() const;
    unsigned int getAnno() const;
    void setGiorno(const unsigned int& g=00);
    void setMese(const unsigned int& m=00);
    void setAnno(const unsigned int& a=00);
    std::string convertToString() const;
private:
    unsigned int giorno;
    unsigned int mese;
    unsigned int anno;
};
std::ostream& operator <<(std::ostream& os, const date&);
#endif // DATA_H
