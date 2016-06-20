#ifndef _EFFECT_
#define _EFFECT_
//#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstdint>
#include "effect_enum.hpp"

class Hero;

class Effect
{
    private:
    int is_passive_effect;
    int is_active_effect;
    public:
    EE::Name name;
    unsigned int main_amount;
    int duration;

    Effect(EE::Name name, int main_amount);
    ~Effect();
    std::string getName();
    int getMainAmount();
    int passive_effect() ;
    int active_effect(Hero*) ;
    int heal(Hero*);
    int dealDMG(Hero*);
    int shield(Hero*);
    int recharge(Hero*);
    int satisfyHunger(Hero*);
    int repair(Hero*);
    int HPRegen(Hero*);
    int MPRegen(Hero*);
    int stun(Hero*);
    int weakness(Hero*);
};
#endif //_EFFECT_
