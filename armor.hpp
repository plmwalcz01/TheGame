#pragma once
#include "effect.hpp"
#include "item.hpp"
#include "hero_enums.hpp"

class Armor : public Item
{
    private:
    int AC;
    public:
    Armor(std::string, int, HE::Equipment);
    int getAC() const;
    void setAC(int);
};
