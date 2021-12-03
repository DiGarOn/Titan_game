//
//  Gun.cpp
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#include "Gun.h"

Gun::Gun() {
    _caliber = 100;
    _barrelLength = 100;
}

Gun::Gun(int caliber, int barrelLength) {
    _caliber = caliber;
    _barrelLength = barrelLength;
}

int Gun::getCaliber() const {
    return _caliber;
}

bool Gun::isHit(int random) {
    return (_barrelLength + random) > 100;
}

Gun::Gun(const Gun& a) : _caliber(a._caliber), _barrelLength(a._barrelLength){}
