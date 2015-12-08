#include <QPushButton>
#include <QFile>
#include <QTextStream>

#include "helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) : QDialog(parent) {
    this->resize(501, 313);

    setWindowTitle("Nápověda");

    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setAlignment(Qt::AlignTop);

    textEdit = new QTextEdit;
    textEdit->setReadOnly(true);
    verticalLayout->addWidget(textEdit);

    createButton();
}

/**
 * Načte potřebná data ze zvoleneho souboru html a připraví je do oblasti textEdit
 * @param fileStr - název html souboru k zobrazení
 */
void HelpWindow::createTextEdit(QString fileStr) {
    QFile file(fileStr);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");

    if (!file.exists()) {
        textEdit->setText(tr("Chybí soubor '%1'").arg(fileStr));
    }
    else {
        file.open (QIODevice::ReadOnly);

        textEdit->setHtml(stream.readAll());

        file.close(); // when your done.
    }
}

/**
 * Vytvori tlacitko pro zavření okna.
 * @brief HelpWindow::createButtons
 */
void HelpWindow::createButton() {
    // tlacitko pro zavreni okna
    QPushButton *bt1 = new QPushButton();
    bt1->setText("Zavřít");
    bt1->setMaximumWidth(100);
    connect(bt1, SIGNAL(clicked()), this, SLOT(close()));
    verticalLayout->addWidget(bt1, 0, Qt::AlignRight);
}

HelpWindow::~HelpWindow() {
    delete textEdit;
    delete verticalLayout;
}

