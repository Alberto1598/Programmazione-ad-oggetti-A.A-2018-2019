#include "mylist.h"
mylistItem::mylistItem( bevanda* b,QWidget* p) : drink(b),parent(p){}


mylistItem* mylistItem::TransformItem()
{
    QIcon icon;
    if(drink->tipo()== "birra"){
        icon=QIcon(QIcon(":/img/Immagini/birra.jpg"));
    }
    if(drink->tipo()== "vino"){
        icon=QIcon(QIcon(":/img/Immagini/vino.jpg"));
    }
    if(drink->tipo()== "tè"){
        icon=QIcon(QIcon(":/img/Immagini/tè.jpg"));
    }
    setText(QString::fromStdString(drink->getFields()));
    setIcon(icon);
    QFont f;
    f.setPointSize(8);
    setFont(f);
    return this;
}

bevanda *mylistItem::getBevanda() const
{
    return drink;
}









