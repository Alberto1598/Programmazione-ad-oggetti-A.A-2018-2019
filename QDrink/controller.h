#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QWidget>
#include "model.h"
#include "mywidgets.h"
#include <QWidget>
#include <mylist.h>
#include "data.h"
#include <QDialog>
#include <QFileDialog>
#include <visualizza.h>
#include <modifica.h>
#include <QAction>
#include <QMessageBox>
#include <string>
#include <bevanda.h>
#include <bevanda_alcolica.h>
#include <bevanda_analcolica.h>
#include <birra.h>
#include <vino.h>
#include <te.h>
#include <QList>
#include <QIcon>
#include <QList>
#include <iomanip>
class MainWindow;
class controller: public QWidget
{
    Q_OBJECT
public:
    controller(QWidget* =nullptr);
    int giveItem(QListWidget*, mylistItem*) const;
    bool correctInsert() const; //verifica se i campi obbligatori sono stati tutti riempiti
    mylistItem* ListItem(QListWidgetItem*) const;
private:
         MainWindow* window;
         model* m;
         visualizza* secondwindow; // puntatore alla schermata di ricerca
         modifica* thirdwindow;  // puntatore alla schermata di modifica
public slots:

         void addItem() const; // aggiunge una bevanda
         void modify() const; // modifica una bevanda
         void verify() const; // chiede all'utente di salvare prima di uscire
         void eraseSelectedItem() const; // elimina l'elemento selezionato
         void eraseAll() const; // elimina tutti gli elementi
         void calcPrezzoSelected() const; // calcola il prezzo totale dell'elemento selezionato
         void OpenDialog() const; // apre il dialog di ricerca
         void OpenModifyDialog() const; // apre il dialog di modifica
         void search() const; // ricerca filtrata degli elementi
         void eraseAllSearchedItem() const;// elimina tutti gli elementi ricercati dall'utente
         void save() const; // salvataggio su file
         void load(); // caricamento da file


};

#endif // CONTROLLER_H
