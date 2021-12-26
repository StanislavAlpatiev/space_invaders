#include "Sprite.h"
#include <SDL2/SDL_ttf.h>
#include "System.h"
#include <SDL2/SDL_image.h>

namespace cwing
{

	Sprite::Sprite(int x, int y, int w, int h, std::string image_path) : Component(x, y, w, h)
	{
		sprite = IMG_LoadTexture(sys.get_ren(), (IMAGES_PATH + image_path).c_str());
	}

	Sprite::~Sprite()
	{
		SDL_DestroyTexture(texture);
		SDL_DestroyTexture(sprite);
	}

	Sprite *Sprite::getInstance(int x, int y, int w, int h, std::string image_path)
	{
		return new Sprite(x, y, w, h, image_path);
	}
	void Sprite::moveUp()
	{
		setX(SPEED);
	}

	void Sprite::moveDown()
	{
		int value = -1 * SPEED;
		setX(value);
	}

	void Sprite::moveLeft()
	{
		int value = -1 * SPEED;
		setY(value);
	}

	void Sprite::moveRight()
	{
		setY(SPEED);
	}

	void Sprite::perform(SDL_Event event)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			moveUp();
			break;
		case SDLK_LEFT:
			moveDown();
			break;
		case SDLK_UP:
			moveLeft();
			break;
		case SDLK_DOWN:
			moveRight();
			break;
		}
	}

	void Sprite::draw() const
	{

		SDL_RenderCopy(sys.get_ren(), sprite, NULL, &getRect());

		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}
}