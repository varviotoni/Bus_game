#include "statistics.hh"


//namespace GameSide
//{

Statistics::Statistics(std::string difficulty_level):
    alien_died_(false),
    points_(ZERO),
    max_hp_(LEVELSTATS.at(difficulty_level).first),
    hp_(max_hp_),
    zero_hp_(ZERO),
    removed_nysse_multiplier_(LEVELSTATS.at(difficulty_level).second.first),
    left_nysse_multiplier(LEVELSTATS.at(difficulty_level).second.second)


{

}



int Statistics::givePoints() const
{
    return points_;
}

void Statistics::passengerDied(int num)
{
    updatePoints(num*PASSANGERVALUE);
    updateHPCount(num*PASSANGERVALUE);
}

void Statistics::nysseLeft()
{
    updatePoints(left_nysse_multiplier*NYSSEVALUE);
}

void Statistics::newNysse()
{
    //Not needed
}

void Statistics::nysseRemoved()
{
    //Not needed
}

void Statistics::morePassengers(int num)
{
    //Not needed
}

void Statistics::nysseIsRemoved(int num)
{
    passengerDied(removed_nysse_multiplier_*num);
}

void Statistics::noPrey()
{
    updateHPCount(NOPREYPENALTY);
}

bool Statistics::sayAlienIsDead() const
{
    return alien_died_;
}

int Statistics::giveHPCount() const
{
    return hp_;
}

bool Statistics::isOverHPMax(int hp_change)
{
    if(max_hp_ <= hp_ + hp_change)
        {
            return true;
        }
        return false;
}

bool Statistics::isUnderHPMin(int hp_change)
{
    if(hp_ + hp_change <= zero_hp_)
        {
            return true;
        }
        return false;
}

void Statistics::updateHPCount(int hp_change)
{
    if(isOverHPMax(hp_change))
       {
           hp_ = max_hp_;
       }
    else if(isUnderHPMin(hp_change))
       {
           alien_died_ = true;
       }
    else
       {
           hp_ += hp_change;
       }
}

void Statistics::updatePoints(int points)
{
    points_ += points;
}
//}
