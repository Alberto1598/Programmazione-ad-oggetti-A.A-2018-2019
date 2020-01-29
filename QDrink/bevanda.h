#ifndef BEVANDA_H
#define BEVANDA_H
#include <string>
#include "data.h"
#include <iostream>
#include <iomanip>
#include <sstream>
class bevanda
{
public:
    bevanda(const std::string&, const std::string&, const double&, const std::string&, const date&, const unsigned int&);
    virtual std::string tipo() const = 0;
    virtual ~bevanda() =default;
    virtual bool isAlcoholic () const = 0;
    virtual double CalcPrezzoTot() const;
    std::string getNome() const;
    std::string getMarca() const;
    double getPrezzo() const;
    std::string getDescrizione() const;
    date getScadenza() const;
    unsigned int getQuantita () const;
    void setNome(const std::string& ="nessun nome");
    void setMarca(const std::string& ="nessuna marca");
    void setPrezzo(const double&);
    void setDescrizione(const std::string& ="nessuna descrizione");
    void setScadenza(const date& = 00-00-00);
    void setQuantita(const unsigned int& =0);
    virtual std::string getFields() const;
private:
    std::string nome;
    std:: string marca;
    double prezzo;
    std:: string descrizione;
    date scadenza;// giorno mese anno
    unsigned int quantita;


};


#endif // BEVANDA_H
