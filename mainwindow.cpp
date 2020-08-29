#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameEngine.h"
#include "matrix.h"
#include <QGraphicsScene>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    MainTimer = new QTimer();
    scene = new QGraphicsScene();



}

MainWindow::~MainWindow()
{
    delete gameEngine;
    delete MainTimer;
    delete ui;
}


void MainWindow::StartGame()
{


    resolution = ui->ResolutionLineEdit->text().toInt();
    cols = ui->MainGraphicsView->width()/resolution;
    rows = ui->MainGraphicsView->height()/resolution;

    gameEngine = new GameEngine(cols,rows,10);

    connect(MainTimer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    MainTimer->start(100);

    ui->MainGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->MainGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void MainWindow::StopGame()
{
    //scene->clear();
    MainTimer->stop();
}


void MainWindow::DrawCell(int x1, int y1, int width, int height)
{


    ui->MainGraphicsView->setScene(scene);
    scene->setSceneRect(0,0, ui->MainGraphicsView->width(),ui->MainGraphicsView->height());
    scene->addRect(QRect(x1* resolution,y1 * resolution,width - 1,height - 1), QPen(Qt::red,0.8), QBrush(Qt::green));

}

void MainWindow::slotTimerAlarm()
{
    scene->clear();
    matrix<bool> buffer = gameEngine->GetCurrentGeneration();

    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            if(buffer[i][j])
                DrawCell(i ,j,resolution,resolution);
        }
    }
    gameEngine->NextGeneration(false);
    QThread::msleep(100);

}

void MainWindow::on_StartButton_clicked()
{
    StartGame();


}

void MainWindow::on_StopButton_clicked()
{
    StopGame();
}
