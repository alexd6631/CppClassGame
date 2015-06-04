#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);

    player.setup();
    for (int i=0; i<NSTARS; i++) {
        stars[i].setup();
    }
    enemyGenerator.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
    float fps = ofGetFrameRate();
    if (fps < 58) {
        cout << "FPS " << ofGetFrameRate() << endl;
    }

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

    for (std::list<Enemy>::iterator it = enemies.begin();
         it != enemies.end();
         ) {
        it->update();
        if (it->isOutside()) {
            it = enemies.erase(it);
        } else {
            it++;
        }
    }

    if (enemyGenerator.update()) {
        Enemy e = enemyGenerator.createEnemy();
        enemies.push_back(e);
    }

    for (std::list<Enemy>::iterator eit = enemies.begin();
         eit != enemies.end();) {
        for (std::list<Missile>::iterator mit = missiles.begin();
         mit != missiles.end();) {
            if (collisionMissileEnemy(*mit, *eit)) {
                cout << "Collision" << endl;
                missiles.erase(mit);
                enemies.erase(eit);
                break;
            }
            mit++;
         }
        eit++;
    }


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

    for (std::list<Enemy>::iterator it = enemies.begin();
         it != enemies.end();
         it++) {
        it->draw();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 32) {
        tryFireMissile();
    }
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
    tryFireMissile();
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

void ofApp::tryFireMissile() {
    if (player.canFireMissile()) {
        Missile m = player.fireMissile();
        missiles.push_back(m);
    } else {
        cout << "Surchauffe" << endl;
    }
}

bool ofApp::collisionMissileEnemy(const Missile &m, const Enemy &e) const {
    return m.getRect().intersects(e.getRect());
}

bool ofApp::collisionPlayerEnemy(const Player &p, const Enemy &e) const {
    return p.getRect().intersects(e.getRect());
}
