#ifndef MODIFICA_H
#define MODIFICA_H
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <form.h>
#include <QLabel>
#include <QPushButton>
class controller;
class modifica : public QDialog
{
    Q_OBJECT
public:
    modifica(QWidget* p = nullptr);
    QLineEdit* getNome() const;
    QLineEdit* getPrezzo() const;
    QLineEdit* getMarca() const;
    QSpinBox* getQuantita() const;
    QDateEdit* getScadenza() const;
    QTextEdit* getDescrizione() const;
    QPushButton* getModify() const;
private:
    QWidget* parent;
    QLineEdit* nome;
    QLineEdit* prezzo;
    QLineEdit* marca;
    QSpinBox* quantita;
    QDateEdit* scadenza;
    QTextEdit* descrizione;
    form* formLayout;
    QPushButton* modify;
};

#endif // MODIFICA_H
