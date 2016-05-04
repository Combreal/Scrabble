#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"

class CDictionary
{
public:
	CDictionary(CSDL_Setup* passed_SDL_Setup, SDL_Renderer* passed_renderer, std::string passed_FilePath, std::string passed_Sentence, int passed_PoliceSize, Uint8 passed_r, Uint8 passed_g, Uint8 passed_b, Uint8 passed_a, int x, int y, int w, int h);
	~CDictionary(void);
	bool loadFromRenderedText(std::string textureText);
	void DrawText();
	bool DrawCursor();
	bool IsAWord();
	void DrawCurzor();
	void RetrieveWord();
	void cleanEditB();
private:
	CSDL_Setup* csdl_setup;
	SDL_Renderer* renderer;
	SDL_Surface* text;
	SDL_Surface* textSurface;
	SDL_Texture* Message;
	SDL_Color textColor;
	std::string filePath;
	std::string sentence;
	std::string testChain;
	std::string lopSentence;
	TTF_Font *font;
	SDL_Rect position;
	bool Cursor;
	bool renderText;
	bool keyReleased;
	bool keyReleasedd;
	bool lastbool;
	bool cleanOnce;
	bool isAword;
	bool sameWord;
	int MouseX, MouseY;
	int time;
	int counter;
	int counta;
	int counterb;
	int policeSize;
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
	int Origin_X;
	int Origin_Y;
	int timerb;
};

