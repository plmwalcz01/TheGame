#pragma once
#include "hero.hpp"

class NPC : public Hero
{
    private:
    int aggressiveness;

    public:
    NPC(int agro, std::string name, unsigned int HP, bool isMain, int exp);
    int show_NCP();

};
