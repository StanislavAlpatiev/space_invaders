#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Session.h"
#include <SDL2/SDL.h>
#include <string>
#include "Controller.h"

namespace cwing
{
	class Sprite : public Component
	{
	public:
		enum Direction
		{
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		static Sprite *getInstance(int x, int y, int w, int h, std::string image_path);
		int SPEED = 20;

		const bool isOutOfBounds() const;
		const bool isOutOfBoundsRight() const;
		const bool isOutOfBoundsLeft() const;
		const bool isMovementAllowed(Direction dir) const;
		void kill();
		void takeDamage() { health--; };

		void removal() { this->~Sprite(); };

		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		Component *perform(SDL_Event event);
		void draw() const;
		~Sprite();

	protected:
		short int health;
		Sprite(int x, int y, int w, int h, std::string images_path);
		SDL_Texture *sprite;
	// private:
	};
}

extern std::string IMAGES_PATH;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

#endif