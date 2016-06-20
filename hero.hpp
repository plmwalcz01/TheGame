#ifndef _HERO
#define _HERO
//#pragma once
#include <map>
#include "skill.hpp"
#include "item.hpp"
#include "hero_enums.hpp"

class Hero
{
    private:
    std::string hero_name;
    std::string hero_race;
    std::string hero_class;
    std::map<HE::Equipment, Item* > equipment;
    int max_strenth;
    int max_dexterity;
    int max_intellect;
    int max_wisdom;
    int max_AC;
    std::pair <unsigned int, unsigned int> HP;
    std::pair <unsigned int, unsigned int> MP;
    int max_MP;
    int max_MOV;
    int max_hunger;
    int max_attak_speed;
    int max_min_dmg;
    int max_max_dmg;
    int max_chance_to_hit;
    int max_critical_chance;
    int max_critical_dmg;
    int max_resist_fire;
    int max_resist_water;
    int max_resist_wind;
    int max_resist_earth;
    int max_resist_poison;
    int max_weight_limit;
    unsigned int exp_to_lvl;
    int exp_to_lvl_factor; // can differ with different heroes
    unsigned long int exp;
    unsigned int lvl;
    bool isDead;

    public:
    bool isMain;
    std::vector<Skill *> skill_set;
    std::vector<Skill*> skill_sequence;
    std::vector<Item *> inventory;
    std::vector<Effect*> buffs_debuffs;
    std::pair<int, int> heroCurentPos;

    Hero();
    Hero(std::string);
    Hero(std::string name, unsigned int HP, unsigned int MP, bool isMain,
                                                        Skill* starting_skill);
    Hero(std::string name, unsigned int HP, bool isMain, int exp);
    int level_up();
    int gain_exp(long int);
    int learn_skill(Skill*);
    int prepare_to_fight();
    int add_skill_to_skill_sequence(Skill*);
    int rm_skill_from_skill_sequence(Skill*);
    int set_skill_sequence();
    int show_skill_set();
    int show_skill_sequence();
    int attack();
    int steal();
    int show_inventory();
    int hero_move_east();
    int hero_move_west();
    int hero_move_north();
    int hero_move_south();
    int pick_up_item(Item*);
    int equip_item(Item*);
    int take_off_item(HE::Equipment);
    int destroy_item(Item*);
    int set_initial_stats();
    int set_stats();
    int repair();
    int identify();
    int show_equiped_items();
    int use_skill(Hero* source, Hero* target,  Skill*);


    std::string getName() const;
    void setName(const std::string& heroName);
    const std::vector<Skill*>& getSkillSet() const;
    void setSkillSet(const std::vector<Skill*>& skillSet);
    const std::vector<Item *>& getInventory() const;
    void setInventory(const std::vector<Item *>& inventory);
    const std::vector<Effect*>& getBuffs_Debuffs() const;
    void setInventory(const std::vector<Effect*>& buffs_debuffs);

    bool getIsDead();
    void setIsDead(bool);
    void setLvl(int lvl);
    int getExp() const;
    void setExp(int exp);
    int getExpToLvl() const;
    void setExpToLvl(int expToLvl);
    int getMaxAttakSpeed() const;
    void setMaxAttakSpeed(int maxAttakSpeed);
    int getMaxDexterity() const;
    void setMaxDexterity(int maxDexterity);
    std::pair <unsigned int, unsigned int> getHp() const;
    void setHp(std::pair <unsigned int, unsigned int> Hp);
    void showHp();
    std::pair <unsigned int, unsigned int> getMp() const;
    void setMp(std::pair <unsigned int, unsigned int> Mp);
    void showMp();
    int getMaxHunger() const;
    void setMaxHunger(int maxHunger);
    int getMaxIntellect() const;
    void setMaxIntellect(int maxIntellect);
    int getMaxAC() const;
    void setMaxAC(int maxAC);
    int getMaxDmg() const;
    void setMaxDmg(int maxMaxDmg);
    int getMinDmg() const;
    void setMinDmg(int maxMinDmg);
    int getMaxMov() const;
    void setMaxMov(int maxMov);
    int getMaxMp() const;
    void setMaxMp(int maxMp);
    int getMaxResistEarth() const;
    void setMaxResistEarth(int maxResistEarth);
    int getMaxResistFire() const;
    void setMaxResistFire(int maxResistFire);
    int getMaxResistPioson() const;
    void setMaxResistPioson(int maxResistPioson);
    int getMaxResistWater() const;
    void setMaxResistWater(int maxResistWater);
    int getMaxResistWind() const;
    void setMaxResistWind(int maxResistWind);
    int getMaxStrenth() const;
    void setMaxStrenth(int maxStrenth);
    int getMaxWeightLimit() const;
    void setMaxWeightLimit(int maxWeightLimit);
    int getMaxWisdom() const;
    void setMaxWisdom(int maxWisdom);

};
#endif //_HERO
