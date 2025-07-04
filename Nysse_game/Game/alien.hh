#ifndef ALIEN_HH
#define ALIEN_HH

#include <interfaces/iactor.hh>
#include <graphics/simpleactoritem.hh>

namespace GameSide
{

class Alien : public Interface::IActor
{
public:
    Alien(int x, int y, int color_type);

    //ActorIF
    ~Alien();

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    void remove();
    bool isRemoved() const;

    CourseSide::SimpleActorItem* giveAlienItem() const;

private:

    Interface::Location location_;
    CourseSide::SimpleActorItem* alien_item_;

};
}
#endif // ALIEN_HH
