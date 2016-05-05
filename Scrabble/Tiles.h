#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Deck.h"

class CTiles
{
public:
	CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup);
	~CTiles(void);
	void DrawBack();
	void GetHand();
	void PictClicked();
	int GetTilesNb() {return (int)theTilesnb;}
	bool GetSwapOn() {return swapon;}
	void SetTilesNb(int passed_tilesnb);
	void SetSwapOn(bool passed_SwapOn);
private:
	CSprite* tiles[100];
	CSprite* TilesNb;
	CSprite* Decade_TilesNb;
	CSDL_Setup* csdl_setup;
	CDeck* Deck[15][15];
	std::vector<int> TilesNumber;
	std::vector<int> Hand;
	void WichPict();
	void SetTileOnDeck(int setTx, int setTy, int tileNumber);
	void InitSpecCase();
	int* MouseX;
    int* MouseY;
	bool *swapLoop;
	char letter;
	size_t timeCheck;
	float theTilesnb, tilesnb, decade_tilesnb;
	int deckRow, deckPillar;
	int CxReloc, CyReloc, CxRelocb, CyRelocb, wichpict;
	int tmpTileX, tmpTileY;
	bool Follow, Lockwichpict, isClicked, swapon, putBackTile, IsOnDeck, handLock, noTileMoved;
	float dTilesnb;
	float comp;
};

