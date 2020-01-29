#include "model.h"

void model::b_push_back(bevanda *b)
{
    obj.push_back(b);
}

void model::s_push_back(bevanda *b)
{
    search.push_back(b);
}

void model::b_popback()
{
    obj.pop_back();
}

void model::b_insert(container<bevanda*>::iterator it, bevanda *b)
{
    obj.insert(it, b);
}

void model::b_erase(container<bevanda*>::iterator it)
{
    obj.erase(it);
}

void model::b_eraseInt(unsigned int index)
{
    obj.erase(index);
}

void model::s_eraseInt(unsigned int index)
{
    search.erase(index);
}

void model::b_clear()
{
    obj.clear();
}

void model::s_clear()
{
    search.clear();
}


bevanda *model::b_GetinfoAt(unsigned int t) const
{
    return obj.at(t);
}

bevanda *model::s_GetinfoAt(unsigned int t) const
{
    return search.at(t);
}

unsigned int model::b_getSize() const
{
    return obj.getSize();
}

unsigned int model::b_getCapacity() const
{
    return obj.getCapacity();
}

unsigned int model::s_getSize() const
{
    return search.getSize();
}

container<bevanda*>::iterator model::b_begin() const
{
    return obj.begin();
}

container<bevanda*>::iterator model::b_end() const
{
    return obj.end();
}

container<bevanda*>::iterator model::s_begin() const
{
    return search.begin();
}

container<bevanda*>::iterator model::s_end() const
{
    return search.end();
}

container<bevanda*>::const_iterator model::cb_begin() const
{
    return obj.cbegin();
}

container<bevanda*>::const_iterator model::cb_end() const
{
    return obj.cend();
}

bevanda *&model::front()
{
    return obj.front();
}

bevanda *&model::end()
{
    return obj.back();
}

bool model::b_isAlcoholic(unsigned int i) const
{
    return obj[i]->isAlcoholic(); // chiamata polimorfa
}

std::string model::b_getTipo(unsigned int i) const
{
    return obj[i]->tipo(); // chiamata polimorfa
}

double model::b_calcPrezzoTot(unsigned int i) const
{
    return obj[i]->CalcPrezzoTot(); // chiamata polimorfa
}

void model::save(QString& f) const
{
    QString path(f);
    QSaveFile filename(path);
    if(!filename.open(QIODevice::WriteOnly)){
        throw std::exception();
    }
    QXmlStreamWriter writer(&filename);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("root");
    auto it= obj.cbegin();
    while(it!=obj.cend()){
          const bevanda* toSave= *(it);
          std::string tipo= toSave->tipo();
          writer.writeEmptyElement(QString::fromStdString(tipo));
          writer.writeAttribute("nome", QString::fromStdString(toSave->getNome()));
          writer.writeAttribute("marca", QString::fromStdString(toSave->getMarca()));
          writer.writeAttribute("prezzo", QString::fromStdString(std::to_string(toSave->getPrezzo())));
          writer.writeAttribute("descrizione", QString::fromStdString(toSave->getDescrizione()));
          writer.writeAttribute("scadenza", QString::fromStdString(toSave->getScadenza().convertToString()));
          writer.writeAttribute("quantita",QString::fromStdString(std::to_string(toSave->getQuantita())));
          if(toSave->tipo()=="birra"){
              const birra* b= static_cast< const birra*>(toSave);
              writer.writeAttribute("grado_alcolico", QString::fromStdString(std::to_string(b->getGrado_alcolico())));
              writer.writeAttribute("capacita",QString::fromStdString(std::to_string(b->getCapacita())));
              writer.writeAttribute("colore", QString::fromStdString(b->getColore()));
          }
          if(toSave->tipo()=="vino"){
              const vino* v= static_cast< const vino*>(toSave);
              writer.writeAttribute("grado_alcolico", QString::fromStdString(std::to_string(v->getGrado_alcolico())));
              writer.writeAttribute("capacita",QString::fromStdString(std::to_string(v->getCapacita())));
              writer.writeAttribute("tipologia", QString::fromStdString(v->getTipologia()));
              writer.writeAttribute("regione", QString::fromStdString(v->getRegione()));
          }
          if(toSave->tipo()=="tè"){
             const te* t= static_cast<const te*>(toSave);
             writer.writeAttribute("temperatura_infusione", QString::fromStdString(std::to_string(t->getTemperaturaInfusione())));
             writer.writeAttribute("aroma",QString::fromStdString((t->getAroma())));
          }
          ++it;
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    filename.commit();
}

void model::load(std::string& filename)
{
    QFile file(QString::fromStdString(filename));
    if(!file.open(QIODevice::ReadOnly)){
        qWarning() << "non è stato possibile aprire il file";
     }
    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                    bevanda* drink=nullptr;
                    const QXmlStreamAttributes attributes = reader.attributes();
                    std::string type= reader.name().toString().toStdString();
                    std::string nome= attributes.value("nome").toString().toStdString();
                    std::string marca= attributes.value("marca").toString().toStdString();
                    double prezzo= attributes.value("prezzo").toDouble();
                    std::string descrizione= attributes.value("descrizione").toString().toStdString();
                    date scadenza;
                    QDate toconvert= QDate::fromString(attributes.value("scadenza").toString(), "d/M/yyyy");
                    scadenza.setGiorno(static_cast <unsigned int>(toconvert.day()));
                    scadenza.setMese(static_cast <unsigned int>(toconvert.month()));
                    scadenza.setAnno(static_cast <unsigned int>(toconvert.year()));
                    //scadenza.convertFromQDate(QDate::fromString(attributes.value("scadenza").toString(), "d/M/yyyy"));
                    unsigned int quantita=attributes.value("quantita").toUInt();
                    if(type== "birra"){
                        float grado= static_cast<float>(attributes.value("grado_alcolico").toString().toDouble());
                        std::string colore= attributes.value("colore").toString().toStdString();
                        unsigned int capacita= attributes.value("capacita").toString().toUInt();
                        drink= new birra(nome, marca, prezzo, descrizione, scadenza, quantita, grado, capacita, colore);
                        b_push_back(drink);
                    }
                    if(type=="vino"){
                        float grado= static_cast <float>(attributes.value("grado_alcolico").toString().toDouble());
                        unsigned int capacita= attributes.value("capacita").toString().toUInt();
                        std::string regione= attributes.value("regione").toString().toStdString();
                        std::string tipologia= attributes.value("tipologia").toString().toStdString();
                        drink= new vino(nome, marca, prezzo, descrizione, scadenza, quantita, grado, capacita, tipologia, regione);
                        b_push_back(drink);
                    }
                    if(type=="tè"){
                        std::string aroma= attributes.value("aroma").toString().toStdString();
                        unsigned int temperatura=attributes.value("temperatura_infusione").toString().toUInt();
                        drink= new te(nome, marca, prezzo, descrizione, scadenza, quantita, aroma, temperatura);
                        b_push_back(drink);
                    }
                    reader.skipCurrentElement();
                }
            }
        }
    file.close();
}

void model::research(const std::string& name, const double& price, const std::string& type, const bool& alcoholic, const bool& more)
{
    bool noEmpty= false;
    if(search.getSize()>0) s_clear();
    for(unsigned int i=0; i<b_getSize();i++){
        bevanda*drink= b_GetinfoAt(i);
        s_push_back(drink);
    }
    if(name!="nessun nome"){
        noEmpty=true;
        for(auto it= s_begin(); it!=s_end(); ++it){
            if (name!=(*(it))->getNome()){
                search.erase(it);
                it--;
            }
        }
    }
    if(price>=0){
        noEmpty=true;
        if(more){
            for(auto it= s_begin(); it!=s_end(); ++it){
                if (price>=(*(it))->getPrezzo()){
                    search.erase(it);
                    it--;
                }
            }
        }
        else{
            for(auto it= s_begin(); it!=s_end(); ++it){
                if (price<=(*(it))->getPrezzo()){
                    search.erase(it);
                    it--;
                }
            }
        }
    }
    if (type!="--"){
        noEmpty=true;
        for(auto it= s_begin(); it!=s_end(); ++it){
            if (type!=(*(it))->tipo()){
                search.erase(it);
                it--;
            }
        }
    }
    if(alcoholic){
        noEmpty=true;
        for(auto it= s_begin(); it!=s_end(); ++it){
            if ((!(*it)->isAlcoholic())){
                search.erase(it);
                it--;
            }
        }
    }
    if(!noEmpty){
        s_clear();
    }
}









