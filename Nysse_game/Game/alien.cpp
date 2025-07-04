#include "alien.hh"

namespace GameSide
{

Alien::Alien(int x, int y, int type) :
    alien_item_(new CourseSide::SimpleActorItem(x, y, type))

{
}

Alien::~Alien()
{
}

Interface::Location Alien::giveLocation() const
{
    return location_;
}

void Alien::move(Interface::Location loc)
{
    location_ = loc;
}

void Alien::remove()
{
    //Not needed
}

bool Alien::isRemoved() const
{
    //Not needed
}

CourseSide::SimpleActorItem* Alien::giveAlienItem() const
{
    return alien_item_;
}

}
