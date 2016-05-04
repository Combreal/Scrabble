#pragma once
#include "stdafx.h"

class CSprite
{
public:
	CSprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, char passed_letter, int passed_points);
	~CSprite(void);
	void Draw();
	void DrawSteady();
	void SetX(int X);
	void SetY(int Y);
	void SetPosition(int X, int Y);
	int GetX();
	int GetY();
	char GetLetter();
	int GetPoints();
	int GetWidth();
	int GetHeight();
	void SetWidth(int W);
	void SetHeight(int H);
	void SetOrigin(int X, int Y);
	void ImageDirection(int Pillar, int Line);
	void ScoreCrop(int Pillar);
	void TilesNbCrop(int Pillar);
private:
	int Origin_X;
	int Origin_Y;
	int X_pos;
	int Y_pos;
	int points;
	char letter;
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Renderer* renderer;
	int img_width;
	int img_height;
};

