#ifndef VISUALIZZA_H
#define VISUALIZZA_H
#include <QDialog>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QGroupBox>
#include <QFormLayout>
#include "form.h"
#include "QLineEdit"
#include <QCheckBox>
#include <QRadioButton>
#include "QGridLayout"
class controller;
class visualizza : public QDialog
{
    Q_OBJECT
public:
    visualizza(QWidget* =nullptr);
    void setList(QListWidget*);
    QListWidget* getLista() const;
    QVBoxLayout* getMainlayout() const;
    QVBoxLayout* getFirstlayout() const;
    QHBoxLayout* getSecondLayout() const;
    QLineEdit* getNome() const;
    QLineEdit* getPrezzo() const;
    QComboBox* getType() const;
    QCheckBox* getIsAlcoholic() const;
    QPushButton* getsearch() const;
    QPushButton* getClear() const;
    QPushButton* getDelete() const;
    QRadioButton* getMoreThan() const;
    QRadioButton* getLessThan() const;
private:
    QWidget * parent;
    QListWidget* lista;
    QVBoxLayout* MainLayout;
    QVBoxLayout* firstLayout;
    QHBoxLayout* SecondLayout;
    QHBoxLayout* Buttonlayout;
    QLineEdit* nome;
    QLineEdit* prezzo;
    QComboBox* type;
    QCheckBox* isAlcoholic;
    QPushButton* search;
    QPushButton* clear;
    QPushButton* Delete;
    form* formlayout;
    form* formlayout2;
    controller* control;
    QHBoxLayout* groupboxlayout;
    QRadioButton* lessThan;
    QRadioButton* moreThan;
public slots:
    void clearFields() const;
};

#endif // VISUALIZZA_H
