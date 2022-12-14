#ifndef DEBRIS_H
#define DEBRIS_H

#include "Sprite.h"

namespace space_invaders
{
    class Debris : public Sprite
    {
    public:
        static Debris *getInstance(int x, int y, int w, int h, std::string image_path, int speed, short int health);
        // void moveUp();
        // void moveDown();
        void moveLeft();
        // void moveRight();
        void spinDebris(const int &speed);
        void setAngle(const int &angle);
        void draw() const;
        Component *perform(SDL_Event event);
        ~Debris();

    protected:
        Debris(int x, int y, int w, int h, std::string images_path, int speed, short int health);

    private:
        Debris(const Debris& debris) = delete;
        const Debris &operator=(const Debris &) = delete;
        float angle = 0;
        int spinDir, spinEveryXFrame, spinCounter;
    };
}

extern std::string IMAGES_PATH;

#endif
