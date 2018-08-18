#include "Sprite.h"
#include <stdio.h>
#include <SDL_image.h>
#include <stdexcept>
#include <string>

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

void Sprite::Animate(int rate, int rowHeight, int columnWidth, int startRow, int startColumn, int numAnimations) {
	mRate = rate;
	mRowHeight = rowHeight;
	mColumnWidth = columnWidth;

	mStartRow = mRow = startRow;
	mStartColumn = mColumn = startColumn;

	mNumAnimations = numAnimations;

	int cols = int(mWidth / mColumnWidth);
	int endCell = mNumAnimations + mStartColumn + cols * mStartRow - 1;
	mEndColumn = endCell % cols;
	mEndRow = endCell / cols;

	mSrcRect = SDL_Rect{ mStartColumn * mColumnWidth, mStartRow * mRowHeight, mColumnWidth, mRowHeight };
}

void Sprite::Rotate(double amount)
{
	mAngle += amount;
}

void Sprite::RotateTo(double angle)
{
	mAngle = angle;
}

void Sprite::ChangeBlendType(SDL_BlendMode blendType)
{
	mBlendType = blendType;
}

void Sprite::ChangeColor(SDL_Color color)
{
	mColor = color;
}

void Sprite::RemoveColor() {
	mColor = { 0xFF, 0xFF, 0xFF };
}

void Sprite::IncreaseRed(int amount)
{
		mColor.r = (mColor.r + amount)%255;
}

void Sprite::IncreaseGreen(int amount)
{
	mColor.g = (mColor.g + amount) % 255;
}

void Sprite::IncreaseBlue(int amount)
{
		mColor.b = (mColor.b + amount) % 255;
}

void Sprite::ChangeOpacity(int opacity)
{
	mOpacity = opacity % 255;
}

void Sprite::IncreaseOpacity(int amount)
{
	mOpacity = (amount + mOpacity) % 255;
}

void Sprite::Translate(int dx, int dy)
{
	mX += dx;
	mY += dy;
}

void Sprite::MoveTo(int x, int y)
{
	mX = x;
	mY = y;
}

void Sprite::ZoomTo(double zx, double zy)
{
	mZoomX = zx;
	mZoomY = zy;
}

void Sprite::ToggleVisible()
{
	mVisible = !mVisible;
}

void Sprite::BringFoward(int amount)
{
	mZ += amount;
}

void Sprite::BringBack(int amount)
{
	mZ -= amount;
}

void Sprite::ToggleMirror()
{
	mMirror = !mMirror;
}

void Sprite::SetBushDepth(int bushDepth)
{
	mBushDepth = bushDepth;
}

void Sprite::ChangeViewport(SDL_Rect * viewport)
{
	mViewport = viewport;
}

void Sprite::ChangeSourceRect(SDL_Rect srcRect)
{
	mSrcRect = srcRect;
}

void Sprite::Free()
{
	mAngle = 0;
	mTexture = NULL;
	mBlendType = SDL_BLENDMODE_BLEND;
	mBushDepth = 0;
	mColor = { 0xFF, 0xFF, 0xFF };
	mMirror = false;
	mOpacity = 255;
	mOX = 0;
	mOY = 0;
	mSrcRect = SDL_Rect{ 0, 0, 0, 0 };
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
}

// Duration in frames
void Sprite::Flash(SDL_Color *color, const int interval=1)
{
	mFlashColor = color;
	mFlashInterval = interval;
	mFlashing = true;
}

void Sprite::FlashOff() {
	mFlashColor = NULL;
	mFlashInterval = 0;
	mFlashing = false;
	mFlashOn = false;
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

	mSrcRect = SDL_Rect{ 0, 0, static_cast<int>(mWidth), static_cast<int>(mHeight) };

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
	SDL_SetTextureColorMod(mTexture, mColor.r, mColor.g, mColor.b);

	DoEffects();
	MoveAnimation();

	mFrame++;

	SDL_RenderCopyEx(mRenderer, mTexture, &mSrcRect, mViewport, mAngle, NULL, mMirror ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Sprite::MoveAnimation() {
	if (mFrame % mRate == 0) {
		mColumn++;
		if (mColumn > mEndColumn) {
			mColumn = mStartColumn;
			mRow++;
			if (mRow > mEndRow) {
				mColumn = mStartColumn;
				mRow = mStartRow;
			}
		}

		mSrcRect.x = mColumnWidth * mColumn;
		mSrcRect.y = mRowHeight * mRow;
		mSrcRect.w = mColumnWidth;
		mSrcRect.h = mRowHeight;
	}
}

void Sprite::DoEffects() {
	if (mFlashing) {
		if (mFrame % mFlashInterval == 0) {
			if (mFlashOn) {
				RemoveColor();
				mFlashOn = false;
			}
			else {
				mColor = *mFlashColor;
				mFlashOn = true;
			}
		}
	}
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
