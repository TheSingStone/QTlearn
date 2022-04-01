#include "mainwindow.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    scene(new QGraphicsScene(this)),
    view(new QGraphicsView(scene,this)),
    game(new GameController(*scene,this))
{
    setCentralWidget(view);
    resize(600,600);
    initScene();
    initSceneBackGround();
    QTimer::singleShot(0,this,SLOT(adjustViewSize());
}

MainWindow::~MainWindow()
{
}
void MainWindow::initScene()
{
    scene->setSceneRect(-100,-100,200,200);
}

void MainWindow::initSceneBackGround()
{
    QPixmap bg(TILE_SIZE,TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0,0,TILE_SIZE,TILE_SIZE);

    view->setBackGroundBrush(QBrush(bg));

}
