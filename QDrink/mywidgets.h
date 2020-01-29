#ifndef MYWIDGETS_H
#define MYWIDGETS_H
#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QTextEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QLabel>
#include <form.h>
#include "data.h"
#include <string>
#include <QString>
#include <QGroupBox>
using std::string;
class mywidgets : public QWidget
{
    Q_OBJECT
public:
    mywidgets(QWidget* parent= nullptr);
private:
    QLineEdit* name;
    QLineEdit* label;
    QLineEdit* price;
    QDateEdit* deadline;
    QSpinBox* number;
    QComboBox* type;
    QTextEdit* description;
    QLineEdit* grade;
    QLineEdit* flavour;
    QCheckBox* carbonated;
    QComboBox* colour;
    QLineEdit* tipo;
    QLineEdit* country;
    QLineEdit* capacity;
    QSpinBox* temperature;
    form* f;
    form* g;
public:
    QLineEdit* getName () const;
    QLineEdit* getLabel () const;
    QLineEdit* getPrice () const;
    QDateEdit* getDeadline() const;
    QSpinBox* getNumber() const;
    QComboBox* getType() const;
    QTextEdit* getDescription() const;
    QLineEdit* getGrade() const;
    QLineEdit* getFlavour() const;
    QCheckBox* getCarbonated() const;
    QComboBox* getColour() const;
    QLineEdit* getTipo() const;
    QLineEdit* getCountry() const;
    QLineEdit* getCapacity() const;
    QSpinBox* getTemperature() const;
    form* getFormF() const;
    form* getFormG() const;
signals:
    void currentTextChanged(const QString&);
public slots:
    void ClearFields() const;
    void hidefields() const;
};

#endif // MYWIDGETS_H
