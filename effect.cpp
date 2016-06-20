#include <map>
#include "effect.hpp"
#include "hero.hpp"
#include "NPC.hpp"

std::map<EE::Name, std::string> EfToStrMap = {
        {EE::Name::Heal, "Heal"},
        {EE::Name::DealDMG, "DealDMG"},
        {EE::Name::Recharge, "Recharge"},
        {EE::Name::Repair, "Repair"},
        {EE::Name::HPRegen, "HPRegen"},
        {EE::Name::MPRegen, "MPRegen"},
        {EE::Name::SatisfyHunger, "SatisfyHunger"},
        {EE::Name::Shield, "Shield"},
        {EE::Name::Stun, "Stun"},
        {EE::Name::Weakness, "Weakness"}};

/************************** constructor **************************************/
Effect::Effect(EE::Name name, int main_amount): name(name),
                                                        main_amount(main_amount)
{
}
/*****************************************************************************/
Effect::~Effect()
{
    std::cout<< "destroy" << std::endl;
}
std::string Effect::getName()
{
    return EfToStrMap[name];
}
int Effect::getMainAmount()
{
    return main_amount;
}
int Effect::passive_effect()
{
    return 0;
}
int Effect::active_effect(Hero* hero)
{
    switch (name)
    {
    case EE::Name::Heal : heal(hero); break;
    case EE::Name::DealDMG : dealDMG(hero); break;
    case EE::Name::Recharge : recharge(hero); break;
    case EE::Name::Repair : repair(hero); break;
    case EE::Name::HPRegen : HPRegen(hero); break;
    case EE::Name::MPRegen : MPRegen(hero); break;
    case EE::Name::SatisfyHunger : satisfyHunger(hero); break;
    case EE::Name::Shield : shield(hero); break;
    case EE::Name::Stun : stun(hero); break;
    case EE::Name::Weakness : weakness(hero); break;
    }
    return 0;
}
int Effect::heal(Hero* hero)
{
    if((hero->getHp().first + main_amount) < hero->getHp().second)
    {
        hero->setHp(std::make_pair(hero->getHp().first + main_amount,
                                                         hero->getHp().second));
    }
    else
    {
        hero->setHp(std::make_pair(hero->getHp().second, hero->getHp().second));
    }
    return 0;
}
int Effect::dealDMG(Hero* target)
{
    if((target->getHp().first > main_amount))
    {
        target->setHp(std::make_pair(target->getHp().first - main_amount,
                                                         target->getHp().second));
    }
    else
    {
        target->setIsDead(true);
        std::cout << "target is dead" << std::endl;
        return 1;
    }
    return 0;
}
int Effect::shield(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::recharge(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::satisfyHunger(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::repair(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::HPRegen(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::MPRegen(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::stun(Hero* hero)
{
    (void) hero;
        return 0;
}
int Effect::weakness(Hero* hero)
{
    (void) hero;
        return 0;
}
