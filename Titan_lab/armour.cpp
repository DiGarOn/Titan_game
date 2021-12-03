//
//  armour.cpp
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#include "armour.h"
#include "ammo.h"

using namespace std;

template<typename Base, typename T> inline bool instanceof(const T*) {
    return is_base_of<Base, T>::value;
}

Armour::Armour() {
    thickness = 0;
    type = "light";
}

Armour::Armour(int new_thickness, string new_type){
    thickness = new_thickness;
    type = new_type;
}

bool Armour::isPenetrated(Ammo projectile){
    return projectile.getDamage() > thickness;
}

bool HArmour::isPenetrated(Ammo projectile) {
    if (typeid(HEATCartridge) == typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 1.2;
    }
    if (typeid(HVAmmo)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 1.5;
    }
    if (typeid(APCartridge)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 0.9;
    }
    else {
        return projectile.getPenetration() > this->thickness * 1;
    }
}

bool LArmour::isPenetrated(Ammo projectile) {
    if (typeid(HEATCartridge)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 1.1;
    }
    if (typeid(HVAmmo)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 0.5;
    }
    if (typeid(APCartridge)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 0.9;
    }
    else {
        return projectile.getPenetration() > this->thickness * 1;
    }
}

bool MArmour::isPenetrated(Ammo projectile) {
    if (typeid(HEATCartridge)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 1.2;
    }
    if (typeid(HVAmmo)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 0.8;
    }
    if (typeid(APCartridge)==typeid(projectile)) {
        return projectile.getPenetration() > this->thickness * 1;
    }
    else {
        return projectile.getPenetration() > this->thickness * 1;
    }
}

