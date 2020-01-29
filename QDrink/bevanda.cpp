#include "bevanda.h"
#include <string>
#include <data.h>
#include <sstream>
#include <iomanip>
using std::string;
bevanda::bevanda(const std::string& n, const std::string& m, const double& p, const std::string& d, const date& s, const unsigned int& q): nome(n), marca(m), prezzo(p), descrizione(d), scadenza(s), quantita(q) {}

double bevanda::CalcPrezzoTot() const
{   if(quantita > 1)
    return prezzo*quantita;
    else {
        return prezzo;
    }
}

std::string bevanda::getNome() const
{
    return nome;
}

std::string bevanda::getMarca() const
{
    return marca;
}

double bevanda::getPrezzo() const
{
    return prezzo;
}

std::string bevanda::getDescrizione() const
{
    return descrizione;
}


date bevanda::getScadenza() const
{
    return scadenza;
}
unsigned int bevanda::getQuantita() const
{
    return quantita;
}

void bevanda::setNome(const std::string &n)
{
    nome=n;
}

void bevanda::setMarca(const std::string &m)
{
    marca=m;
}

void bevanda::setPrezzo(const double& p)
{
    prezzo=p;
}

void bevanda::setDescrizione(const std::string &d)
{
    descrizione=d;
}

void bevanda::setScadenza(const date &s)
{
    scadenza=s;
}

void bevanda::setQuantita(const unsigned int &q)
{
    quantita=q;
}

std::string bevanda::getFields() const
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << getPrezzo();
    std::string tot;
    //ss.str("nome : " + getNome()+ "\t\tmarca : " + getMarca()  +"\nprezzo : € "+std::to_string(getPrezzo()) + "\t\tdescrizione : " + getDescrizione() + "\ndata scadenza : " + getScadenza().convertToString()); //+ "\tquantità :" + std::to_string(getQuantita()));
    return tot.append("nome : " + getNome()).append("\nmarca : " + getMarca()).append("\nprezzo : "+ ss.str() + "€").append("\ndescrizione : " + getDescrizione()).append("\ndata scadenza : " + getScadenza().convertToString()).append("\nquantità : " + std::to_string(static_cast<int>((getQuantita()))));
    //retun ss << tot.append("nome : " + getNome()).append("\t\tmarca : " + getMarca()).append("\nprezzo : "+std::to_string(getPrezzo()) + "€").append("\t\tdescrizione : " + getDescrizione()).append("\ndata scadenza : " + getScadenza().convertToString()).append("\tquantità :" + std::to_string(static_cast<int>((getQuantita()))));

}





