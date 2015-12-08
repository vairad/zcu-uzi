#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

#include "roundwidget.h"

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

public slots:
    void playRound();
    void moveScrollBar();

protected:

private:

    //debug
     int counter = 0;
    //end debug

    Ui::MainWindow *ui;

    QList<RoundWidget *> listOfRounds;

    void createMenuBar(void);
    void createToolBar(void);
    void createUserPanel(void);

signals:
    void addedRound(void);
};

#endif // MAINWINDOW_H
