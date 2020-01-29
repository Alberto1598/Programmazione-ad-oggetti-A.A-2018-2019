#include "bevanda_analcolica.h"

bevanda_analcolica::bevanda_analcolica(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q, const std::string& ar): bevanda(n, m, p, d, s, q), aroma(ar){}

bool bevanda_analcolica::isAlcoholic() const
{
    return false;
}

std::string bevanda_analcolica::getAroma() const
{
    return aroma;
}

void bevanda_analcolica::setAroma(const std::string& ar)
{
    aroma=ar;
}

std::string bevanda_analcolica::getFields() const
{
    bevanda::getFields();
    std::string tot;
    std::string str;
    str=str.append("\nè alcolica:  ").append(isAlcoholic()? "si" : "no").append("\naroma : "+ getAroma());
    return tot.append(bevanda::getFields()+ str);
}


