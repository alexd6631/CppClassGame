#ifndef MISSILE_H
#define MISSILE_H

#include "ofMain.h"

class Missile
{
    private:
        static const int WIDTH;
        static const int HEIGHT;
        ofRectangle rect;
    public:
        Missile(float x, float y);
        void update();
        void draw() const;
        bool isOutside() const;
        const ofRectangle &getRect() const;
};

#endif // MISSILE_H
