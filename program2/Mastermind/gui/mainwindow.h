#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>

#include "gui/roundwidget.h"
#include "gui/gamedialog.h"
#include "gui/helpwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addRound(QList<int> colors, QList<bool> solution);

    static char VERSION_STR[];
    static char APP_NAME_STR[];
    static char AUTHOR_NAME_STR[];
    static char AUTHOR_INFO_STR[];

public slots:
    void playRound();
    void moveScrollBar();
    void createNewGame();

    void acceptNewGame();

    void openHelp();
    void openRules();
    void aboutApplication();

    //todo
    void saveGame();
    void openFileChooser();


protected:

private:
    /** odkaz na dialog pro tvorbu nové hry */
    GameDialog *gameDialog;
    /** odkaz na okno s nápovědou */
    HelpWindow *helpWin;

    Ui::MainWindow *ui;

    QList<RoundWidget *> listOfRounds;

    void createMenuBar(void);
    void createPlayButton(void);
    void deleteRoundWidgets(void);

signals:
    void addedRound(void);
};

#endif // MAINWINDOW_H
