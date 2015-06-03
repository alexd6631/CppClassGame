#include "Missile.h"

const int Missile::WIDTH = 10;
const int Missile::HEIGHT = 50;

Missile::Missile(float x, float y) {
    rect = ofRectangle();
    rect.setFromCenter(x, y, WIDTH, HEIGHT);
}

void Missile::update() {
    rect.translate(0, -10);
}

void Missile::draw() const {
    ofFill();
    ofSetColor(255, 0, 0);
    ofRect(rect);
}

bool Missile::isOutside() const {
    return rect.getBottom() < 0;
}
