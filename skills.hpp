#pragma once
#include <string>

class Skills : public Hero, public Effect
{
    private:
    std::string name;
    public:
    Effect skill_effect;
};
