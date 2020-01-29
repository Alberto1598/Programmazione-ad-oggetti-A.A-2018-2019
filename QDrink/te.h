#ifndef TE_H
#define TE_H
#include "bevanda_analcolica.h"

class te : public bevanda_analcolica
{
public:
    te(const std::string& = " nessun nome ", const std::string& =" nessuna marca ", const double& = 2.00, const std::string& ="nessuna descrizione", const date& =00-00-00, const unsigned int& =0, const std::string& ="nessun aroma", const unsigned int& = 90 );
    virtual std::string tipo() const override;
    virtual bool isCarbonated() const override;
    unsigned int getTemperaturaInfusione() const;
    void setTemperaturaInfusione(const unsigned int& ti=90);
    std::string getFields() const override;
private:
    unsigned int temperatura_infusione;
};

#endif // TE_H
