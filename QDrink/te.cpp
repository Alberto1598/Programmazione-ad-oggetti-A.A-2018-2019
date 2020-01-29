#include "te.h"

te::te(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q, const std::string& ar, const unsigned int& ti): bevanda_analcolica (n, m, p, d, s, q, ar), temperatura_infusione(ti){}

std::string te::tipo() const
{
    return "tè";
}

bool te::isCarbonated() const
{
    return false;
}

unsigned int te::getTemperaturaInfusione() const
{
    return temperatura_infusione;
}

void te::setTemperaturaInfusione(const unsigned int& ti)
{
    temperatura_infusione=ti;
}

std::string te::getFields() const
{
    std::string str;
    str=str.append("\ntemperatura infusione : "+ std::to_string(static_cast<int>(getTemperaturaInfusione()))+ "°").append("\t\tè gassata : ").append(isCarbonated()? "si" : "no");
    std::string tot;
    return tot.append(bevanda_analcolica::getFields()+ str);
}
