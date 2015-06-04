#pragma once

#include "ofMain.h"
#include "Star.h"
#include "Player.h"
#include "Missile.h"
#include "Enemy.h"
#include "EnemyGenerator.h"

class ofApp : public ofBaseApp{
    private:
        static const int NSTARS = 25;
        Star stars[NSTARS];
        Player player;
        std::list<Missile> missiles;
        std::list<Enemy> enemies;
        EnemyGenerator enemyGenerator;

        void tryFireMissile();
        bool collisionMissileEnemy(const Missile &m, const Enemy &e) const;
        bool collisionPlayerEnemy(const Player &p, const Enemy &e) const;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};
