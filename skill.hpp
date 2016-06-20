#pragma once
#include "effect.hpp"

class Skill
{
    private:
    std::string name;
    int mana_cost;
    public:
    Skill(){};
    Skill(std::string, int mana_cost);
    std::vector<Effect *> skill_effect;
    std::string getName();
    int getMana_cost();
    void showEffects();
};
