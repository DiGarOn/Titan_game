//
//  titan.h
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#ifndef titan_h
#define titan_h

#include "Gun.h"
#include "ammo.h"
#include "armour.h"
#include <vector>
#include <string>
using namespace std;
class Titan {
private:
    string model;
    Gun gun;
    vector<Armour> armours;
    vector<Ammo> ammos;
    Ammo loadedAmmo;
    Armour selectedArmour;
    Ammo * ammo_pointer = &loadedAmmo;

    class TitansKernel {
    private:
        int health;
    public:
        explicit TitansKernel(int health_) : health(health_) {}
        TitansKernel() : health(500){}

        int getHealth() {
            return health;
        }
        void handleHit(Ammo projectile) {
            health -= projectile.getDamage();
        }
    };

    TitansKernel kernel;
public:
    Titan(std::string name, Gun someGun, int armourWidth, int health);

    void setLoadedAmmo(Ammo new_loadedAmmo){
        loadedAmmo = new_loadedAmmo;
    }
    void setSelectedArmour(Armour selectedArmour){
        this->selectedArmour = selectedArmour;
    }
    Ammo getLoadedAmmo(){
        return loadedAmmo;
    }
    Armour getSelectedArmour(){
        return selectedArmour;
    }

    void addArmours(int armourWidth);
    void loadAmmos();
    void selectArmour(const string&);
    void loadGun(const string&);
    void armourHitHandle(Ammo projectile);
    Ammo* shoot();

};

#endif /* titan_h */
