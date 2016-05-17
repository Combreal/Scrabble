#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "TextSprite.h"
#include "Deck.h"

class CTiles
{
public:
	CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup);
	~CTiles(void);
	void DrawBack();
	void GetHand();
	void PictClicked();
	void Swapy();
	void AiPlay();
	void Play();
	void Undo();
	void CancelSwap();
	bool GetSwapOn() {return swapon;}
	bool GetPlay() {return play;}
	bool GetFirstTile() {return firsttile;}
	bool GetPlayClicked() {return playAlreadyClicked;}
	std::string GetWord() {return word;}
	void SetSwapOn(bool passed_SwapOn);
	void SetPlay(bool passed_play);
	void SetFirstTile(bool passed_FirstTile);
	void SetFirstTileAfteraTurn(bool passed_FirstTileAfteraTurn);
	void SetMachineScore(std::string passed_score);
	void SetTilesNumber(std::string passed_tilesNumber);
private:
	CSprite* tiles[100];
	CTextSprite* PlayerScore;
	CTextSprite* MachineScore;
	CTextSprite* TileNumber;
	CSDL_Setup* csdl_setup;
	CDeck* Deck[15][15];
	std::vector<int> TilesNumber;
	std::vector<int> TilesNumberb;
	std::vector<int> Hand;
	std::vector<int> BotHand;
	std::vector<int> Swap;
	std::vector<int> OnDeck;
	std::vector<int> ResetPillar;
	std::vector<int> ResetRow;
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
	size_t found;
	std::string word;
	std::string wordCopy;
	std::string playerScorea;
	std::string machineScorea;
	std::string tileNumbera;
	std::string testChain;
	int jockerPos[2];
	int deckRow, deckPillar, horizontalFirst, horizontalLast, verticalFirst, verticalLast;
	int CxReloc, CyReloc, CxRelocb, CyRelocb, wichpict, tmpPillar, tmpRow, stayInPillarOrRow, tmpFirstPillar, tmpFirstRow;
	int tmpTileX, tmpTileY, tmpSwapedTileNb, tmpSwap, tileNumberb, playerScoreb, machineScoreb, newScore, TNLopOffCounter;
	int tmpLeftPillar, tmpLeftRow, tmpRightPillar, tmpRightRow, tmpUpPillar, tmpUpRow, tmpDownPillar, tmpDownRow, onDeckSize;
	bool jocker[2];
	bool Follow, Lockwichpict, isClicked, swapon, putBackTile, IsOnDeck, handLock, playAlreadyClicked;
	bool isPackedOnDeck, firsttile, firsttileafteraturn, secondtile, secondtileafteraturn, initBotHand;
	bool noTileMoved, play, dreplswap, initGetHand, initPictClicked, lockSeekWord, isAword, sameWord, initTNLopOff;
};

