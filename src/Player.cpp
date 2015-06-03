#include "Player.h"
#include "ofMain.h"

static const int W = 50;
static const int H = 80;

Player::Player() {
    //ctor
}

void Player::setup() {
    rect = ofRectangle();
    rect.setFromCenter(ofGetWidth()/2,
                       ofGetHeight() - 100,
                       W, H);
}

void Player::mouseMoved(int x, int y) {
    //TODO
    rect.setX(x - W / 2);
}

void Player::update() {
    //vide
}

void Player::draw() const {
    ofFill();
    ofSetColor(0, 0, 255);
    float x = rect.getX();
    float y = rect.getY();

    ofTriangle(
       x, y + H,
       x + W / 2, y,
       x + W, y + H
    );
}

Missile Player::fireMissile() {
    ofPoint center = rect.getCenter();
    return Missile(center.x, center.y);
}
