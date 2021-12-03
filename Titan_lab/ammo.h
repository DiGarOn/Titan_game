//
//  ammo.h
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#ifndef ammo_h
#define ammo_h

#include <utility>

#include "Gun.h"
#include <string>
class Ammo {
private:
    Gun gun;
    bool null;
public:
    std::string type;
    Ammo();
    Ammo(const Ammo& ammo) : gun(ammo.gun), type(ammo.type) {}
    Ammo(Gun someGun, std::string type) : gun(someGun), type(std::move(type)) {}
    virtual int getDamage() {
        return gun.getCaliber() * 3;
    };
    int getPenetration();   
};

class HEATCartridge : public Ammo{
public:
    virtual int getDamage();
    HEATCartridge(Gun someGun) : Ammo(someGun, "cummulative"){}
};

class APCartridge : public Ammo {
public:
    APCartridge(Gun someGun) : Ammo(someGun, "podkaliberny") {}
    virtual int getDamage();
};

class HVAmmo : public Ammo {
public:
    HVAmmo(Gun someGun) : Ammo(someGun, "High Velocity") {}
    virtual int getDamage();
};

#endif /* ammo_h */
