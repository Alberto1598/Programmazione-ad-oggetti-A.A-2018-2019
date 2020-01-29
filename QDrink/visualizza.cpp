#include "visualizza.h"

visualizza::visualizza(QWidget* p): parent(p), lista(new QListWidget()), MainLayout( new QVBoxLayout()), firstLayout(new QVBoxLayout), SecondLayout(new QHBoxLayout), Buttonlayout(new QHBoxLayout), nome( new QLineEdit()), prezzo(new QLineEdit()), type(new QComboBox()), isAlcoholic(new QCheckBox(this)), search(new QPushButton(this)), clear(new QPushButton()), Delete(new QPushButton()), formlayout(new form(this)), formlayout2(new form(this)), groupboxlayout(new QHBoxLayout(this)), lessThan(new QRadioButton(this)), moreThan(new QRadioButton(this))
{
    setWindowTitle("ricerca ed eliminazione");
    setMinimumSize(500, 500);
    lista->setIconSize(QSize(60,60));
    moreThan->setChecked(true);
    moreThan-> setText(": maggiori di prezzo");
    lessThan->setText(": minori di prezzo");
    setModal(true);
    search->setText("ricerca elementi");
    clear->setText("pulisci campi");
    Delete->setText("elimina tutti gli elementi ricercati");
    Delete->setContentsMargins(230, 200, 200, 200);
    Delete->setFixedSize(QSize(230, 30));


    QGroupBox* groupbox= new QGroupBox(this);
    groupbox->setTitle("filtri di ricerca");

    lista->setSpacing(5);
    nome->setFixedWidth(100);
    prezzo->setFixedWidth(100);
    type->addItem("--");
    type->addItem("birra");
    type->addItem("tè");
    type->addItem("vino");
    formlayout2->setFormAlignment(Qt::AlignLeft);
    formlayout->setFormAlignment(Qt::AlignTop);
    formlayout->addRow(new QLabel(tr("nome: ")), nome);
    formlayout2->addRow(new QLabel(tr("prezzo: ")), prezzo);
    formlayout2->addRow(moreThan, lessThan);
    formlayout->addRow(new QLabel(tr("tipo: ")), type);
    formlayout2->addRow(new QLabel(tr("è alcolica: ")), isAlcoholic);
    groupboxlayout->addLayout(formlayout);
    groupboxlayout->addLayout(formlayout2);
    groupbox->setLayout(groupboxlayout);


    firstLayout->addWidget(groupbox);
    Buttonlayout-> addWidget(search);
    Buttonlayout-> addWidget(clear);
    SecondLayout->addWidget(lista);
    MainLayout->addLayout(firstLayout);
    MainLayout->addLayout(Buttonlayout);
    MainLayout->addLayout(SecondLayout);
    MainLayout->addWidget(Delete);
    setLayout(MainLayout);


    connect(clear, SIGNAL(clicked()), this, SLOT(clearFields()));
}

void visualizza::setList(QListWidget * list)
{
    lista=list;
}

QListWidget *visualizza::getLista() const
{
    return lista;
}

QVBoxLayout *visualizza::getMainlayout() const
{
    return MainLayout;
}

QVBoxLayout *visualizza::getFirstlayout() const
{
    return firstLayout;
}

QHBoxLayout *visualizza::getSecondLayout() const
{
    return SecondLayout;
}

QLineEdit *visualizza::getNome() const
{
    return nome;
}

QLineEdit *visualizza::getPrezzo() const
{
    return prezzo;
}

QComboBox *visualizza::getType() const
{
    return type;
}

QCheckBox *visualizza::getIsAlcoholic() const
{
    return isAlcoholic;
}

QPushButton *visualizza::getsearch() const
{
    return search;
}

QPushButton *visualizza::getClear() const
{
    return clear;
}

QPushButton *visualizza::getDelete() const
{
    return Delete;
}

QRadioButton *visualizza::getMoreThan() const
{
    return moreThan;
}

QRadioButton *visualizza::getLessThan() const
{
    return lessThan;
}

void visualizza::clearFields() const
{
    nome->clear();
    prezzo->clear();
    type->setCurrentText("--");
}



