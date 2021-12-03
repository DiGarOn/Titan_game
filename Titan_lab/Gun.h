//
//  Gun.h
//  Titan_lab
//
//  Created by Dmitriy Garkin on 02.12.2021.
//

#ifndef Gun_h
#define Gun_h

class Gun {
private:
    int _caliber;
    int _barrelLength;
public:
    Gun();
    Gun(int caliber, int barrelLength);
    Gun(const Gun&);

    int getCaliber() const;
    bool isHit(int random);
};

#endif /* Gun_h */
