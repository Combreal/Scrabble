#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include "textSprite.h"
#include "Tiles.h"
#include "Dictionary.h"

class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHeight);
	~CMain(void);
	void GameLoop();
	int CheckSel();
	int CheckSwapSel();
private:
	void SelPoffLoff();
	void SelPoffLon();
	void DictionaryCheck();
	bool quit;
	bool quitSelLoop;
	bool SwapLoop;
	bool checkWordSl;
	bool checkCheckWordSl;
	bool onlyOne;
	bool victoryDrawn;
	bool initHand;
	bool blockSwap;
	int clickSel;
	int clickSwapSel;
	int MouseX, MouseY;
	int ScreenWidth;
	int ScreenHeight;
	int dictionaryresponce;
	int victoryCounter;
	CSDL_Setup* csdl_setup;
	CSprite* Deck;
	CSprite* Deck2;
	CSprite* Swap;
	CSprite* Cancel;
	CSprite* Pass;
	CSprite* Undo;
	CSprite* Play;
	CSprite* Swap2;
	CSprite* SwapWind2;
	CSprite* Cancel2;
	CSprite* Pass2;
	CSprite* Undo2;
	CSprite* Play2;
	CSprite* CheckWord;
	CSprite* CheckWord2;
	CSprite* Wid;
	CSprite* Wind;
	CSprite* pWon;
	CSprite* mWon;
	CSprite* execo;
	CTiles* Tiles;
	CDictionary* Dictionary;
};

