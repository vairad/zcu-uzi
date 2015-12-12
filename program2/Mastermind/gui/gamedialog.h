#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QtWidgets>
#include <QDialog>

#include "core/datacontroler.h"

class QDialogButtonBox;
class QFileInfo;
class QTabWidget;

/**
 * List hlavni - nastaveni hodnot nove hry
 * @brief The MainTab class
 */
class MainTab : public QWidget {
    Q_OBJECT

public:
    explicit MainTab(QWidget *parent = 0);

    QSpinBox *numberOfColors;
    /** pole pro informaci o umisteni metadat */
    QSpinBox *numberOfSlots;
};

/**
 * Dialog umoznujici nastaveni meta dat
 * @brief The TabDialog class
 */
class GameDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameDialog(DataControler *controler, QWidget *parent = 0);
    /** hlavni list */
    MainTab *mainTab;

public slots:
    void rejectNewGame();

private:
    /** widget s listy */
    QStackedWidget *stackedWidget;
    /** box s tlacitky OK a Cancel */
    QDialogButtonBox *buttonBox;
    /** true pokud jsou validni vstupy od uzivatele */
    bool isValidInputs;

};
#endif // GAMEDIALOG_H
