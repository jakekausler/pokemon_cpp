#pragma once
#include <sdl.h>
#include "BlendType.h"
#include <string>

class Sprite
{
private:
	double mAngle = 0;
	SDL_Texture *mTexture = NULL;
	SDL_BlendMode mBlendType = SDL_BLENDMODE_NONE;
	int mBushDepth = 0; // TODO: Lower Separate Opacity
	SDL_Color *mColor = NULL;
	bool mMirror = false; //TODO: Mirroring
	int mOpacity = 255;
	int mOX = 0; //TODO: Get Initial X
	int mOY = 0; //TODO: Get Initial Y
	SDL_Rect *mSrcRect = NULL; // Subtexture, or null for whole thing
	int mTone = 0;
	SDL_Rect *mViewport = NULL; // Where to render
	bool mVisible = true;
	int mX = 0;
	int mY = 0;
	int mZ = 0;
	double mWidth = 0;
	double mHeight = 0;
	double mZoomX = 1.0; //TODO: Work with zooming
	double mZoomY = 1.0; //TODO: Work with zooming
	SDL_Color *mColorKey = NULL;
	SDL_Renderer *mRenderer = NULL;

public:
	Sprite(SDL_Renderer *renderer, SDL_Rect *viewport = NULL);
	~Sprite();

	void LoadTexture(const std::string path, SDL_Color *colorKey = NULL);

	void Free();

	void Flash(const SDL_Color color, const int duration); //TODO: Implement Flash

	void Update();

	void Render();

	friend bool operator== (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator!= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator< (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator<= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator> (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator>= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
};

