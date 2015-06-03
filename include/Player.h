#ifndef PLAYER_H
#define PLAYER_H

#include "ofRectangle.h"

class Player
{
    private:
        ofRectangle rect;
    public:
        Player();
        void setup();
        void mouseMoved(int x, int y);
        void update();
        void draw() const;
};

#endif // PLAYER_H
