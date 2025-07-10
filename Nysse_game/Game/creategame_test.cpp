#include "creategame_test.hh"
#include "city.hh"
namespace GameSide
{
std::shared_ptr<City> createGame()
{
    QImage big_background = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    QImage small_background = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    auto City = std::shared_ptr<GameSide::City>(new GameSide::City);
    City->setBackground(big_background, small_background);

    return City;
}
}
