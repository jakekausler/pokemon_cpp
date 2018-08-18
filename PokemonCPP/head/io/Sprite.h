#pragma once
#include <sdl.h>
#include "BlendType.h"
#include <string>

class Sprite
{
private:
	double mAngle = 0;
	SDL_Texture *mTexture = NULL;
	SDL_BlendMode mBlendType = SDL_BLENDMODE_BLEND;
	int mBushDepth = 0; // TODO: Lower Separate Opacity
	SDL_Color mColor{0xFF, 0xFF, 0xFF};
	bool mMirror = false; //TODO: Mirroring
	int mOpacity = 255;
	int mOX = 0; //TODO: Get Initial X
	int mOY = 0; //TODO: Get Initial Y
	SDL_Rect mSrcRect; // Subtexture, or null for whole thing
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

	int mRowHeight = 0;
	int mColumnWidth = 0;
	int mStartRow = 0;
	int mEndRow = 0;
	int mStartColumn = 0;
	int mEndColumn = 0;
	int mNumAnimations = 1;

	int mRow = 0;
	int mColumn = 0;

	int mFrame = 0;
	int mRate = 1;
	int currAnimation = 1;

	SDL_Color *mFlashColor = NULL;
	bool mFlashing = false;
	int mFlashInterval = 0;
	bool mFlashOn = false;

public:
	Sprite(SDL_Renderer *renderer, SDL_Rect *viewport = NULL);
	~Sprite();

	void Animate(int rate, int rowHeight, int columnWidth, int startRow = 0, int startColumn = 0, int numAnimations = 1);

	void Rotate(double amount);
	void RotateTo(double angle);

	void ChangeBlendType(SDL_BlendMode blendType);

	void ChangeColor(SDL_Color color);
	void RemoveColor();

	void IncreaseRed(int amount);
	void IncreaseGreen(int amount);
	void IncreaseBlue(int amount);

	void ChangeOpacity(int opacity);
	void IncreaseOpacity(int amount);

	void Translate(int dx, int dy);
	void MoveTo(int x, int y);

	void ZoomTo(double zx, double zy);

	void ToggleVisible();

	void BringFoward(int amount=1);
	void BringBack(int amount = 1);

	void ToggleMirror();

	void SetBushDepth(int bushDepth);

	void ChangeViewport(SDL_Rect *viewport);

	void ChangeSourceRect(SDL_Rect srcRect);

	void LoadTexture(const std::string path, SDL_Color *colorKey = NULL);

	void Free();

	void Flash(SDL_Color *color, const int duration);
	void FlashOff();

	void Update();

	void Render();

	void MoveAnimation();

	void DoEffects();

	friend bool operator== (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator!= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator< (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator<= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator> (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
	friend bool operator>= (const Sprite &s1, const Sprite &s2); //TODO: Implement comparison
};

