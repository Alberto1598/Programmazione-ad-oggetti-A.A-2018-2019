#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "bevanda.h"
#include "birra.h"
#include "vino.h"
#include "te.h"
#include "data.h"
#include <QSaveFile>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QFileDialog>
#include <string>
class model
{
private:
    container <bevanda*> obj;
    container <bevanda*> search; // contiene gli elementi filtrati dalla ricerca
public:
    model()=default;
    ~model()= default;
    void b_push_back(bevanda*);
    void s_push_back(bevanda*);
    void b_popback();
    void b_insert(container<bevanda*>::iterator, bevanda*);
    void b_erase(container<bevanda*>::iterator);
    void b_eraseInt(unsigned int);
    void s_eraseInt(unsigned int);
    void b_clear();
    void s_clear();
    bevanda* b_GetinfoAt(unsigned int) const;
    bevanda* s_GetinfoAt(unsigned int) const;
    unsigned int b_getSize() const;
    unsigned int b_getCapacity() const;
    unsigned int s_getSize() const;
    container<bevanda*> :: iterator b_begin() const;
    container<bevanda*> :: iterator b_end() const;
    container<bevanda*> :: iterator s_begin() const;
    container<bevanda*> :: iterator s_end() const;
    container<bevanda*> :: const_iterator cb_begin() const;
    container<bevanda*> :: const_iterator cb_end() const;
    bevanda*& front();
    bevanda*& end();
    bool b_isAlcoholic(unsigned int) const;
    std::string b_getTipo(unsigned int) const;
    double b_calcPrezzoTot(unsigned int) const;
    void save(QString&) const;
    void load(std::string&);
    void research(  const std::string&, const double&, const std::string&, const bool&, const bool&); // filtra gli elementi di search che contiene una copia dei puntatori di obj
};

#endif // MODEL_H
