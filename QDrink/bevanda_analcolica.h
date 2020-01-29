#ifndef BEVANDA_ANALCOLICA_H
#define BEVANDA_ANALCOLICA_H
#include "bevanda.h"

class bevanda_analcolica : public bevanda
{
public:
    bevanda_analcolica( const std::string&, const std::string&, const double&, const std::string&, const date&, const unsigned int&, const std::string& ar);
    virtual bool isAlcoholic () const override final;
    virtual bool isCarbonated() const =0;
    virtual ~bevanda_analcolica() override =default;
    std::string getAroma() const;
    void setAroma( const std::string& ar="nessun aroma");
    std::string getFields() const override;
private:
    std::string aroma;
};

#endif // BEVANDA_ANALCOLICA_H
