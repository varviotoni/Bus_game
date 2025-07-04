#ifndef CITY_HH
#define CITY_HH
#include "interfaces/ivehicle.hh"
#include "interfaces/icity.hh"
#include "interfaces/ipassenger.hh"
#include "core/location.hh"
#include "actors/stop.hh"
#include "interfaces/istop.hh"
#include "interfaces/iactor.hh"

#include <QTime>
#include <memory>
#include <set>
#include <map>
#include <vector>

namespace GameSide
{

class City : public Interface::ICity
{
public:
    City();

    void setBackground(QImage &basicbackground, QImage &bigbackground) ;
    QImage returnBackground();
    void setClock(QTime clock) ;
    void addStop(std::shared_ptr<Interface::IStop> stop) ;
    void startGame() ;
    void addActor(std::shared_ptr<Interface::IActor> newactor) ;
    void removeActor(std::shared_ptr<Interface::IActor> actor) ;
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) ;
    bool findActor(std::shared_ptr<Interface::IActor> actor) const ;
    void actorMoved(std::shared_ptr<Interface::IActor> actor) ;
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const ;
    bool isGameOver() const ;

    std::vector<std::shared_ptr<Interface::IActor>> getActors() const;

    std::vector<std::shared_ptr<Interface::IStop>> getStops() const;

private:

    QTime time_;
    std::vector<std::shared_ptr<Interface::IStop>> stops_;
    std::vector<std::shared_ptr<Interface::IActor>> actors_;
    std::shared_ptr<Interface::IActor> alien_;
    QImage big_map_;
    QImage map_;
    bool game_state_;
    bool ended_;

};
}
#endif // CITY_HH
