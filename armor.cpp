#include "armor.hpp"

Armor::Armor(std::string name, int AC, HE::Equipment p_t_e): Item(name, p_t_e),
AC(AC)
{
}

int Armor::getAC() const
{
    return AC;
}

void Armor::setAC(int AC)
{
    this->AC = AC;
}
