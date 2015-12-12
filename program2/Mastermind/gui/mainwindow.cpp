#include <QtWidgets>
#include <QLinkedList>

#include "gui/mainwindow.h"
#include "gui/roundwidget.h"
#include "gui/helpwindow.h"
#include "ui_mainwindow.h"

#include "core/datacontroler.h"

char MainWindow::VERSION_STR[] = "1.0";
char MainWindow::APP_NAME_STR[] = "Mastermind";
char MainWindow::AUTHOR_NAME_STR[] = "Radek VAIS, vaisr@students.zcu.cz";
char MainWindow::AUTHOR_INFO_STR[] = "Semestrální práce předmětu KIV/UZI, 2015/2016";

/**
 * Konstruktor hlavního okna aplikace.
 *
 * @brief MainWindow::MainWindow
 * @param parent QWidget rodič hlavního okna
 */
MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow){
    gameDialog = new GameDialog(new DataControler());
    helpWin = new HelpWindow();

    ui->setupUi(this);
    ui->verticalLayout_3->setAlignment(Qt::AlignTop);

    this->setWindowTitle(APP_NAME_STR);

    createMenuBar(); // menu pro ovládání aplikace
    createPlayButton(); //tlačítka pro hru

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

    QAction *actionNew;
    actionNew = new QAction(this);
    actionNew->setText("Nová hra");
    actionNew->setShortcut(Qt::Key_N | Qt::CTRL);
    connect(actionNew, SIGNAL(triggered()), this, SLOT(createNewGame()));
    menuGame->addAction(actionNew);

    QAction *actionOpen;
    actionOpen = new QAction(this);
    actionOpen->setText("Načíst hru");
    actionOpen->setShortcut(Qt::Key_O | Qt::CTRL);
    actionOpen->setEnabled(false); //##########x#################################
    connect(actionOpen, SIGNAL(triggered()), this, SLOT(openFileChooser()));
    menuGame->addAction(actionOpen);

    QAction *actionSave;
    actionSave = new QAction(this);
    actionSave->setText("Uložit hru");
    actionSave->setShortcut(Qt::Key_S | Qt::CTRL);
    actionSave->setEnabled(false); //###########################################
    connect(actionSave, SIGNAL(triggered()), this, SLOT(saveGame()));
    menuGame->addAction(actionSave);

    menuGame->addSeparator();

    QAction *actionRound;
    actionRound = new QAction(this);
    actionRound->setText("Hádej kombinaci");
    actionRound->setShortcut(Qt::Key_H);
    connect(actionRound, SIGNAL(triggered()), this, SLOT(playRound()));
    menuGame->addAction(actionRound);


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
    connect(actionRules, SIGNAL(triggered()), this, SLOT(openRules()));
    menuHelp->addAction(actionRules);

    QAction *actionAboutApp;
    actionAboutApp = new QAction(this);
    actionAboutApp->setText("O aplikaci");
    connect(actionAboutApp, SIGNAL(triggered()), this, SLOT(aboutApplication()));
    menuHelp->addAction(actionAboutApp);

    this->setMenuBar(menuBar);
}

void MainWindow::createPlayButton()
{

}

void MainWindow::moveScrollBar(){
    QScrollBar *v = ui->scrollArea->verticalScrollBar();
    v->setValue(v->maximum());
}

/**
 * Otevře okno s nápovědou k ovládání programu.
 * @brief MainWindow::openHelp
 */
void MainWindow::openHelp(){
    helpWin->createTextEdit("help/help.html");
    helpWin->show();
    helpWin->raise();
    helpWin->activateWindow();
}

/**
 * Otevře okno s nápovědou k pravidlům hry Mastermind
 * @brief MainWindow::openRules
 */
void MainWindow::openRules(){
    helpWin->createTextEdit("help/rules.html");
    helpWin->show();
    helpWin->raise();
    helpWin->activateWindow();
}

/**
 * Zobrazí informace o aplikaci
 * @brief MainWindow::aboutApplication
 */
void MainWindow::aboutApplication(){
    QString msg = QString ("%1 verze %2\n"
                           "%3 \n"
                           "%4").arg(QString(MainWindow::APP_NAME_STR),
                                      QString(MainWindow::VERSION_STR),
                                      QString(MainWindow::AUTHOR_NAME_STR),
                                      QString(MainWindow::AUTHOR_INFO_STR)
                                      );

    QMessageBox::information(this, "O Aplikaci", msg, QMessageBox::Ok);
}


void MainWindow::saveGame(){
    //TODO save game
}

void MainWindow::openFileChooser(){
    //TODO open file
}

void MainWindow::addRound(QList<int> colors, QList<bool> solution){
    RoundWidget *tmp = new RoundWidget(&colors, colors.size(), &solution, ui->scrollAreaWidgetContents_2);

    listOfRounds.append(tmp);
    ui->verticalLayout_3->addWidget(tmp, 0, Qt::AlignTop);
    ui->scrollArea->ensureWidgetVisible(tmp);
    ui->scrollAreaWidgetContents_2->repaint();
    moveScrollBar();
}

void MainWindow::createNewGame(){
    gameDialog->show();
    gameDialog->raise();
    gameDialog->activateWindow();
}


/**
 * Metoda zpracovává požadavek na nové kolo hry.
 * @brief GameDialog::acceptNewGame
 */
void MainWindow::acceptNewGame(){

    QString msg = QString ("Byla zahájena nová hra s parametry: \n"
                           " Počet barev : %1 \n"
                           " Počet pozic : %2").arg(QString::number(gameDialog->mainTab->numberOfColors->value()),
                                                    QString::number(gameDialog->mainTab->numberOfSlots->value()));
    QMessageBox::information(this, "Nová hra", msg, QMessageBox::Ok);
}

void MainWindow::playRound(){
   int i = 5;

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

void MainWindow::deleteRoundWidgets(){
    foreach (RoundWidget *widget, listOfRounds) {
        delete widget;
    }
}

/**
 * Destruktor uklízí všechny vytvořené objekty.
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    deleteRoundWidgets();
    delete gameDialog;
    delete helpWin;
    delete ui;
}


