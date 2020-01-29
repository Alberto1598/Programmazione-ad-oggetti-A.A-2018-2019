#include "modifica.h"

modifica::modifica(QWidget* p): parent(p), nome(new QLineEdit(this)), prezzo(new QLineEdit(this)), marca(new QLineEdit(this)), quantita(new QSpinBox(this)), scadenza(new QDateEdit(this)), descrizione(new QTextEdit(this)), formLayout(new form(this)), modify(new QPushButton(this))
{
    QVBoxLayout* mainLayout= new QVBoxLayout();
    QHBoxLayout* firstLayout= new QHBoxLayout();
    modify->setText("modifica elemento");
    setModal(true);
    setWindowTitle("modifica elementi");
    nome->setMinimumWidth(100);
    prezzo->setMinimumWidth(100);
    prezzo->setValidator(new QDoubleValidator());
    quantita->setMaximum(500);
    quantita->setMinimum(1);
    formLayout->addRow(new QLabel(tr("Nome")), nome);
    formLayout->addRow(new QLabel(tr("Marca")), marca);
    formLayout->addRow(new QLabel(tr("Prezzo")), prezzo);
    formLayout->addRow(new QLabel(tr("Scadenza")), scadenza);
    formLayout->addRow(new QLabel(tr("Quantità")), quantita);
    formLayout->addRow(new QLabel(tr("Descrizione")), descrizione);
    firstLayout->addWidget(modify);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(firstLayout);
    mainLayout->addWidget(modify);
    setLayout(mainLayout);

}

QLineEdit *modifica::getNome() const
{
    return nome;
}

QLineEdit *modifica::getPrezzo() const
{
    return prezzo;
}

QLineEdit *modifica::getMarca() const
{
    return marca;
}

QSpinBox *modifica::getQuantita() const
{
    return quantita;
}

QDateEdit *modifica::getScadenza() const
{
    return scadenza;
}

QTextEdit *modifica::getDescrizione() const
{
    return descrizione;
}

QPushButton *modifica::getModify() const
{
    return modify;
}
