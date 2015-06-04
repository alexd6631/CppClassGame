#ifndef PLAYER_H
#define PLAYER_H

#include "ofRectangle.h"
#include "Missile.h"

class Player
{
    private:
        ofRectangle rect;
        unsigned long long lastMissileTime;
    public:
        Player();
        void setup();
        void mouseMoved(int x, int y);
        void update();
        void draw() const;

        bool canFireMissile();
        Missile fireMissile();
};

#endif // PLAYER_H
