#include "vino.h"

vino::vino(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q,  const float& g, const unsigned int& c, const std::string& ti, const std::string& re): bevanda_alcolica(n, m, p, d, s, q, g, c), tipologia(ti), regione(re){}

std::string vino::tipo() const
{
    return "vino";
}

std::string vino::getTipologia() const
{
    return tipologia;
}

std::string vino::getRegione() const
{
    return regione;
}

void vino::setTipologia(const std::string& ti)
{
    tipologia=ti;
}

void vino::setRegione(const std::string& re)
{
    regione=re;
}

std::string vino::getFields() const
{
    std::string str;
    str.append("\ntipologia : "+ getTipologia()).append("\t\tregione : " + getRegione());
    std::string tot;
    return tot.append(bevanda_alcolica::getFields()+ str);
};

