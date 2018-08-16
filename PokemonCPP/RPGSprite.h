#pragma once
#include "Sprite.h"
class RPGSprite :
	public Sprite
{
public:
	RPGSprite(SDL_Renderer *renderer, SDL_Rect *viewport = NULL); //TODO
	~RPGSprite();
};

