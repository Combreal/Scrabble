#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Deck.h"

class CTheBot
{
public:
	CTheBot(CSDL_Setup* passed_SDL_Setup, CSprite* passed_tiles[100], CDeck* passed_Deck[15][15]);
	~CTheBot(void);
	void Play();
private:
	CSDL_Setup* csdl_setup;
	CSprite* tiles[100];
	CDeck* Deck[15][15];
};

