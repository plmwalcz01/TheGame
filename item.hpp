#pragma once
#include "effect.hpp"
#include "hero_enums.hpp"

class Item
{
    private:
    std::string name;
    std::string path_to_bitmap;
    int max_durability;
    int max_price;
    int max_weight;
    int max_stack;
    bool isIdentified;

    public:
    HE::Equipment place_to_equip;
    int durability;
    int price;
    int weight;
    int stack;
    std::vector<Effect *> item_effect;

    Item(std::string);
    Item(std::string, HE::Equipment);

    virtual ~Item();
    std::string getName() const;
    virtual std::pair<int, int> getDmg() const;
    virtual void setAC(int);
    virtual int getAC() const;
    virtual void setDmg(std::pair<int, int>);
    int set_current_price();
    int decrease_durability(int);
    int increase_durability(int);
};
