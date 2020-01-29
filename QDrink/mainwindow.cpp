#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QWidget(parent), m(new mywidgets(this)), ins(new QPushButton(this)), clean(new QPushButton(this)), view(new QPushButton(this)), remove(new QPushButton(this)),  calcToto(new QPushButton(this)), eraseAll(new QPushButton(this)), drinklist(new QListWidget(this)), menubar(new QMenuBar(this)), menu(new QMenu(menubar)), search(new QAction(menubar)), save(new QAction(menubar)), load(new QAction(menubar)), esc(new QAction(menubar))
{
    QVBoxLayout* MainLayout= new QVBoxLayout;
    QVBoxLayout* MenuLayout= new QVBoxLayout;
    QHBoxLayout* secondLayout= new QHBoxLayout;
    QGridLayout* thirdLayout= new QGridLayout;
    QHBoxLayout* fourthLayout= new QHBoxLayout;
    QHBoxLayout* fifthLayout= new QHBoxLayout;


    setWindowTitle("QDrink");
    //setFixedSize(QSize(750,750));
    setFixedWidth(800);
    setWindowIcon(QIcon(":/immagini/icona.png"));


    menu->setTitle("file");
    esc->setText("esci");
    search->setText("ricerca");
    save->setText("salva con nome");
    load->setText("carica file");

    menubar->addMenu(menu);
    menu->addAction(save);
     menu->addAction(load);
    menubar->addAction(esc);
    menubar->addAction(search);


    QGroupBox* groupbox= new QGroupBox(tr("Riempire i campi obbligatori sottostanti"));
      groupbox->setFixedSize(QSize(380,300));

    QGroupBox* groupbox2= new QGroupBox();
    groupbox2->setFixedSize(QSize(380,300));

    QSize button=QSize(60, 30);
    QSize button3=QSize(190, 30);
    ins->setText("inserisci");
    clean->setText("pulisci");
    ins->setFixedSize(button);
    clean->setFixedSize(button);
    view->setText("modifica selezionato");
    view->setFixedSize(button3);
    remove->setText("rimuovi selezionato");
    remove->setFixedSize(button3);
    calcToto->setText("calcola totale selezionato");
    calcToto->setFixedSize(button3);
    eraseAll->setText("elimina tutto");


    drinklist->setSpacing(10);
    drinklist->setSelectionMode(QAbstractItemView::SingleSelection);
    drinklist->setIconSize(QSize(60,60));



    MainLayout->addLayout(MenuLayout);
    MenuLayout->addWidget(menubar);
    MainLayout->addLayout(secondLayout);
    groupbox->setLayout(m->getFormF());
    groupbox2->setLayout(m->getFormG());
    secondLayout->addWidget(groupbox);
    secondLayout->addWidget(groupbox2);
    MainLayout->addLayout(fourthLayout);
    fourthLayout->addWidget(ins);
    fourthLayout->addWidget(clean);
    thirdLayout->addWidget(drinklist);
    MainLayout->addLayout(thirdLayout);
    MainLayout->addLayout(fifthLayout);
    fifthLayout->addWidget(view);
    fifthLayout->addWidget(remove);
    fifthLayout->addWidget(calcToto);
    fifthLayout->addWidget(eraseAll);


    setLayout(MainLayout);
    connect(clean, SIGNAL(clicked()), getWidget(), SLOT(ClearFields()));
}


QPushButton *MainWindow::getclean() const
{
    return clean;
}

QListWidget *MainWindow::getDrinkList() const
{
    return drinklist;
}

QPushButton *MainWindow::getIns() const
{
    return ins;
}

QPushButton *MainWindow::getView() const
{
    return view;
}

QPushButton *MainWindow::getRemove() const
{
    return remove;
}

QPushButton *MainWindow::getCalctoto() const
{
    return calcToto;
}

QPushButton *MainWindow::getEraseAll() const
{
    return eraseAll;
}

mywidgets *MainWindow::getWidget() const
{
    return m;
}

QMenuBar *MainWindow::getMenubar() const
{
    return menubar;
}

QMenu *MainWindow::getMenu() const
{
    return menu;
}

QAction *MainWindow::getSave() const
{
    return save;
}

QAction *MainWindow::getSearch() const
{
    return search;
}

QAction *MainWindow::getEsc() const
{
    return esc;
}

QAction *MainWindow::getLoad() const
{
    return load;
}




