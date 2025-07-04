#include "creategame_test.hh"
#include "city.hh"
const QString BASIC_CITY = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
namespace GameSide
{
std::shared_ptr<City> createGame()
{
    std::shared_ptr<City> City = std::make_shared<GameSide::City>();
    QImage basic_city_map;
    basic_city_map.load(BASIC_CITY);
    City->setBackground(basic_city_map, basic_city_map);

    return City;
}
}
