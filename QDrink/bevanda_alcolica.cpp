#include "bevanda_alcolica.h"
#include <string>
bevanda_alcolica::bevanda_alcolica(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q, const float& g, const unsigned int& c): bevanda(n, m, p, d, s, q), grado_alcolico(g), capacita(c) {}

bool bevanda_alcolica::isAlcoholic() const
{
    return true;
}

float bevanda_alcolica::volume_alcolico() const
{
    return (grado_alcolico*capacita)/100;
}

float bevanda_alcolica::getGrado_alcolico() const
{
    return grado_alcolico;
}

void bevanda_alcolica::setGrado_alcolico(const float &g)
{
    grado_alcolico=g;
}
unsigned int bevanda_alcolica::getCapacita() const
{
    return capacita;
}
void bevanda_alcolica::setCapacita(const unsigned int &c)
{
    capacita=c;
}

std::string bevanda_alcolica::getFields() const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << getGrado_alcolico();
    std::string str;
    std::string tot;
    str.append("\n è alcolica: ").append(isAlcoholic()? "si" : "no").append("\ngrado_alcolico : "+ ss.str() +"%").append("\ncapacità : " + std::to_string(static_cast<int>(getCapacita()))+ "cl");
    return tot.append(bevanda::getFields()+ str);

};

