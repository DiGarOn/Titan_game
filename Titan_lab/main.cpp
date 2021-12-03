//
//  main.cpp
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#include <iostream>
#include "titan.h"

int main() {
    Gun Sniper = Gun(50, 700);
//    cout << "\n here1 \n";
    Titan NorthStar = Titan("North Star", Sniper, 400, 800);
//    cout << "\n here2 \n";
    NorthStar.loadGun("High Velocity");
//    cout << "\n here3 \n";
    NorthStar.selectArmour("Light");
//    cout << "\n here4 \n";
    Ammo* shotAmmo = NorthStar.shoot();
//    cout << "\n here5 \n";
    Titan SecondTitan = Titan("SecondTitan", Sniper, 400, 800);
//    cout << "\n here6 \n";
    SecondTitan.armourHitHandle(*shotAmmo);
}

