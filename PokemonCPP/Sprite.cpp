#include "Sprite.h"
#include <string>
#include <stdio.h>
#include <SDL_image.h>
#include <stdexcept>

Sprite::Sprite(SDL_Renderer *renderer, SDL_Rect * viewport)
{
	mViewport = viewport;
	mRenderer = renderer;
}

Sprite::~Sprite()
{
	Free();
	mRenderer = NULL;
}

void Sprite::Free()
{
	mAngle = 0;
	mTexture = NULL;
	mBlendType = SDL_BLENDMODE_NONE;
	mBushDepth = 0;
	mColor = NULL;
	mMirror = false;
	mOpacity = 255;
	mOX = 0;
	mOY = 0;
	mSrcRect = NULL;
	mTone = 0;
	mViewport = NULL;
	mVisible = true;
	mX = 0;
	mY = 0;
	mZ = 0;
	mWidth = 0;
	mHeight = 0;
	mZoomX = 1.0;
	mZoomY = 1.0;
	mColorKey = NULL;
}

void Sprite::Flash(const SDL_Color color, const int duration)
{
	//TODO
}

void Sprite::LoadTexture(const std::string path, SDL_Color *colorKey) {
	Free();

	SDL_Texture *newTexture = NULL;

	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface) {
		printf("Error loading file from %s: %s", path.c_str(), IMG_GetError());
		throw std::runtime_error("Error loading file!");
	}

	mColorKey = colorKey;
	if (colorKey) {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, colorKey->r, colorKey->g, colorKey->b));
	}

	newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
	if (!newTexture) {
		printf("Error loading texture from %s: %s", path.c_str(), SDL_GetError());
		throw std::runtime_error("Error loading texture!");
	}

	mWidth = loadedSurface->w;
	mHeight= loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	mTexture = newTexture;
}

void Sprite::Update()
{
	Render();
}

void Sprite::Render()
{
	SDL_SetTextureAlphaMod(mTexture, mOpacity);
	SDL_SetTextureBlendMode(mTexture, mBlendType);
	SDL_SetTextureColorMod(mTexture, mColor->r, mColor->g, mColor->b);

	SDL_RenderCopyEx(mRenderer, mTexture, mSrcRect, mViewport, mAngle, NULL, mMirror ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

bool operator==(const Sprite & s1, const Sprite & s2)
{
	return s1.mZ == s2.mZ;
}

bool operator!=(const Sprite & s1, const Sprite & s2)
{
	return !(s1==s2);
}

bool operator<(const Sprite & s1, const Sprite & s2)
{
	return s1.mZ < s2.mZ;
}

bool operator<=(const Sprite & s1, const Sprite & s2)
{
	return s1.mZ <= s2.mZ;
}

bool operator>(const Sprite & s1, const Sprite & s2)
{
	return s1.mZ > s2.mZ;
}

bool operator>=(const Sprite & s1, const Sprite & s2)
{
	return s1.mZ >= s2.mZ;
}
