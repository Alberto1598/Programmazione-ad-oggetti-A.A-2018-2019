#ifndef BEVANDA_ALCOLICA_H
#define BEVANDA_ALCOLICA_H
#include "bevanda.h"
#include <string>
class bevanda_alcolica : public bevanda
{
public:
    bevanda_alcolica(const std::string&, const std::string&, const double&, const std::string&, const date&, const unsigned int&, const float&, const unsigned int&);
    virtual bool isAlcoholic () const override final;
    virtual ~bevanda_alcolica() override =default;
    unsigned int getCapacita() const;
    float getGrado_alcolico() const;
    void setGrado_alcolico(const float& =0);
    void setCapacita (const unsigned int& =0);
    virtual std::string getFields() const override;
private:
    float grado_alcolico; // %/volume
    unsigned int capacita;  // le bevande alcoliche vengono memorizzate in bottiglie di cui si vuole sapere la capacità:
protected:
    float volume_alcolico () const; // metodo protetto di utilità, che non verrà utilizzato dall'utente

};

#endif // BEVANDA_ALCOLICA_H
