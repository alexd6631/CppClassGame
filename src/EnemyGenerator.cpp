#include "EnemyGenerator.h"
#include "ofMain.h"

EnemyGenerator::EnemyGenerator() {
    //ctor
}

void EnemyGenerator::reinitCounter() {
    remainingFrames = ofRandom(50, 150);
}

void EnemyGenerator::setup() {
    reinitCounter();
}

bool EnemyGenerator::update() {
    return --remainingFrames <= 0;
}

Enemy EnemyGenerator::createEnemy() {
    if (remainingFrames > 0) {
        throw string("Impossible de créer l'ennemi");
    }
    reinitCounter();
    return Enemy();
}
