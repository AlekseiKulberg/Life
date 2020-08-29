#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include "GameEngine.h"
#include <QThread>
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DrawCell(int x1, int y1, int width, int height);

private slots:
    void slotTimerAlarm();
    void on_StartButton_clicked();

    void on_StopButton_clicked();

private:

    GameEngine *gameEngine;
    int cols = 10;
    int rows = 10;
    int resolution;

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *MainTimer;


    void StartGame();
    void StopGame();

};
#endif // MAINWINDOW_H
