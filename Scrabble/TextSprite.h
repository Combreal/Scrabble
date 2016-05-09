#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"

class CTextSprite
{
public:
	CTextSprite(CSDL_Setup* passed_SDL_Setup, SDL_Renderer* passed_renderer, std::string passed_FilePath, std::string passed_Sentence, int passed_PoliceSize, Uint8 passed_r, Uint8 passed_g, Uint8 passed_b, Uint8 passed_a, int x, int y, int w, int h);
	~CTextSprite(void);
	bool loadFromRenderedText(std::string textureText);
	void DrawText();
	void SetX(int X);
	void SetY(int Y);
	void SetPosition(int X, int Y);
	bool SetFontSize(int fontSize);
	bool SetFontColor(Uint8 passed_r, Uint8 passed_g, Uint8 passed_b, Uint8 passed_a);
	void SetWidth(int W);
	void SetHeight(int H);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	int GetFontSize();
private:
	CSDL_Setup* csdl_setup;
	SDL_Renderer* renderer;
	SDL_Surface* text;
	SDL_Surface* textSurface;
	SDL_Texture* Message;
	SDL_Color textColor;
	std::string filePath;
	std::string sentence;
	TTF_Font *font;
	SDL_Rect position;
	bool renderText;
	int policeSize;
	int X_pos;
	int Y_pos;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};

