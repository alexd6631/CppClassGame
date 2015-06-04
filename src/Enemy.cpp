#include "Enemy.h"

Enemy::Enemy() : x0( ofRandom(0, ofGetWidth()) )
{
    rect = ofRectangle();
    rect.setFromCenter(x0, 0, 50, 80);
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::update() {
    rect.translate(0, 5);
    rect.setX(100 * cos(0.01 * rect.getY()) + x0);
}

void Enemy::draw() const {
    ofSetColor(0, 255, 0);
    ofRect(rect);
}

bool Enemy::isOutside() {
    return rect.getY() > ofGetHeight();
}
