#include "item.hpp"

Item::Item(std::string name): name(name)
{
}
Item::Item(std::string name, HE::Equipment p_t_e): name(name),
                                                   place_to_equip(p_t_e)
{
}

Item::~Item()
{
}

std::string Item::getName() const
{
    return name;
}
std::pair<int, int> Item::getDmg() const
{
    return std::make_pair(0, 0);
}
void Item::setDmg(std::pair<int, int> dmg)
{
    (void) dmg;
}
int Item::getAC() const
{
    return 0;
}
void Item::setAC(int)
{
}
