#include "birra.h"

birra::birra(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q,  const float& g, const unsigned int& c, const std::string& co): bevanda_alcolica(n, m, p, d, s, q, g, c), colore(co){}

std::string birra::tipo() const
{
    return "birra";
}
double birra :: tassa = 0.0304; // in euro
double birra::CalcPrezzoTot() const
{

    return bevanda::CalcPrezzoTot()+ getQuantita()* tassa* static_cast <double> (volume_alcolico()); // safe cast
}

std::string birra::getColore() const
{
    return colore;
}

void birra::setColore(const std::string co)
{
    colore=co;
}

std::string birra::getFields() const
{
    std::string str;
    str.append("\t\tcolore : " +getColore());
    std::string tot;
    tot=tot.append(bevanda_alcolica::getFields()+ str);
    return tot;
}





