#ifndef ENEMYGENERATOR_H
#define ENEMYGENERATOR_H

#include "Enemy.h"

class EnemyGenerator
{
    private:
        int remainingFrames;
        void reinitCounter();
    public:
        EnemyGenerator();
        void setup();
        bool update();
        Enemy createEnemy();
};

#endif // ENEMYGENERATOR_H
