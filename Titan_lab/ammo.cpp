//
//  ammo.cpp
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#include "ammo.h"
#include <iostream>
using std::cout;

int Ammo::getPenetration(){
    return gun.getCaliber();
}

int HEATCartridge::getDamage(){
//    cout << "\n HEATCartridge\n";
    return static_cast<int>(Ammo::getDamage() * 0.6);
}
int APCartridge::getDamage() {
//    cout << "\n APCartridge\n";
    return static_cast<int>(Ammo::getDamage() * 0.3);
}
int HVAmmo::getDamage() {
//    cout << "\n HVAmmo\n";
    return static_cast<int>(Ammo::getDamage() * 0.3);

}

Ammo::Ammo() {
    gun = Gun();
    type = "High Velocity";
}
