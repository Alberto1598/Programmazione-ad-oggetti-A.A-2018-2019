#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "form.h"
#include "mywidgets.h"
#include <QMainWindow>
#include <QPushButton>
#include "controller.h"
#include <QWidget>
#include "data.h"
#include <QListWidget>
#include <mylist.h>
#include <QBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QListWidget>
#include <QMenu>
#include <QMenuBar>
#include <form.h>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QCheckBox>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QList>
#include <QAction>
#include <QDate>
#include <QListWidgetItem>
class controller;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( QWidget * = nullptr);
    QPushButton* getclean() const;
    QListWidget* getDrinkList() const;
    QPushButton* getIns() const;
    QPushButton* getView() const;
    QPushButton* getRemove() const;
    QPushButton* getCalctoto() const;
    QPushButton* getEraseAll() const;
    mywidgets* getWidget() const;
    QMenuBar* getMenubar() const;
    QMenu*  getMenu() const;
     QAction* getSave() const;
    QAction* getSearch() const;
    QAction* getEsc() const;
    QAction* getLoad() const;
private:
    mywidgets* m;
    QPushButton* ins;
    QPushButton* clean;
    QPushButton* view;
    QPushButton* remove;
    QPushButton* calcToto;
    QPushButton* eraseAll;
    QListWidget* drinklist;
    QMenuBar* menubar;
    QMenu* menu;
    QAction* search;
    QAction* save;
    QAction* load;
    QAction* esc;
};

#endif // MAINWINDOW_H
