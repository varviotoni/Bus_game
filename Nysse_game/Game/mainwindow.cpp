#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "startdialog.hh"
#include "ui_startdialog.h"
#include <QDebug>
#include <QImage>
#include <QString>
#include <QTime>


#include "creategame_test.hh"
#include "city.hh"

//default files
const QString BASIC_CITY = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString BIG_CITY = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";
const int PADDING = 100;

namespace GameSide {

MainWindow::MainWindow(StartDialog* d, QWidget *parent) :
    QMainWindow(parent),
    dialog_(d),
    city_(nullptr),
    game_logic_(nullptr),

    //Aliens initial spot centered on the graphics scene
    alien_(std::make_shared<Alien>(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, DEFAULT_COLOR_TYPE)),
    statistics_(nullptr)


{

   ui->setupUi(this);
   ui->gameView->setFixedSize(width_, height_);
   ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);
   ui->gameView->move(0,0);
   ui->startButton->move(width_ + PADDING/2 , PADDING);
   ui->lcd_points->move(width_ + PADDING/2, 2*PADDING);
   ui->alien_healthbar->move(width_ + PADDING/2, 3*PADDING);
   map = new QGraphicsScene(this);
   ui->gameView->setScene(map);
   map->setSceneRect(0,0,width_,height_);

   resize(minimumSizeHint());
   ui->gameView->fitInView(0,0, 24, 24, Qt::KeepAspectRatio);

   timer = new QTimer(this);
   connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
   timer->start(tick_);



    connect(dialog_, &StartDialog::inputs_accepted, this, &MainWindow::on_startDialog_accepted);

    // time signals slot routine game check
}

MainWindow::~MainWindow()
{
}



void MainWindow::updateCoords(int nX, int nY)
{
    alien_->giveAlienItem()->setCoord(nX, nY);
}

void MainWindow::setPicture(QImage &img)
{
     map->setBackgroundBrush(img);
}

void MainWindow::write_lcd()
{
    //to be used
}

void MainWindow::setActorItems()
{
    qDebug() << "setting started.";
    std::vector<std::shared_ptr<Interface::IActor>> actors_list = city_->getActors();
    qDebug() << actors_list.size();
    for(std::shared_ptr<Interface::IActor> actor : actors_list)
    {

        auto actor_get = &*actor;

        if(dynamic_cast<CourseSide::Nysse*>(actor_get))
        {
            CourseSide::SimpleActorItem* nysse_item =
                    new CourseSide::SimpleActorItem(actor->giveLocation().giveX(),
                                                    actor->giveLocation().giveY(),
                                                    DEFAULT_NYSSE_TYPE);
            PaintItem(nysse_item);
            actors_items_.push_back(nysse_item);


        }
        if(dynamic_cast<CourseSide::Passenger*>(actor_get))
        {
            CourseSide::SimpleActorItem* passenger_item =
                    new CourseSide::SimpleActorItem(actor->giveLocation().giveX(),
                                                    actor->giveLocation().giveY(),
                                                    DEFAULT_PASSANGER_TYPE);
            //REMEMBER TO PUT BACK
            //PaintItem(passanger_item);
            actors_items_.push_back(passenger_item);
        }
    }
}

void MainWindow::setStopItems()
{
    std::vector<std::shared_ptr<Interface::IStop>> stops_list = city_->getStops();

    for(auto stop : stops_list)
    {

            CourseSide::SimpleActorItem* stop_item =
                    new CourseSide::SimpleActorItem(stop->getLocation().giveX(),
                                                    stop->getLocation().giveY(),
                                                   DEFAULT_STOP_TYPE);
            //REMEMBER TO PUT BACK
            //PaintItem(stop_item);
            stops_items_.push_back(stop_item);

    }

}



void GameSide::MainWindow::on_startDialog_accepted(std::string difficulty_level)
{
    qDebug() << "StartDialog accepted";

    // Create city
    //  Tässä ei käytetty Interface::creategame
    // TODO: Selvitä miten saan käytettyä city -luokan ei periytettyjä
    // funktioita(Esim returnBackground()) kun creategame palauttaa Interface::ICityn tyyppisen olion
    city_ = createGame();

    // Create Logic
    game_logic_ = std::make_shared<CourseSide::Logic>();

    // Take city into logic
    game_logic_->takeCity(city_);

    // Gets stops and busses from files
    game_logic_->fileConfig();

    game_logic_->finalizeGameStart();

    // Not necessary to setClock?

    //int hour = QTime::currentTime().hour();
    //int minute = QTime::currentTime().minute();
    //Logic_ptr->setTime(hour, minute);

    // Set map into GameView
    QImage map = city_->returnBackground();
    setPicture(map);


    // actors, stops and alien to items


    setActorItems();
    setStopItems();
    qDebug() << actors_items_.size();
    qDebug() << stops_items_.size();

    PaintItem(alien_->giveAlienItem());

    qDebug() << "Alien painted";

    //Set difficulty

    statistics_ = std::make_shared<Statistics>(difficulty_level);



    //Need to set rest qwidgets for init_state!






}

void MainWindow::on_startButton_pressed()
{

}

void MainWindow::on_keyPressEvent_pressed()
{

}

void MainWindow::on_timer_timeout()
{

}

void MainWindow::on_game_ended()
{

}

void MainWindow::on_closeButton_pressed()
{

}

void MainWindow::PaintItem(CourseSide::SimpleActorItem *item)
{
    QPainter* painter = new QPainter(this);
    item->paint(painter, nullptr, nullptr);
}

}
