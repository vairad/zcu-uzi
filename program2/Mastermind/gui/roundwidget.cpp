#include "roundwidget.h"
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

int RoundWidget::instance_counter = 0;

RoundWidget::RoundWidget(QVBoxLayout *vLayout, QList<int> *roundValues, int numberOfSlots, QList<bool> *solution, QWidget *parent) : QWidget(parent)
{
    this->numberOfSlots = numberOfSlots;
    this->colors = *roundValues;
    this->solution = *solution;

    this->frameWidth = SIZE_OF_SLOT * numberOfSlots + SIZE_OF_SOLUTION * solution->size();
    this->frameHeight = SIZE_OF_SLOT * 1.2;

    RoundWidget::instance_counter++;

    this->setObjectName(QStringLiteral("widget"));
    this->setEnabled(true);
    this->setMinimumSize(QSize(frameWidth, frameHeight));
    this->setMaximumSize(QSize(16777215, frameHeight));
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setAutoFillBackground(false);
    vLayout->addWidget(this, 0, Qt::AlignTop);

    createLayout();
    createGraphicsView();

    drawRound();
}

/**
 * Připraví layout widgetu
 * @brief RoundWidget::createLayout
 */
void RoundWidget::createLayout(){
    layout = new QHBoxLayout(this);
    layout->setSpacing(6);
    layout->setContentsMargins(4, 4, 4, 4);
    layout->setObjectName(QStringLiteral("horizontalLayout"));
}

/**
 * Vykresli graficke okno
 * @brief SensorWidget::createGraphicsView
 */
void RoundWidget::createGraphicsView() {
    graphicsView = new QGraphicsView(this);
    graphicsView->setObjectName(QStringLiteral("graphicsView"));
    graphicsView->setEnabled(true);
    graphicsView->setMinimumSize(QSize(frameWidth, frameHeight));
    graphicsView->setMaximumSize(QSize(16777215, frameHeight));
    graphicsView->setDragMode(QGraphicsView::NoDrag);
    graphicsView->setCacheMode(QGraphicsView::CacheNone);
    graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    graphicsView->setRubberBandSelectionMode(Qt::ContainsItemShape);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF(QPointF(0, 0), QPointF(this->graphicsView->width(), this->graphicsView->height())));

    graphicsView->setScene(scene);
    graphicsView->setBackgroundBrush(QBrush(QColor(150, 150, 150), Qt::SolidPattern));
    graphicsView->setFrameStyle(0);

    layout->addWidget(graphicsView);
}


/**
 * Vykreslí všechny prvky kola.
 * @brief RoundWidget::drawRound
 */
void RoundWidget::drawRound(){

    drawSlots();
    drawSolution();

    //TODO delete
    QString mrkev;
    mrkev = QString::number(instance_counter);
    scene->addText(mrkev);
}

/**
 * Přidá sloty do grafické scény
 * @brief RoundWidget::drawSlots
 */
void RoundWidget::drawSlots(){
    int mezera = (SIZE_OF_SLOT / 20);
    int prumerSlotu = (9 * SIZE_OF_SLOT) / 10;
    int vertikalniMezera = (frameHeight - SIZE_OF_SLOT) / 2 ;

    QPen pen;
    pen.setColor(QColor(Qt::black));

    for(int i = 0; i < numberOfSlots; ++i){

        int left = mezera + (i * 2 * mezera) + (i * prumerSlotu);

        QColor chosedColor = getColor(colors.at(i));

        scene->addEllipse(left, vertikalniMezera, prumerSlotu, prumerSlotu, pen, QBrush(chosedColor));
    }
}

/**
 * Přidá řešení do grafické scény
 * @brief RoundWidget::drawSlots
 */
void RoundWidget::drawSolution(){
    int mezera = (SIZE_OF_SOLUTION / 30);
    int prumerSlotu = (9 * SIZE_OF_SOLUTION) / 10;

    int vertikalniMezera = (frameHeight - 2 * SIZE_OF_SOLUTION) / 4;
    int slotOffset = SIZE_OF_SLOT * numberOfSlots;

    QPen pen;
    pen.setColor(QColor(Qt::black));

    short modCounter = 0;
    for(int i = 0; i < solution.size(); ++i){

        int top = vertikalniMezera + modCounter * (2 * vertikalniMezera + SIZE_OF_SOLUTION);
        int left = slotOffset + mezera + ( i * 2 * mezera) + (i * prumerSlotu);

        QColor chosedColor = getSolutionColor(solution.at(i));

        scene->addEllipse(left, top,prumerSlotu, prumerSlotu, pen, QBrush(chosedColor));

        modCounter = (modCounter + 1) % 2;
    }
}

QColor RoundWidget::getColor(int colotID){
    switch(colotID){
        case 1:
            return QColor(Qt::red);
        case 2:
            return QColor(Qt::blue);
        case 3:
            return QColor(Qt::green);
        case 4:
            return QColor(Qt::black);
        case 5:
            return QColor(Qt::yellow);
        case 6:
            return QColor(Qt::gray);
        case 7:
            return QColor(Qt::cyan);
        case 8:
            return QColor(Qt::magenta);
        case 9:
            return QColor("#5E2612"); //hnědá, brown
        case 10:
            return QColor("#ff6600"); //oranžová, orange
    }
    return QColor(Qt::white);
}


QColor RoundWidget::getSolutionColor(bool solutionValue){
    if( solutionValue == true ){
        return QColor(Qt::black);
    }
    return QColor(Qt::white);
}

/**
 * Destruktor vidgetu pokusu.
 * @brief RoundWidget::~RoundWidget
 */
RoundWidget::~RoundWidget(){

}
