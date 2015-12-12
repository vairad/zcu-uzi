#include "gui/gamedialog.h"
#include "gui/mainwindow.h"

#include <QSlider>

/**
 * Vytvori dialog umoznujici nastaveni meta dat
 * @brief GameDialog::GameDialog
 * @param sensors widgety senzoru
 * @param numberOfSensors pocet senzoru
 * @param parent
 */
GameDialog::GameDialog(DataControler *controler, QWidget *parent) : QDialog(parent) {
    stackedWidget = new QStackedWidget;
    mainTab = new MainTab();
    stackedWidget->addWidget(mainTab);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(acceptNewGame()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(rejectNewGame()));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Nová hra"));
}


void GameDialog::rejectNewGame(){
    QMessageBox::information(this, "Informace", "Pokračujete v původní hře", QMessageBox::Ok);
}

/**
 * Vytvori list hlavni - nastaveni udaju uzivatele
 * @brief MainTab::MainTab
 * @param parent
 */
MainTab::MainTab(QWidget *parent) : QWidget(parent) {

    QLabel *colorsLabel = new QLabel(tr("Počet barev:"));
    numberOfColors = new QSpinBox();
    numberOfColors->setRange(2,10);
    numberOfColors->setSingleStep(1);

    QLabel *slotsLabel = new QLabel(tr("Počet míst:"));
    numberOfSlots = new QSpinBox();
    numberOfSlots->setRange(2,20);
    numberOfSlots->setSingleStep(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(colorsLabel);
    mainLayout->addWidget(numberOfColors);
    mainLayout->addWidget(slotsLabel);
    mainLayout->addWidget(numberOfSlots);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

