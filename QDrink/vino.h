#ifndef VINO_H
#define VINO_H
#include "bevanda_alcolica.h"

class vino: public bevanda_alcolica
{
public:
    vino(const std::string& = " nessun nome ", const std::string& =" nessuna marca ", const double& = 2.00, const std::string& ="nessuna descrizione", const date& = 00-00-00, const unsigned int& =0, const float& =5.00, const unsigned int& = 50, const std::string& tipologia="nessuna tipologia", const std::string& regione="italia");
    virtual std::string tipo() const override;
    std::string getTipologia() const;
    std::string getRegione() const;
    void setTipologia(const std::string& ti = "nessuna tipologia");
    void setRegione( const std::string& re = "Italia");
    std::string getFields() const override final;
private:
    std::string tipologia;
    std::string regione; // regione o stato di provenienza;
};

#endif // VINO_H
