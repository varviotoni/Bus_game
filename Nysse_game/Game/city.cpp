#include "city.hh"
#include "mainwindow.hh"
#include "graphics/simplemainwindow.hh"
#include "core/logic.hh"
#include <algorithm>
#include <iostream>


namespace GameSide
{

City::City() : game_state_(false), ended_(false)

{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{

    map_ = basicbackground;
    big_map_ = bigbackground;


}

QImage City::returnBackground()
{
    return map_;
}


void City::setClock(QTime clock)
{
    time_ = clock;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);
}

void City::startGame()
{
    game_state_ = true;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    // Not needed
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

    std::vector<std::shared_ptr<Interface::IActor>>::iterator it;
    auto actors_list = actors_;

    it = std::find(actors_list.begin(),actors_list.end(), actor);
    if (it != actors_list.end()) {
        return true;

    } else {
        return false;
    }
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    // Not needed
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor> > nearby_list;
    for (auto actor : actors_) {

        if (actor->giveLocation().isClose(loc,100)) {
            nearby_list.push_back(actor);

        }
    }
    return nearby_list;
}

bool City::isGameOver() const
{
    if (ended_){

        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getActors() const
{
    return actors_;
}

std::vector<std::shared_ptr<Interface::IStop> > City::getStops() const
{
    return stops_;
}

}
