#pragma once
#include "item.hpp"
#include "NPC.hpp"
#include <memory>
#include <vector>

class Location
{
    private:
    int location_ID;
    std::string description;
    std::vector< Item* > items_on_location;
    std::vector<NPC*> NPC_on_location;
    bool isKnown;
    public:
    Location();
    Location(int x, int y, bool);
    Location(int, int x, int y, bool);
    int x_coord;
    int y_coord;
    Item* getLocationItems(unsigned int item_number);
    int transfer_item(Item *);
    int getLocationID();
    NPC* getLocationNPC(unsigned int npc_no);
    std::string showLocationItems();
    int showLocationNPC();
    int item_generator();
    int NPC_generator();
    int setIsKnown();
};
