#ifndef ROUNDWIDGET_H
#define ROUNDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QAction>
#include <QMenu>
#include <QGraphicsLineItem>
#include <QMainWindow>
#include <QColor>

class RoundWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RoundWidget(QList<int> *roundValues, int number, QList<bool> *solution, QWidget *parent = 0);
    ~RoundWidget();

public slots:

signals:

protected:

    /** komponenta pro zobrazeni sceny grafu */
    QGraphicsView *graphicsView;

    /** komponenta pro zobrazeni sceny grafu */
    QGraphicsScene *scene;

  /*  void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);*/

private:

    static int instance_counter;

    const static int SIZE_OF_SLOT = 50;
    const static int SIZE_OF_SOLUTION = 20;


    void createGraphicsView();
    void drawRound();
    void drawSlots();
    void drawSolution();
    void createLayout();

    QColor getColor(int colorID);
    QColor getSolutionColor(bool solutionValue);


    /** počet míst pro barvy */
    int numberOfSlots;
    /** barvy tahu */
    QList<int> colors;
    /** řešení tahu */
    QList<bool>solution;

    /** graphic width for round*/
    int frameWidth;
    /** graphic height for round*/
    int frameHeight;

    /** hlavni widget */
    QWidget *widget;
    /** tlacitko vyhodnoceni */
    QPushButton *button;
    /** popisek widgetu */
    QLabel *label;
    /** layout widgetu */
    QHBoxLayout *layout;
    /** polozka krivky kreslena do sceny */
    QGraphicsPathItem *curve;
};

#endif // ROUNDWIDGET_H
