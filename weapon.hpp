#pragma once
#include "item.hpp"

class Weapon : public Item
{
    private:
    std::pair<int, int> dmg;

    public:

    Weapon(std::string, std::pair<int, int>, HE::Equipment);
    std::pair<int, int> getDmg() const;
    void setDmg(std::pair<int, int>);
};
