#include "controller.h"
#include "mainwindow.h"
using std::string;
controller::controller(QWidget* parent): QWidget(parent),  window(new MainWindow(this)),
    m(new model()),  secondwindow(new visualizza(this)), thirdwindow(new modifica(this)){
     connect(window->getEsc(), SIGNAL(triggered()), this, SLOT(verify()));
    connect(window->getIns(), SIGNAL(clicked()), this, SLOT(addItem()));
    connect(window->getCalctoto(), SIGNAL(clicked()), this, SLOT(calcPrezzoSelected()));
    connect(window->getRemove(), SIGNAL(clicked()), this, SLOT(eraseSelectedItem()));
    connect(window->getSearch(), SIGNAL(triggered()), this, SLOT(OpenDialog()));
    connect(window->getView(), SIGNAL(clicked()), this, SLOT(OpenModifyDialog()));
    connect(secondwindow->getsearch(),SIGNAL(clicked()), this, SLOT(search()));
    connect(secondwindow->getDelete(), SIGNAL(clicked()), this, SLOT(eraseAllSearchedItem()));
    connect(thirdwindow->getModify(), SIGNAL(clicked()), this, SLOT(modify()));
    connect(window->getSave(), SIGNAL(triggered()),this, SLOT(save()));
    connect(window->getLoad(), SIGNAL(triggered()),this, SLOT(load()));
    connect(window->getEraseAll(), SIGNAL(clicked()),this, SLOT(eraseAll()));
}

void controller::eraseSelectedItem() const
{
    QList<QListWidgetItem*> list= window->getDrinkList()->selectedItems();
    if(m->b_getSize()>0 && list.count()!=0){
        int index= window->getDrinkList()->currentRow();
        auto it= m->b_begin();
        for(;it!=m->b_end() && *(it)!=m->b_GetinfoAt(static_cast <unsigned int>(index)); it++);
        m->b_erase(it);
        mylistItem* item=ListItem(window->getDrinkList()->takeItem((index)));
        delete item;
    }
}

void controller::eraseAll() const
{
    if(window->getDrinkList()->count()>0){
        QMessageBox Box;
        Box.setIcon(QMessageBox::Critical);
        Box.setWindowTitle("eliminazione di tutti gli elementi");
        Box.setText("eliminare tutti gli elementi presenti ?");
        Box.addButton(QMessageBox::Yes);
        Box.addButton(QMessageBox::No);
        if(Box.exec()== QMessageBox::Yes){
            for(int i=0; i<window->getDrinkList()->count(); i++){
                mylistItem* itemWindow= ListItem(window->getDrinkList()->takeItem(i));
                m->b_eraseInt(static_cast<unsigned int>(i));
                i--;
                delete itemWindow;
            }
            secondwindow->getLista()->clear();
        }
    }

}


void controller::calcPrezzoSelected() const
{
    QList<QListWidgetItem*> list= window->getDrinkList()->selectedItems();
    if(m->b_getSize()>0 && list.count()!=0){
        unsigned int itemrow= static_cast<unsigned int> (window->getDrinkList()->currentRow());
        double prezzo= m->b_calcPrezzoTot(itemrow);
        std::string text;
        std::stringstream tot;
        tot << std::fixed << std::setprecision(2) << prezzo;
        text.append ("importo totale : " +tot.str()+ "€");
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setInformativeText(QString::fromStdString(text));
        msg.setWindowTitle("Prezzo totale");
        msg.size();
        msg.exec();
    }
}

void controller::OpenDialog() const
{
    secondwindow->getNome()->clear();
    secondwindow->getPrezzo()->clear();
    secondwindow->getIsAlcoholic()->setChecked(false);
    secondwindow->getType()->setCurrentText("--");
    secondwindow->getLista()->clear();
    m->s_clear();
    secondwindow->show();
}

void controller::OpenModifyDialog() const
{
    QList<QListWidgetItem*> list= window->getDrinkList()->selectedItems();
    if(list.size()>0){
        thirdwindow->getQuantita()->setValue(static_cast <int>(ListItem(list.first())->getBevanda()->getQuantita()));
        QDate data;
        data.setDate(static_cast<int>(ListItem(list.first())->getBevanda()->getScadenza().getAnno()),static_cast<int>(ListItem(list.first())->getBevanda()->getScadenza().getMese()),static_cast<int>(ListItem(list.first())->getBevanda()->getScadenza().getGiorno()));
        thirdwindow->getScadenza()->setDate(data);
        thirdwindow->show();
   }
}

void controller::search() const{
    secondwindow->getLista()->clear();
    if(window->getDrinkList()->count()>0){
        string nome="nessun nome";
        string tipo;
        double prezzo=-1;
        bool moreOrless;
        bool alcolico;
        if(!(secondwindow->getNome()->text().isEmpty()))nome=secondwindow->getNome()->text().toStdString();
        tipo=secondwindow->getType()->currentText().toStdString();
        if(!(secondwindow->getPrezzo()->text().isEmpty())) prezzo=secondwindow->getPrezzo()->text().toDouble();
        if(secondwindow->getMoreThan()->isChecked()){
            moreOrless=true;
        }
        else{
            moreOrless=false;
        }
        alcolico = secondwindow->getIsAlcoholic()->isChecked();
        m->research(nome, prezzo, tipo, alcolico, moreOrless);
        for(unsigned int i=0; i<m->s_getSize(); i++){
            mylistItem* item= new mylistItem(m->s_GetinfoAt(i));
            secondwindow->getLista()->addItem(item->TransformItem());
        }
    }
}

void controller::eraseAllSearchedItem() const
{
    for(int i=0; i<secondwindow->getLista()->count(); i++){
        mylistItem* itemSecondwindow= ListItem(secondwindow->getLista()->item(i));
        int index= giveItem(window->getDrinkList(), itemSecondwindow);
        mylistItem* itemWindow= ListItem(window->getDrinkList()->takeItem(index));
        m->b_eraseInt(static_cast<unsigned int>(index));
        delete itemWindow;
    }
    m->s_clear();
    secondwindow->getLista()->clear();
}

void controller::save() const
{
    try {
      QString filename = QFileDialog::getSaveFileName(window, "Save File", "../progetto/QDrink/Salvataggi/", "XML files (*.xml)");
      m->save(filename);
    } catch (std::exception)
    {
        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
        box.exec();
    }
}

void controller::load()
{
    try {
      QString filEname = QFileDialog::getOpenFileName(window, "load file", "../progetto/QDrink/Salvataggi/", "XML files (*.xml)");
      string filename= filEname.toStdString();
      m->load(filename);
      window->getDrinkList()->clear();
      for(unsigned int i=0; i<m->b_getSize(); i++){
          mylistItem* toPush= new mylistItem(m->b_GetinfoAt(i));
          window->getDrinkList()->addItem(toPush->TransformItem());
      }
    } catch (std::exception)
    {
        QMessageBox box(QMessageBox::Warning, "Errore di caricamento", "Non è stato possibile leggere da file", QMessageBox::Ok);
        box.exec();
    }
}


void controller::addItem() const
{
    if(correctInsert()){
        string tipo= window->getWidget()->getType()->currentText().toStdString();
        bevanda* drink=nullptr;
        string nome= window->getWidget()->getName()->text().toStdString();
        string label= window->getWidget()->getLabel()->text().toStdString();
        double prezzo= window->getWidget()->getPrice()->text().toDouble();
        string descrizione= window->getWidget()->getDescription()->toPlainText().toStdString();
        date scadenza;
        scadenza.setGiorno(static_cast <unsigned int>(window->getWidget()->getDeadline()->date().day()));
        scadenza.setMese(static_cast <unsigned int>(window->getWidget()->getDeadline()->date().month()));
        scadenza.setAnno(static_cast <unsigned int>(window->getWidget()->getDeadline()->date().year()));
        unsigned int quantita=window->getWidget()->getNumber()->text().toUInt();

        if(window->getWidget()->getType()->currentText().toStdString()== "birra"){
            float grado= window->getWidget()->getGrade()->text().toFloat();
            unsigned int capacita=window->getWidget()->getCapacity()->text().toUInt();
            string colore= window->getWidget()->getColour()->currentText().toStdString();
            drink= new birra(nome, label, prezzo, descrizione, scadenza, quantita, grado, capacita, colore);
            m->b_push_back(drink);
            mylistItem* item= new mylistItem(drink);
            window->getDrinkList()->addItem(item->TransformItem());
        }

        if(window->getWidget()->getType()->currentText().toStdString()=="vino"){
            float grado= window->getWidget()->getGrade()->text().toFloat();
            unsigned int capacita=window->getWidget()->getCapacity()->text().toUInt();
            string tipologia= window->getWidget()->getTipo()->text().toStdString();
            string regione= window->getWidget()->getCountry()->text().toStdString();
            drink= new vino(nome, label, prezzo, descrizione, scadenza, quantita, grado, capacita, tipologia, regione);
            m->b_push_back(drink);
            mylistItem* item= new mylistItem(drink);
            window->getDrinkList()->addItem(item->TransformItem());
        }

        if (window->getWidget()->getType()->currentText().toStdString()=="tè"){
            string aroma=window->getWidget()->getFlavour()->text().toStdString();
            unsigned int temperatura= window->getWidget()->getTemperature()->text().toUInt();
            drink= new te(nome, label, prezzo, descrizione, scadenza, quantita, aroma, temperatura);
            m->b_push_back(drink);
            mylistItem* item= new mylistItem(drink);
            window->getDrinkList()->addItem(item->TransformItem());
        }
    }
}

void controller::modify() const
{
    QList<QListWidgetItem*> list= window->getDrinkList()->selectedItems();
    mylistItem* item= ListItem(list.front());
    date scadenza;
    if(!(thirdwindow->getNome()->text().isEmpty())) item->getBevanda()->setNome(thirdwindow->getNome()->text().toStdString());
    if(!(thirdwindow->getMarca()->text().isEmpty())) item->getBevanda()->setMarca(thirdwindow->getMarca()->text().toStdString());
    if(!(thirdwindow->getPrezzo()->text().isEmpty())) item->getBevanda()->setPrezzo(thirdwindow->getPrezzo()->text().toDouble());
    scadenza.setGiorno(static_cast <unsigned int>(thirdwindow->getScadenza()->date().day()));
    scadenza.setMese(static_cast <unsigned int>(thirdwindow->getScadenza()->date().month()));
    scadenza.setAnno(static_cast<unsigned int>(thirdwindow->getScadenza()->date().year()));
    item->getBevanda()->setScadenza(scadenza);
    item->getBevanda()->setQuantita(thirdwindow->getQuantita()->text().toUInt());
    if(!(thirdwindow->getDescrizione()->toPlainText().isEmpty())) item->getBevanda()->setDescrizione(thirdwindow->getDescrizione()->toPlainText().toStdString());
    item->setText(QString::fromStdString( item->getBevanda()->getFields()));
    thirdwindow->close();
}

void controller::verify() const
{
    if(window->getDrinkList()->count()>0){
        QMessageBox save;
        save.setIcon(QMessageBox::Question);
        save.setWindowTitle("salvataggio");
        save.setText("desideri salvare gli elementi presenti ?");
        QPushButton* yesButton= new QPushButton();
        yesButton->setText("yes");
        save.addButton(QMessageBox::Yes);
        save.addButton(QMessageBox::No);
        if(save.exec()== QMessageBox::No){
            QApplication::quit();
        }
        else{
            controller::save();
            QApplication::quit();
        }
    }
    else{
        QApplication::quit();
    }
}
int controller::giveItem(QListWidget * list, mylistItem * item) const
{
    int i;
    for( i=0; i<list->count() && ListItem(list->item(i))->getBevanda()!= item->getBevanda(); i++);
    return i;
}
mylistItem *controller::ListItem(QListWidgetItem * p) const
{
    return static_cast <mylistItem*>(p);
}

bool controller::correctInsert() const
{
    if(window->getWidget()->getType()->currentText().toStdString()=="selezionare tipo"){
        QMessageBox msg;
        msg.setWindowTitle("inserimento fallito");
        msg.setInformativeText("selezionare il tipo di bevanda!");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return false;
    }
    if(window->getWidget()->getName()->text().isEmpty() || window->getWidget()->getLabel()->text().isEmpty() || window->getWidget()->getPrice()->text().isEmpty()){
        QMessageBox msg;
        msg.setWindowTitle("inserimento fallito");
        msg.setInformativeText("riempire i campi obbligatori, verificare i campi nome, marca e prezzo");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return false;
    }
    if(window->getWidget()->getType()->currentText().toStdString()!="tè" && ((window->getWidget()->getGrade()->text().isEmpty() || window->getWidget()->getCapacity()->text().isEmpty()))){
        QMessageBox msg;
        msg.setWindowTitle("inserimento fallito");
        msg.setInformativeText("riempire i campi obbligatori, verificare i campi grado alcolico e capacità");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
        return false;
    }
    return true;
}






