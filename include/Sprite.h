#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <string>

namespace cwing
{
	class Sprite : public Component
	{
	public:
		enum Direction {UP, DOWN, LEFT, RIGHT};
		static Sprite *getInstance(int x, int y, int w, int h, std::string image_path);
		int SPEED = 20;
		const bool isOutOfBounds();
		const bool isMovementAllowed(Direction dir);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void perform(SDL_Event event);
		void draw() const;
		~Sprite();

	protected:
		Sprite(int x, int y, int w, int h, std::string images_path);

	private:
		SDL_Texture *texture;
		SDL_Texture *sprite;
	};
}

extern std::string IMAGES_PATH;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

#endif