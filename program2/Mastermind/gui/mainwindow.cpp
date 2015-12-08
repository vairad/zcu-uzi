#include <QtWidgets>
#include <QLinkedList>

#include "mainwindow.h"
#include "roundwidget.h"
#include "ui_mainwindow.h"

/**
 * Konstruktor hlavního okna aplikace.
 *
 * @brief MainWindow::MainWindow
 * @param parent QWidget rodič hlavního okna
 */
MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
   // this->listOfRounds = new QList<RoundWidget *>();

    ui->setupUi(this);
    ui->verticalLayout_3->setAlignment(Qt::AlignTop);
    this->setWindowTitle("Mastermind");

    createMenuBar();

    //  createToolBar();
    //  createUserPanel();
    //  initialWindow = new InitialWindow(dataManager, this);

   connect(this, SIGNAL(addedRound()), this, SLOT(moveScrollBar()));
}


/**
 * Vytvoří menu aplikace Hra a Nápověda
 *
 * @brief MainWindow::createMenuBar
 */
void MainWindow::createMenuBar()
{
    QMenuBar *menuBar;
    menuBar = new QMenuBar(this);
    menuBar->setGeometry(QRect(0, 0, 756, 21));

    //tvorba hlavních částí vodorovného menu
    // polozka Hra
    QMenu *menuGame;
    menuGame = new QMenu(menuBar);
    menuGame->setTitle("Hra");
    menuBar->addAction(menuGame->menuAction());

    // polozka Nápověda
    QMenu *menuHelp;
    menuHelp = new QMenu(menuBar);
    menuHelp->setTitle("Nápověda");
    menuBar->addAction(menuHelp->menuAction());


    //================================================ add menu items
    // menu hra
    QAction *actionOpen;
    actionOpen = new QAction(this);
    actionOpen->setText("Načíst hru");
    actionOpen->setShortcut(Qt::Key_O | Qt::CTRL);
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFileChooser()));
    menuGame->addAction(actionOpen);

    //############################################################################################
    QAction *actionRound;
    actionRound = new QAction(this);
    actionRound->setText("Přidej kolo");
    actionRound->setShortcut(Qt::Key_A);
    connect(actionRound, SIGNAL(triggered()), this, SLOT(playRound()));
    menuGame->addAction(actionRound);
    //#############################################################################################

    QAction *actionSave;
    actionSave = new QAction(this);
    actionSave->setText("Uložit hru");
    actionSave->setShortcut(Qt::Key_S | Qt::CTRL);
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveGame()));
    menuGame->addAction(actionSave);

    QAction *actionNew;
    actionNew = new QAction(this);
    actionNew->setText("Nová hra");
    actionNew->setShortcut(Qt::Key_N | Qt::CTRL);
    connect(actionNew, SIGNAL(triggered()), this, SLOT(createNewGame()));
    menuGame->addAction(actionNew);

    //menu nápověda
    QAction *actionHelp;
    actionHelp = new QAction(this);
    actionHelp->setText("Ovládání");
    actionHelp->setShortcut(Qt::Key_H | Qt::CTRL);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(openHelp()));
    menuHelp->addAction(actionHelp);

    QAction *actionRules;
    actionRules = new QAction(this);
    actionRules->setText("Pravidla hry");
    actionRules->setShortcut(Qt::Key_P | Qt::CTRL);
    connect(actionRules, SIGNAL(triggered()), this, SLOT(openHelp()));
    menuHelp->addAction(actionRules);

    QAction *actionAboutApp;
    actionAboutApp = new QAction(this);
    actionAboutApp->setText("O aplikaci");
    connect(actionAboutApp, SIGNAL(triggered()), this, SLOT(aboutApplication()));
    menuHelp->addAction(actionAboutApp);

    this->setMenuBar(menuBar);


}

void MainWindow::playRound(){
    int i = counter;
    counter++;

    QList<int> seznam;
    seznam.append((1 + i) % 10);
    seznam.append((2 + i) % 10);
    seznam.append((3 + i) % 10);
    seznam.append((4 + i) % 10);
    seznam.append((5 + i) % 10);
    seznam.append((6 + i) % 10);
    seznam.append((7 + i) % 10);
    seznam.append((8 + i) % 10);
    seznam.append((9 + i) % 10);
    seznam.append((10 + i) % 10);

    QList<bool> solution;
    solution.append(true);
    solution.append(true);
    solution.append(false);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(false);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(false);
    solution.append(true);
    solution.append(true);
    solution.append(true);
    solution.append(true);

    addRound(seznam, solution);
}

void MainWindow::moveScrollBar(){
    QScrollBar *v = ui->scrollArea->verticalScrollBar();
    v->setValue(v->maximum());
v->setValue(v->maximum());
v->setValue(v->maximum());
}

void MainWindow::createToolBar()
{

}


void MainWindow::addRound(QList<int> colors, QList<bool> solution){
    listOfRounds.append(new RoundWidget(ui->verticalLayout_3, &colors, colors.size(), &solution, ui->scrollAreaWidgetContents_2));
}

MainWindow::~MainWindow()
{
    foreach (RoundWidget *widget, listOfRounds) {
        delete widget;
    }
    delete ui;
}


