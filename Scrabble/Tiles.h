#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Deck.h"
#include "Score.h"

class CTiles
{
public:
	CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup);
	~CTiles(void);
	void DrawBack();
	void GetHand();
	void PictClicked();
	void Swapy();
	int GetTilesNb() {return (int)theTilesnb;}
	bool GetSwapOn() {return swapon;}
	bool GetPlay() {return play;}
	bool GetFirstTile() {return firsttile;}
	void TilesCounter();
	void SetSwapOn(bool passed_SwapOn);
	void SetPlay(bool passed_play);
	void SetFirstTile(bool passed_FirstTile);
private:
	CScore* Score;
	CSprite* tiles[100];
	CSprite* TilesNb;
	CSprite* Decade_TilesNb;
	CSDL_Setup* csdl_setup;
	CDeck* Deck[15][15];
	std::vector<int> TilesNumber;
	std::vector<int> TilesNumberb;
	std::vector<int> Hand;
	std::vector<int> Swap;
	std::vector<int>::iterator it;
	void WichPict();
	void SetTileOnDeck(int setTx, int setTy, int tileNumber);
	void InitSpecCase();
	int* MouseX;
    int* MouseY;
	bool *swapLoop;
	char letter;
	size_t timeCheck;
	float theTilesnb, tilesnb, decade_tilesnb;
	int deckRow, deckPillar, tileCounter;
	int CxReloc, CyReloc, CxRelocb, CyRelocb, wichpict;
	int tmpTileX, tmpTileY, tmpSwapedTileNb, tmpSwap, playerScore, machineScore;
	bool Follow, Lockwichpict, isClicked, swapon, putBackTile, IsOnDeck, handLock, noTileMoved, play, firsttile, dreplswap, initGetHand;
	float dTilesnb;
	float comp;
};

