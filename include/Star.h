#ifndef STAR_H
#define STAR_H

class Star
{
    private:
        float x;
        float y;
        float radius;
    public:
        Star();
        void setup();
        void update();
        void draw() const;
};

#endif // STAR_H
