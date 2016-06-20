/*
 * hero_enums.hpp
 *
 *  Created on: Oct 7, 2015
 *      Author: plmwalcz01
 */

#pragma once
namespace HE
{
    enum class Race
    {
        elf, dwarf, ork, human, dark_elf
    };
    enum class Class
    {
        warrior, mage, rogue
    };
    enum class Equipment
    {
        Head, Torso, Legs, Hands, Arms, Feet, Neck, Waist, Cape, Weapon, Shield,
        Left_Ear, Right_Ear,
        Left_Finger1, Left_Finger2, Left_Finger3,
        Right_Finger1, Right_Finger2, Right_Finger3
    };
} // end of namespace HE

