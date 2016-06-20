#pragma once
#include "items.hpp"
#include "skills.hpp"
#include "effect.hpp"
#include <vector>
#include <string>

class Hero
{
    private:
    std::string hero_name;
    enum class Race
    {
        elf, dwarf, ork, human, dark_elf
    };
    enum class Class
    {
        warrior, mage, thief, ranger,
    };
    int max_strenth;
    int max_dexterity;
    int max_intellect;
    int max_wisdom;
    int max_KP;
    int max_HP;
    int max_MP;
    int max_MOV;
    int max_hunger;
    int max_attak_speed;
    int max_min_dmg;
    int max_max_dmg;
    int max_resist_fire;
    int max_resist_water;
    int max_resist_wind;
    int max_resist_earth;
    int max_resist_pioson;
    int max_weight_limit;
    int exp_to_lvl;
    int exp;

    public:
    int current_strenth;
    int current_dexterity;
    int current_intellect;
    int current_wisdom;
    int current_KP;
    int current_HP;
    int current_MP;
    int current_MOV;
    int current_hunger;
    int current_attak_speed;
    int current_min_dmg;
    int current_max_dmg;
    int current_resist_fire;
    int current_resist_water;
    int current_resist_wind;
    int current_resist_earth;
    int current_resist_pioson;
    int current_weight_limit;
    std::vector<Items> inventory;
    std::vector<Skills> skill_set;

    Hero::Hero();
    int level_up();
    int gain_exp(int);
    int attack();
    int steal();
    int pick_up();
    int set_initial_stats();
    int repair();
};
