#include "Star.h"
#include "ofMain.h"

Star::Star() {
    //ctor
}

void Star::setup() {
    x = ofRandom(ofGetWidth());
    y = ofRandom(ofGetHeight());
    radius = ofRandom(1.5, 4);
}

void Star::update() {
    float speed = 2 * radius;
    y += speed;
    if (y > ofGetHeight()) {
        y = 0;
        x = ofRandom(ofGetWidth());
    }
}

void Star::draw() const {
    ofFill();
    ofSetColor(255, 255, 255);
    ofCircle(x, y, radius);
}
