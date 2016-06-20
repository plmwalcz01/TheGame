#include <cmath>
#include <algorithm>
#include "location.hpp"
#include "item.hpp"
#include "armor.hpp"
#include "weapon.hpp"
#include "hero_enums.hpp"
Location::Location()
{

}
Location::Location(int x, int y, bool isKnown): isKnown(isKnown),
                                                          x_coord(x), y_coord(y)
{
    location_ID = sqrt((x*x) + (y*y));
}
Location::Location(int ID, int x, int y, bool isKnown): location_ID(ID),
                                        isKnown(isKnown), x_coord(x), y_coord(y)
{

}
int Location::item_generator()
{
    if(this->location_ID)
    {
        this->items_on_location.push_back(new Item("loc_item_1"));
        this->items_on_location.push_back(new Armor("loc_item_2 AC15T", 15,
                                                        HE::Equipment::Torso ));
        this->items_on_location.push_back(new Armor("loc_item_3 AC20T", 20,
                                                        HE::Equipment::Torso ));
        this->items_on_location.push_back(new Armor("loc_item_4 AC10H", 10,
                                                        HE::Equipment::Head ));
        this->items_on_location.push_back(new Weapon("loc_item_5 DMG 1-4",
                std::make_pair(2,4), HE::Equipment::Weapon));
    }
    return 0;
}
int Location::NPC_generator()
{
    if(this->location_ID)
    {
        this->NPC_on_location.push_back(new NPC(10, "Drunk", 50, false, 100));
        this->NPC_on_location.push_back(new NPC(50, "Thug", 70, false, 200));
    }
    return 0;
}
int Location::setIsKnown()
{
    if(isKnown)
        isKnown = true;
    return 0;
}
std::string Location::showLocationItems()
{
    for(auto i : this->items_on_location)
    {
        std::cout << i->getName() << std::endl;
    }
    return "wszystkie itemy";
}
int Location::showLocationNPC()
{
    for(auto i : this->NPC_on_location)
    {
        if(!i->getIsDead())
        {
            i->show_NCP();
        }
    }
    return 0;
}
int Location::getLocationID()
{
    return location_ID;
}
NPC* Location::getLocationNPC(unsigned int npc_no)
{
    if(npc_no < NPC_on_location.size())
    {
        return NPC_on_location[npc_no];
    }
    return nullptr;
}

Item* Location::getLocationItems(unsigned int item_number)
{
    if(item_number < (this->items_on_location.size()) )
    {
        return this->items_on_location[item_number];
    }
    return nullptr;
}
int Location::transfer_item(Item *item)
{
    items_on_location.erase(std::remove(items_on_location.begin(),
            items_on_location.end(), item), items_on_location.end());
    return 0;
}
