#include "ofApp.h"
#include "Star.h"
#include "Player.h"
#include "Missile.h"

const int NSTARS = 25;

Star stars[NSTARS];
Player player;

std::list<Missile> missiles;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);

    player.setup();
    for (int i=0; i<NSTARS; i++) {
        stars[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    player.update();
    for (int i=0; i<NSTARS; i++) {
        stars[i].update();
    }

    for (std::list<Missile>::iterator it = missiles.begin();
         it != missiles.end();
         ) {
        it->update();
        if (it->isOutside()) {
            it = missiles.erase(it);
        } else {
            it++;
        }
    }

    cout << missiles.size() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<NSTARS; i++) {
        stars[i].draw();
    }
    player.draw();

    for (std::list<Missile>::iterator it = missiles.begin();
         it != missiles.end();
         it++) {
        it->draw();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    player.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    player.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Missile m = player.fireMissile();
    missiles.push_back(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
