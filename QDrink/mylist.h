#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <QListWidget>
#include <QListWidgetItem>
#include "bevanda.h"
#include "bevanda_analcolica.h"
#include "bevanda_alcolica.h"
#include "vino.h"
#include "te.h"
#include "birra.h"
#include <QIcon>
#include <string>
#include <QString>
class mylistItem : public QListWidgetItem
{
public:
    mylistItem(bevanda* b,QWidget* =nullptr);
    mylistItem* TransformItem();
    bevanda* getBevanda() const;
    QListWidgetItem* getList() const;
private:
    bevanda* drink;
    QWidget* parent;
};

#endif // MYLIST_H
