#ifndef STATISTICS_HH
#define STATISTICS_HH

//#include "interfaces/istatistics.hh"
#include "../Course/CourseLib/interfaces/istatistics.hh"
#include <iostream>
#include <map>

// First int of the pair represents the removed nysse's multiplier of given points
//and the second the left nysse's multiplier of given points.
const std::map<std::string, std::pair<int, std::pair<int, int>>> LEVELSTATS =
{ {"EASY",   { 200, {3, -1} } },
  {"NORMAL", { 150, {2, -2} } },
  {"HARD",   { 100, {1, -3} } } };


const int ZERO = 0;
const int PASSANGERVALUE = 5;
const int NYSSEVALUE = 20;
const int NOPREYPENALTY = -10;

class Statistics : public Interface::IStatistics
{
public:
    Statistics(std::string difficulty_level);


    int givePoints() const;
    void passengerDied(int num);
    void nysseLeft();

    //Not to be used.
    void newNysse();
    void nysseRemoved();
    void morePassengers(int num);

    void nysseIsRemoved(int num);

    void noPrey();

    bool sayAlienIsDead() const;

private:

    bool alien_died_;

    int points_;

    const int max_hp_;
    int hp_;

    const int zero_hp_;
    const int removed_nysse_multiplier_;
    const int left_nysse_multiplier;

    int giveHPCount() const;

    bool isOverHPMax(int hp_change);

    bool isUnderHPMin(int hp_change);

    void updateHPCount(int hp_change);

    void updatePoints(int points);

};

#endif // STATISTICS_HH
