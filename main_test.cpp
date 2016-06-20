#include <map>
#include <utility>
#include <string>
#include <iostream>
#include "hero.hpp"
#include "weapon.hpp"
#include "location.hpp"
#include "game.hpp"

int main ()
{
    Game game;
    Skill rest("rest", 0);
    Hero hero("Michal", 50, 100, true, &rest);
    game.initialize_hero(&hero);
    Item item("goo");
    Item *ptr_item = &item;

    Weapon weapon("sword", std::make_pair(1, 4), HE::Equipment::Weapon);
    Weapon *ptr_weapon = &weapon;

    game.hero.pick_up_item(ptr_item);
    ptr_item = static_cast <Item *> (ptr_weapon);
    game.hero.pick_up_item(ptr_item);
    game.hero.getInventory()[1]->setDmg(std::make_pair(1, 4));
    std::cout << game.hero.getName() << std::endl;
    std::cout << game.hero.getInventory()[0]->getName() << std::endl;
    std::cout << game.hero.getInventory()[1]->getName() << " dmg "
              << std::endl;
    game.insert_location(game.generate_location(std::pair<int, int>(0, 0)));
    game.insert_location(game.generate_location(std::pair<int, int>(0, 1)));
    game.insert_location(game.generate_location(std::pair<int, int>(1, 0)));
    game.insert_location(game.generate_location(std::pair<int, int>(0, -1)));
    game.insert_location(game.generate_location(std::pair<int, int>(-1, 0)));

    for (auto& x: game.map)
    {
        std::cout << x.first.first << " " << x.first.second << " ID = "
            << x.second->getLocationID()<< " " << x.second->showLocationItems()
            << "\n";
           //game.map.at(std::make_pair(0,-1))->getLocationID() << '\n';
    }
    std::cout << "*******************move tests ************************\n";

    game.hero.hero_move_east();
    game.map_ith = game.map.find(game.hero.heroCurentPos);
    std::cout << "*******************after find  ************************\n";
    std::cout << "*game.hero.heroCurentPos\n" << game.hero.heroCurentPos.first
              << game.hero.heroCurentPos.second;
    std::cout << game.map_ith->first.first << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID() << " "
    << game.map_ith->second->showLocationItems() <<"\n";

    game.hero.hero_move_west();
    game.hero.hero_move_west();
    game.map_ith = game.map.find(game.hero.heroCurentPos);
    std::cout << game.map_ith->first.first
    << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID()
    << " " << game.map_ith->second->showLocationItems()<< "\n";
    game.hero.hero_move_east();
    game.hero.hero_move_north();
    game.map_ith = game.map.find(game.hero.heroCurentPos);
    std::cout << game.map_ith->first.first
    << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID()
    << " " << game.map_ith->second->showLocationItems()<< "\n";

    std::cout << "*******************pickup tests ************************\n";

    game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(1));
    game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(3));
    std::cout << game.map_ith->first.first
    << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID()
    << " " << game.map_ith->second->showLocationItems() << "\n";
    game.hero.hero_move_south();
    game.hero.hero_move_east();
    game.map_ith = game.map.find(game.hero.heroCurentPos);
    std::cout << game.map_ith->first.first
    << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID()
    << " " << game.map_ith->second->showLocationItems() << "\n";
    game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(2));
    game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(1));
    game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(1));
    //game.item_transfer(&game.hero, game.map_ith->second->getLocationItems(1));
    std::cout << game.map_ith->first.first
    << " " << game.map_ith->first.second
    << " ID = " << game.map_ith->second->getLocationID()
    << " " << game.map_ith->second->showLocationItems() << "\n";
    game.hero.show_inventory();

    std::cout << "*******************wear item tests ***********************\n";
    game.hero.show_inventory();
    std::cout << " equipuje 2 - ";
    game.hero.equip_item(game.hero.inventory[2]);
    game.hero.show_inventory();
    std::cout << " equipuje 2 - ";
    game.hero.equip_item(game.hero.inventory[2]);
    game.hero.show_inventory();
    std::cout << " equipuje 2 - ";
    game.hero.equip_item(game.hero.inventory[2]);
    game.hero.show_inventory();
    std::cout << " equipuje 2 - ";
    game.hero.equip_item(game.hero.inventory[2]);
    std::cout << " poka inv - ";
    game.hero.show_inventory();

    game.hero.show_equiped_items();
    std::cout << "************* equiped items effects tests ****************\n";
    game.hero.set_stats();
    std::cout << "MaxAC : " << game.hero.getMaxAC() << "\n";
    game.hero.equip_item(game.hero.inventory[2]);
    game.hero.set_stats();
    std::cout << "MaxAC : " << game.hero.getMaxAC()<< "\n";
    game.hero.take_off_item(HE::Equipment::Torso);
    game.hero.show_equiped_items();
    game.hero.set_stats();
    std::cout << "MaxAC : " << game.hero.getMaxAC()<< "\n";
    std::cout << "MinDMG : " << game.hero.getMinDmg()<< "\n";
    std::cout << "MaxDMG : " << game.hero.getMaxDmg()<< "\n";
    std::cout << "*************npc on loc tests ***************************\n";
    game.map_ith->second->showLocationNPC();

    std::cout << "*************skill tests ********************************\n";
    Effect Heal(EE::Name::Heal, 10);
    Effect DealDMG(EE::Name::DealDMG, 70);
    Skill power_smash("power_smash", 5), shield_bash("shield_bash", 10);
    Skill meditate("meditate", 0);
    power_smash.skill_effect.push_back(&DealDMG);
    shield_bash.skill_effect.push_back(&DealDMG);
    meditate.skill_effect.push_back(&Heal);
    Skill* ptr_to_skill;
    ptr_to_skill = &power_smash;
    ptr_to_skill->showEffects();
    game.hero.learn_skill(ptr_to_skill);
    game.hero.learn_skill(ptr_to_skill);
    ptr_to_skill = &shield_bash;
    ptr_to_skill->showEffects();
    game.hero.learn_skill(ptr_to_skill);
    ptr_to_skill = &meditate;
    ptr_to_skill->showEffects();
    game.hero.learn_skill(ptr_to_skill);
    game.hero.show_skill_set();

    std::cout << "*************skill sequence ************************\n";
    game.hero.add_skill_to_skill_sequence(&power_smash);
    game.hero.add_skill_to_skill_sequence(&meditate);
    game.hero.show_skill_sequence();

    std::cout << "************* use skill  ************************\n";
    game.hero.showMp();
    game.map_ith->second->showLocationNPC();
    game.hero.use_skill(
            &game.hero,
            game.map_ith->second->getLocationNPC(0),
            &power_smash);
    game.map_ith->second->showLocationNPC();
    game.hero.showMp();

    std::cout << "*************active effect tests ************************\n";
    game.hero.showHp();
    game.map_ith->second->showLocationNPC();

    return 0;
}
