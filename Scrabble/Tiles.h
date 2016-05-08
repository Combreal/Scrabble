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
	void Play();
	int GetTilesNb() {return (int)theTilesnb;}
	bool GetSwapOn() {return swapon;}
	bool GetPlay() {return play;}
	bool GetFirstTile() {return firsttile;}
	bool GetPlayClicked() {return playAlreadyClicked;}
	std::string GetWord() {return word;}
	void TilesCounter();
	void SetSwapOn(bool passed_SwapOn);
	void SetPlay(bool passed_play);
	void SetFirstTile(bool passed_FirstTile);
	void SetFirstTileAfteraTurn(bool passed_FirstTileAfteraTurn);
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
	std::vector<int> OnDeck;
	std::vector<int> OnDeckForeva;
	void WichPict();
	void SetTileOnDeck();
	void InitSpecCase();
	void PlaceOnDeck(int pillar, int row);
	void PackedOnDeck();
	void PackedOnDeckSecond();
	void RetrievedWord();
	void SetNewScore();
	bool IsAWord();
	int* MouseX;
    int* MouseY;
	bool *swapLoop;
	char letter;
	size_t timeCheck;
	std::string word;
	std::string testChain;
	float theTilesnb, tilesnb, decade_tilesnb;
	float dTilesnb;
	float comp;
	int deckRow, deckPillar, tileCounter, horizontalFirst, horizontalLast, verticalFirst, verticalLast;
	int CxReloc, CyReloc, CxRelocb, CyRelocb, wichpict, tmpPillar, tmpRow, stayInPillarOrRow, tmpFirstPillar, tmpFirstRow;
	int tmpTileX, tmpTileY, tmpSwapedTileNb, tmpSwap, playerScore, machineScore, newScore;
	int tmpLeftPillar, tmpLeftRow, tmpRightPillar, tmpRightRow, tmpUpPillar, tmpUpRow, tmpDownPillar, tmpDownRow;
	bool Follow, Lockwichpict, isClicked, swapon, putBackTile, IsOnDeck, handLock, playAlreadyClicked;
	bool isPackedOnDeck, firsttile, firsttileafteraturn, secondtile, secondtileafteraturn;
	bool noTileMoved, play, dreplswap, initGetHand, initPictClicked, lockSeekWord, isAword, sameWord;
};

