#include "NPC.hpp"

/************************** constructor **************************************/
NPC::NPC(int agro, std::string name, unsigned int HP, bool isMain, int exp):
 Hero(name, HP, isMain, exp), aggressiveness(agro)
{
}
/*****************************************************************************/
int NPC::show_NCP()
{
    std::cout << getName() << " ";
    this->showHp();
    return 0;
}

