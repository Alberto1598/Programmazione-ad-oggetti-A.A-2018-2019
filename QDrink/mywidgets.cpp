#include "mywidgets.h"
#include "form.h"
#include "QString"
mywidgets::mywidgets(QWidget *parent): QWidget(parent),  name(new QLineEdit(this)), label(new QLineEdit(this)), price(new QLineEdit(this)), deadline(new QDateEdit(this)),
         number(new QSpinBox(this)), type(new QComboBox(this)), description(new QTextEdit(this)), grade(new QLineEdit(this)), flavour(new QLineEdit(this)), carbonated(new QCheckBox(this)), colour(new QComboBox(this)),
         tipo(new QLineEdit(this)), country(new QLineEdit(this)), capacity( new QLineEdit(this)),temperature(new QSpinBox(this)), f(new form(this)), g(new form(this))

{
    f->setHorizontalSpacing(30);
    g->setHorizontalSpacing(30);
    name->setMinimumWidth(100);
    label->setMinimumWidth(100);
    carbonated->setEnabled(false);
    temperature->setMaximum(200);
    price->setValidator(new QDoubleValidator());
    capacity->setValidator(new QDoubleValidator());
    grade->setValidator(new QDoubleValidator());
    number->setMaximum(500);
    number->setMinimum(1);
    type->addItem("selezionare tipo");
    type->addItem("vino");
    type->addItem("birra");
    type->addItem("tè");
    f->addRow(new QLabel(tr("Nome")), name);
    f->addRow(new QLabel(tr("Marca")), label);
    f->addRow(new QLabel(tr("Prezzo (in €)")), price);
    f->addRow(new QLabel(tr("Scadenza")), deadline);
    f->addRow(new QLabel(tr("Quantità")), number);
    f->addRow(new QLabel(tr("Tipo")), type);
    f->addRow(new QLabel(tr("Descrizione")), description);

    //form per groupbox 2
    colour->addItem("nessun colore");
    colour->addItem("bionda");
    colour->addItem("chiara");
    colour->addItem("rossa");
    colour->addItem("ambrata");
    colour->addItem("scura");
    g->addRow(new QLabel(tr("capacità (in cl)")), capacity);
    g->addRow(new QLabel(tr("grado alcolico")), grade);
    g->addRow(new QLabel(tr("aroma")), flavour);
    g->addRow(new QLabel(tr("è gassata")), carbonated);
    g->addRow(new QLabel(tr("Colore")), colour);
    g->addRow(new QLabel(tr("Tipologia")), tipo);
    g->addRow(new QLabel(tr("Regione")), country);
    g->addRow(new QLabel(tr("Temperatura infusione")), temperature);
    capacity->setEnabled(false);
    grade->setEnabled(false);
    flavour->setEnabled(false);
    carbonated->setEnabled(false);
    colour->setEnabled(false);
    tipo->setEnabled(false);
    country->setEnabled(false);
    temperature->setEnabled(false);
    connect(type, SIGNAL(currentTextChanged(const QString&)), this, SLOT(hidefields()));
}
void mywidgets::ClearFields () const
{
    name->clear();
    label->clear();
    price->clear();
    QDate date(2000, 01, 01);
    deadline->setDate(date);
    number->setValue(0);
    type->setCurrentText("selezionare tipo");
    description->clear();
    capacity->clear();
    grade->clear();
    flavour->clear();
    colour->setCurrentText("nessun colore");
    tipo->clear();
    country->clear();
    temperature->setValue(0);
}

QLineEdit *mywidgets::getName() const
{
    return name;
}

QLineEdit *mywidgets::getLabel() const
{
    return label;
}

QLineEdit *mywidgets::getPrice() const
{
    return price;
}

QDateEdit *mywidgets::getDeadline() const
{
    return deadline;
}

QSpinBox *mywidgets::getNumber() const
{
    return number;
}

QComboBox *mywidgets::getType() const
{
    return type;
}

QTextEdit *mywidgets::getDescription() const
{
    return description;
}

QLineEdit *mywidgets::getGrade() const
{
    return grade;
}

QLineEdit *mywidgets::getFlavour() const
{
    return flavour;
}

QCheckBox *mywidgets::getCarbonated() const
{
    return carbonated;
}

QComboBox *mywidgets::getColour() const
{
    return colour;
}

QLineEdit *mywidgets::getTipo() const
{
    return tipo;
}

QLineEdit *mywidgets::getCountry() const
{
    return country;
}

QLineEdit *mywidgets::getCapacity() const
{
    return capacity;
}

QSpinBox *mywidgets::getTemperature() const
{
    return temperature;
}

form *mywidgets::getFormF() const
{
    return f;
}

form *mywidgets::getFormG() const
{
    return g;
}
void mywidgets::hidefields() const
{
   flavour->setEnabled(true);
   tipo->setEnabled(true);
   country->setEnabled(true);
   temperature->setEnabled(true);
   colour->setEnabled(true);
   grade->setEnabled(true);
   capacity->setEnabled(true);
   if (type->currentText().toStdString()=="birra"){
        flavour->setEnabled(false);
        tipo->setEnabled(false);
        country->setEnabled(false);
        temperature->setEnabled(false);
    }
   if (type->currentText().toStdString()=="tè")
   {
        tipo->setEnabled(false);
        country->setEnabled(false);
        colour->setEnabled(false);
        grade->setEnabled(false);
        capacity->setEnabled(false);
   }
   if(type->currentText().toStdString()=="vino")
   {
      flavour->setEnabled(false);
      temperature->setEnabled(false);
      colour->setEnabled(false);
   }
   if(type->currentText().toStdString()== "selezionare tipo")
   {
    flavour->setEnabled(false);
    tipo->setEnabled(false);
    country->setEnabled(false);
    temperature->setEnabled(false);
    colour->setEnabled(false);
    grade->setEnabled(false);
    capacity->setEnabled(false);
    }
}










