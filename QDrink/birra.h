#ifndef BIRRA_H
#define BIRRA_H
#include "bevanda_alcolica.h"

class birra : public bevanda_alcolica
{
public:
    birra(const std::string& = " nessun nome ", const std::string& =" nessuna marca ", const double& = 2.00, const std::string& ="nessuna descrizione", const date& =00-00-00, const unsigned int& =0, const float& =5.00, const unsigned int& = 50, const std::string& ="bionda");
    virtual std::string tipo() const override;
    virtual double CalcPrezzoTot() const override;
    std:: string getColore() const;
    void setColore (const std::string co="bionda");
    std::string getFields() const override final;
private:
    std::string colore;
    static double tassa;
};

#endif // BIRRA_H
