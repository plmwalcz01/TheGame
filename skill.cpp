#include "skill.hpp"

/************************** constructor **************************************/
Skill::Skill(std::string name, int mana_cost) : name(name), mana_cost(mana_cost)
{

}
/*****************************************************************************/

std::string Skill::getName()
{
    return name;
}
void Skill::showEffects()
{
    for(auto i : this->skill_effect)
    {
        std::cout << "Skill: " << getName() << " has effects: "
                << i->getName() << " " << i->getMainAmount() <<"\n";
    }
}
int Skill::getMana_cost()
{
    return mana_cost;
}
