#include "weapon.hpp"

Weapon::Weapon(std::string name, std::pair<int, int> dmg,
        HE::Equipment p_t_e): Item(name, p_t_e), dmg(dmg)
{
}
std::pair<int, int> Weapon::getDmg() const
{
    return dmg;
}
void Weapon::setDmg(std::pair<int, int> dmg)
{
    this->dmg = dmg;
}
