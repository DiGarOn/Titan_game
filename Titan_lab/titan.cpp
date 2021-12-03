//
//  titan.cpp
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#include "titan.h"
#include "armour.h"
#include <iostream>

using namespace std;

Titan::Titan(std::string name, Gun someGun, int armourWidth, int health) {
    model = name;
    gun = someGun;
//    cout << "\n calibr: " << gun.getCaliber() << "\n";
    armours = vector<Armour>();
    ammos = vector<Ammo>();
    addArmours(armourWidth);
    loadAmmos();
    loadedAmmo = Ammo(someGun, "High Velocity");
    ammo_pointer = nullptr;
    selectedArmour = armours[0];

    kernel = TitansKernel(health);
}

void Titan::addArmours(int armourWidth) {
    armours.push_back(HArmour(armourWidth));
    armours.push_back(LArmour(armourWidth));
    armours.push_back(MArmour(armourWidth));
}

void Titan::loadAmmos() {
    for(int i = 0; i < 10; i++)
    {
        ammos.push_back(HVAmmo(this->gun));
        ammos.push_back(HEATCartridge(this->gun));
        ammos.push_back(APCartridge(this->gun));
    }
}


void Titan::loadGun(const string& type){
    for (int i = 0; i < ammos.size(); ++i){
        if (ammos[i].type == type){
            loadedAmmo = ammos[i];
            ammo_pointer = &loadedAmmo;
            cout << "Loaded!!!\n";
//            cout << "\n damage: " << loadedAmmo.getDamage() << "\n";
            return;
        }
    }
    cout << "Sheeesh! We are out of \n" << type;
}
void Titan::selectArmour(const string& type){
    for (int i = 0; i < armours.size(); ++i){
        if (armours[i].type == type){
            selectedArmour = armours[i];
        }
    }
}
Ammo* Titan::shoot(){
    if (ammo_pointer != nullptr){
        Ammo firedAmmo = Ammo(loadedAmmo);
        for(auto i = ammos.begin(); i != ammos.end();) {
            if(i->type == loadedAmmo.type) {
                ammos.erase(i);
                break;
            } else {
                ++i;
            }
        }
//        ammos.erase(ammos.begin() + ammos.find(ammos.begin(), ammos.end(), loadedAmmo));
        ammo_pointer = nullptr;
        srand(std::time(nullptr)); // use current time as seed for random generator
        int random_variable = 0+std::rand()%100;
        bool hit = gun.isHit(random_variable);
        if (hit){
            cout << "Hit!\n";
            return &loadedAmmo;
        }
        else{
            cout << "Miss!\n";
            return nullptr;
        }
    }
    else{
        cout << "not loaded!\n";
        return nullptr;
    }
}

void Titan::armourHitHandle(Ammo projectile) {
    if (selectedArmour.isPenetrated(projectile)) {
        kernel.handleHit(projectile);
    }
}
