#ifndef ENEMY_H
#define ENEMY_H

#include "ofMain.h"

class Enemy
{
    private:
        ofRectangle rect;
        const float x0;
    public:
        Enemy();
        virtual ~Enemy();

        void update();
        void draw() const;
        bool isOutside();
        const ofRectangle &getRect() const;
    protected:

};

#endif // ENEMY_H
