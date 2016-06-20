/*
 * game.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: plmwalcz01
 */
#include <memory>
#include "game.hpp"

int Game::item_transfer(Hero* hero, Item* item)
{
    hero->pick_up_item(item);
    map_ith = map.find(hero->heroCurentPos);
    map_ith->second->transfer_item(item);
    return 0;
}
int Game::fight()
{
    hero.prepare_to_fight();
    //hero.attack();
    return 0;
}
int Game::insert_location(std::pair<int, int>
                                    coords, std::shared_ptr<Location> location )
{
    map.insert(std::pair<std::pair<int, int>, std::shared_ptr<Location> >
                                                            (coords, location));
    return 0;
}
int Game::insert_location(std::shared_ptr<Location> location )
{
    std::pair<int, int> coords (location->x_coord, location->y_coord);
    map.insert(std::pair<std::pair<int, int>, std::shared_ptr<Location> >
                                                            (coords, location));
    return 0;
}
int Game::initialize_hero(Hero* givenHero)
{
    hero = *givenHero;
    return 0;
}
std::shared_ptr<Location> Game::generate_location()
{
    std::shared_ptr<Location> location;
    location=std::make_shared<Location>();
    return location;
}
std::shared_ptr<Location> Game::generate_location(std::pair<int, int> coords)
{
    std::shared_ptr<Location> location;
    location=std::make_shared<Location>(coords.first, coords.second, true);
    location->item_generator();
    location->NPC_generator();
    return location;
}
