//
//  armour.h
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#ifndef armour_h
#define armour_h

#include <string>
#include "ammo.h"

using std::string;

class Armour {
public:
    int thickness;
    string type; // light, heavy, medium

    Armour();
    
    Armour(int new_thickness, string new_type);

    bool isPenetrated(Ammo projectile);

};

class HArmour : public Armour {
public:
    HArmour(int thickness) : Armour(thickness, "Heavy") {}

    bool isPenetrated(Ammo projectile);
};

class LArmour : public Armour {
public:
    LArmour(int thickness) : Armour(thickness, "Light") {}

    bool isPenetrated(Ammo projectile);
};

class MArmour : public Armour {
public:
    MArmour(int thickness) : Armour(thickness, "Medium") {}

    bool isPenetrated(Ammo projectile);
};

#endif /* armour_h */
