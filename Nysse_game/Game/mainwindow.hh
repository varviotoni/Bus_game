#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "creategame_test.hh"

#include "startdialog.hh"
#include "city.hh"
#include "core/logic.hh"
#include "alien.hh"
#include "statistics.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include <typeinfo>

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const int DEFAULT_COLOR_TYPE = 0;
const int DEFAULT_NYSSE_TYPE = 50;
const int DEFAULT_PASSANGER_TYPE = 100;
const int DEFAULT_STOP_TYPE = 150;

namespace Ui {
class MainWindow;
}

namespace GameSide {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(StartDialog* d, QWidget *parent = nullptr);
    ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);



    void write_lcd();

    void setActorItems();

    void setStopItems();





private slots:
    void on_startDialog_accepted(std::string difficulty_level);

    void on_startButton_pressed();

    void on_keyPressEvent_pressed();

    void on_timer_timeout();

    void on_game_ended();

    void on_closeButton_pressed();

private:
    Ui::MainWindow *ui;
    StartDialog *dialog_;
    QGraphicsScene *map;
    QTimer *timer;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms


    std::shared_ptr<City> city_;
    std::shared_ptr<CourseSide::Logic> game_logic_;
    std::shared_ptr<Alien> alien_;
    std::shared_ptr<Statistics> statistics_;

    QVector<CourseSide::SimpleActorItem*> actors_items_;
    QVector<CourseSide::SimpleActorItem*> stops_items_;

    void PaintItem(CourseSide::SimpleActorItem* item);


};

}
#endif // MAINWINDOW_HH
