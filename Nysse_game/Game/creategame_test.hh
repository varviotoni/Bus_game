#ifndef CREATEGAME_HH
#define CREATEGAME_HH

#include "city.hh"

#include <memory>


/**
  * @file
  * @brief Defines a function that creates the city (Students implement it).
  */


/**
 * @brief
 * All of the interfaces defined by the course are found in Interface namespace.
 */
namespace GameSide
{

/**
 * @brief createGame creates the games city and return pointer to it.
 * @pre -
 * @return pointer to the created city. (It is in initialization space)
 * @post Exception guaranteee: basic.
 */
std::shared_ptr<City> createGame();

}

#endif // CREATEGAME_HH

