#include "hero.hpp"
#include <algorithm>

std::map<HE::Equipment, std::string> EqToStrMap = {
        {HE::Equipment::Head, "Head "},
        {HE::Equipment::Torso, "Torso "},
        {HE::Equipment::Legs, "Legs "},
        {HE::Equipment::Hands, "Hands "},
        {HE::Equipment::Arms, "Arms "},
        {HE::Equipment::Feet, "Feet "},
        {HE::Equipment::Neck, "Neck "},
        {HE::Equipment::Waist, "Waist "},
        {HE::Equipment::Cape, "Cape "},
        {HE::Equipment::Weapon, "Weapon "},
        {HE::Equipment::Left_Ear, "Left_Ear "},
        {HE::Equipment::Right_Ear, "Right_Ear "},
        {HE::Equipment::Left_Finger1, "Left_Finger1 "},
        {HE::Equipment::Left_Finger2, "Left_Finger2 "},
        {HE::Equipment::Left_Finger3, "Left_Finger3 "},
        {HE::Equipment::Right_Finger1, "Right_Finger1 "},
        {HE::Equipment::Right_Finger2, "Right_Finger2 "},
        {HE::Equipment::Right_Finger3, "Right_Finger3 "}
};

/************************** constructor **************************************/
Hero::Hero()
{
}
Hero::Hero(std::string hero_name): hero_name(hero_name), max_AC(0),
                                   heroCurentPos(std::make_pair(0,0))
{
}
Hero::Hero(std::string hero_name, unsigned int HP, unsigned int MP,
bool isMain, Skill* skill): hero_name(hero_name), max_AC(0),
HP(std::make_pair(HP, HP)),MP(std::make_pair(MP, MP)) ,exp(0), isMain(isMain),
heroCurentPos(std::make_pair(0,0))
{
    //for test only
    skill_set.push_back(skill);//first skill will be given according to race/class
    exp_to_lvl_factor = 300;
    lvl = 2;
    setExp(990);
    setIsDead(false);
    std::cout << "*********************          is dead : "<<getIsDead() << "\n";
}
Hero::Hero(std::string name, unsigned int HP, bool isMain, int exp):
        hero_name(name), max_AC(0), HP(std::make_pair(HP, HP)), exp(exp),
        isMain(isMain)
{
    setIsDead(false);
    std::cout << "*********************          is dead : "<<getIsDead() << "\n";
}

int Hero::level_up()
{
    return 0;
}
int Hero::gain_exp(long int exp_amount)
{
    if((exp + exp_amount) > exp_to_lvl)
    {
        exp = exp + exp_amount;
        setLvl(++lvl);
        exp_to_lvl = exp_to_lvl_factor*(lvl - 1) + 2*(exp_to_lvl);
        level_up();
    }
    else
    {
        exp = exp + exp_amount;
    }
    return 0;
}
/*****************************************************************************/
int Hero::learn_skill(Skill *skill)
{
    //find returns true if skill is in skill_set
    if(std::find(skill_set.begin(), skill_set.end(), skill) != skill_set.end())
    {
        std::cout << "You know that skill already" << std::endl;
        return 1;
    }
    else
    {
        skill_set.push_back(skill);
    }
    return 0;
}
int Hero::prepare_to_fight()
{

    return 0;
}
int Hero::add_skill_to_skill_sequence(Skill* skill)
{
    if( lvl >= skill_sequence.size() )
    {
        skill_sequence.push_back(skill);
    }
    return 0;
}
int Hero::rm_skill_from_skill_sequence(Skill* skill)
{
    skill_sequence.erase(std::remove(skill_sequence.begin(),
                            skill_sequence.end(), skill), skill_sequence.end());
    return 0;
}
int Hero::show_skill_set()
{
    for(auto i : this->skill_set)
    {
        std::cout << i->getName() << "\n";
    }
    return 0;
}
int Hero::show_skill_sequence()
{
    for(auto i : this->skill_sequence)
    {
        std::cout << i->getName() << "\n";
    }
    return 0;
}
int Hero::set_skill_sequence()
{
    //modify layout
    return 0;
}
int Hero::show_inventory()
{
    std::cout << "******************* inventory **********************\n";
    int j=0;
    for(auto i : this->inventory)
    {
        std::cout << j++ << " - " << i->getName() << "\n";
    }
    return 0;
}
int Hero::hero_move_east()
{
    heroCurentPos.first++;
    return 0;
}
int Hero::hero_move_west()
{
    heroCurentPos.first--;
    return 0;
}
int Hero::hero_move_north()
{
    heroCurentPos.second++;
    return 0;
}
int Hero::hero_move_south()
{
    heroCurentPos.second--;
    return 0;
}

int Hero::pick_up_item(Item *picked_item)
{
    this->inventory.push_back(picked_item);
    return 0;
}
int Hero::equip_item(Item* item)
{
    auto equiped_item = equipment.insert(
                                    std::make_pair(item->place_to_equip, item));
    if (equiped_item.second)
    {
        destroy_item(item);
        std::cout << "zalozylem i usunalem \n";
    }
    else
    {
        inventory.push_back(equiped_item.first->second);
        equipment[item->place_to_equip] = item;
        destroy_item(item);
        std::cout << "podmienilem\n";
    }
    return 0;
}
int Hero::take_off_item(HE::Equipment item)
{
    inventory.push_back(equipment.find(item)->second);
    equipment.erase(equipment.find(item));
    return 0;
}
int Hero::destroy_item(Item* item)
{
    inventory.erase(std::remove(inventory.begin(),
                                 inventory.end(), item), inventory.end());
    return 0;
}
int Hero::set_initial_stats()
{
    return 0;
}
int Hero::set_stats()
{
    int tmpAC=0;
    std::pair<int, int> tmpDMG = std::make_pair(0, 0);
    for (auto& ith: equipment)
    {
        tmpAC += ith.second->getAC();
        tmpDMG.first +=ith.second->getDmg().first;
        tmpDMG.second +=ith.second->getDmg().second;
    }
    setMaxAC(tmpAC);
    setMinDmg((tmpDMG.first));
    setMaxDmg((tmpDMG.first) * (tmpDMG.second));
    return 0;
}
int Hero::show_equiped_items()
{
    std::cout << "******************* equipment **********************\n";
    for (auto& ith: equipment)
    {
        std::cout << EqToStrMap[ith.first] << " "
                  << ith.second->getName() << "\n";
    }
    return 0;
}
int Hero::use_skill(Hero* hero, Hero* target, Skill* skill)
{
    if(std::find(skill_set.begin(), skill_set.end(), skill) != skill_set.end())
    {
        if(((hero->getMp().first) - (skill->getMana_cost())) > 0 )
        {
            hero->setMp(std::make_pair(
            hero->getMp().first - skill->getMana_cost(), hero->getMp().second));

            for(auto i : skill->skill_effect)
            {
                i->active_effect(target) ;
            }
            return 1;
        }
        else
        {
            std::cout << "not enough mana" << std::endl;
        }
    }
    else
    {
        std::cout << "You don't know that skill";
    }
    return 0;
}
bool Hero::getIsDead()
{
    return isDead;
}
void Hero::setIsDead(bool isDead)
{
    this->isDead = isDead;
}
void Hero::setLvl(int lvl) {
    this->lvl = lvl;
}

int Hero::getExp() const {
	return exp;
}

void Hero::setExp(int exp) {
	this->exp = exp;
}

int Hero::getExpToLvl() const {
	return exp_to_lvl;
}

void Hero::setExpToLvl(int expToLvl) {
	exp_to_lvl = expToLvl;
}

std::string Hero::getName() const {
	return hero_name;
}

void Hero::setName(const std::string& heroName) {
	hero_name = heroName;
}

const std::vector<Item *>& Hero::getInventory() const {
	return inventory;
}

void Hero::setInventory(const std::vector<Item *>& inventory) {
	this->inventory = inventory;
}

int Hero::getMaxAttakSpeed() const {
	return max_attak_speed;
}

void Hero::setMaxAttakSpeed(int maxAttakSpeed) {
	max_attak_speed = maxAttakSpeed;
}

int Hero::getMaxDexterity() const {
	return max_dexterity;
}

void Hero::setMaxDexterity(int maxDexterity) {
	max_dexterity = maxDexterity;
}

std::pair <unsigned int, unsigned int> Hero::getHp() const {
	return HP;
}

void Hero::setHp(std::pair <unsigned int, unsigned int> Hp)
{
    HP = Hp;
}
void Hero::showHp()
{
    std::cout << "HP: " << HP.first << "/" << HP.second << std::endl;
}
std::pair <unsigned int, unsigned int> Hero::getMp() const {
    return MP;
}

void Hero::setMp(std::pair <unsigned int, unsigned int> Mp)
{
    MP = Mp;
}
void Hero::showMp()
{
    std::cout << "MP: " << MP.first << "/" << MP.second << std::endl;
}
int Hero::getMaxHunger() const {
	return max_hunger;
}

void Hero::setMaxHunger(int maxHunger) {
	max_hunger = maxHunger;
}

int Hero::getMaxIntellect() const {
	return max_intellect;
}

void Hero::setMaxIntellect(int maxIntellect) {
	max_intellect = maxIntellect;
}

int Hero::getMaxAC() const {
    return max_AC;
}

void Hero::setMaxAC(int maxAC) {
	max_AC = +maxAC;
}

int Hero::getMaxDmg() const {
	return max_max_dmg;
}

void Hero::setMaxDmg(int maxMaxDmg) {
	max_max_dmg = maxMaxDmg;
}

int Hero::getMinDmg() const {
	return max_min_dmg;
}

void Hero::setMinDmg(int maxMinDmg) {
	max_min_dmg = maxMinDmg;
}

int Hero::getMaxMov() const {
	return max_MOV;
}

void Hero::setMaxMov(int maxMov) {
	max_MOV = maxMov;
}

int Hero::getMaxMp() const {
	return max_MP;
}

void Hero::setMaxMp(int maxMp) {
	max_MP = maxMp;
}

int Hero::getMaxResistEarth() const {
	return max_resist_earth;
}

void Hero::setMaxResistEarth(int maxResistEarth) {
	max_resist_earth = maxResistEarth;
}

int Hero::getMaxResistFire() const {
	return max_resist_fire;
}

void Hero::setMaxResistFire(int maxResistFire) {
	max_resist_fire = maxResistFire;
}

int Hero::getMaxResistPioson() const {
	return max_resist_poison;
}

void Hero::setMaxResistPioson(int maxResistPioson) {
	max_resist_poison = maxResistPioson;
}

int Hero::getMaxResistWater() const {
	return max_resist_water;
}

void Hero::setMaxResistWater(int maxResistWater) {
	max_resist_water = maxResistWater;
}

int Hero::getMaxResistWind() const {
	return max_resist_wind;
}

void Hero::setMaxResistWind(int maxResistWind) {
	max_resist_wind = maxResistWind;
}

int Hero::getMaxStrenth() const {
	return max_strenth;
}

void Hero::setMaxStrenth(int maxStrenth) {
	max_strenth = maxStrenth;
}

int Hero::getMaxWeightLimit() const {
	return max_weight_limit;
}

void Hero::setMaxWeightLimit(int maxWeightLimit) {
	max_weight_limit = maxWeightLimit;
}

int Hero::getMaxWisdom() const {
	return max_wisdom;
}

void Hero::setMaxWisdom(int maxWisdom) {
	max_wisdom = maxWisdom;
}

const std::vector<Skill*>& Hero::getSkillSet() const {
	return skill_set;
}

void Hero::setSkillSet(const std::vector<Skill*>& skillSet) {
	skill_set = skillSet;
}
