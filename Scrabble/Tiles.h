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
	int GetPlayerScore() {return playerScoreb;}
	int GetBotScore() {return botScoreb;}
	std::string GetWord() {return word;}
	void SetSwapOn(bool passed_SwapOn);
	void SetPlay(bool passed_play);
	void SetFirstTile(bool passed_FirstTile);
	void SetFirstTileAfteraTurn(bool passed_FirstTileAfteraTurn);
	void SetMachineScore(std::string passed_score);
	void SetTilesNumber(std::string passed_tilesNumber);
	void SetDictionaryPath(std::string passed_dictionaryPath);
	bool CheckDeadEnd();
private:
	CSprite* tiles[100];
	CTextSprite* PlayerScore;
	CTextSprite* MachineScore;
	CTextSprite* TileNumber;
	CSDL_Setup* csdl_setup;
	CDeck* Deck[15][15];
	std::map<int,bool>TilesNumber;
	std::vector<int> Hand;
	std::vector<int> Swap;
	std::vector<int> OnDeck;
	std::vector<int> OnDeckForBot;
	std::vector<int> ResetPillar;
	std::vector<int> ResetRow;
	std::vector<int> OnDeckForeva;
	std::vector<int> RandomizedOnDeckForeva;
	std::vector<int> BotHand;
	std::vector<int> BotHandTransf;
	std::vector<int> BotHandb;
	std::vector<int> BotHandc;
	std::vector<int> keepBotHand;
	std::vector<int>::iterator it;
	std::map<int,bool>::iterator itt;
	std::vector<char> BotHandChars;
	std::vector<std::string> TransitHand;
	std::vector<std::string> WordsFound;
	bool IsInTheVector(std::string passed_word, std::vector<std::string>& passed_vector);
	bool IsInTheVectorb(int passed_id, std::vector<int>& passed_vector);
	void FirstWordIsFromBot();
	void findwords(std::vector<std::string>& passed_TransitHand, std::vector<std::string>& passed_WordsFound, char passed_letter);
	void findword(std::vector<std::string>& passed_TransitHand, std::vector<std::string>& passed_WordsFound);
	int GetAvailableTile(std::map<int,bool>& passed_map);
	void GetDeckPillarAndRow(int passed_witchPict);
	bool GetBotUpSideMax();
	bool GetBotDownSideMax();
	bool GetBotLeftSideMax();
	bool GetBotRightSideMax();
	void InitBotHand(char passed_letter);
	void WichPict();
	void SetTileOnDeck();
	void InitSpecCase();
	void PlaceOnDeck(int pillar, int row);
	void PackedOnDeck();
	void PackedOnDeckSecond();
	void RetrievedWord();
	void SetNewScore();
	void SetNewBotScore();
	bool IsAWord();
	void LopOffPT();
	void botDownSideNormal();
	void botRightSideNormal();
	void forceBotHandRandomization();
	int rand_a_b(int a, int b);
	int* MouseX;
    int* MouseY;
	bool *swapLoop;
	char letter;
	size_t timeCheck;
	size_t found;
	size_t botFound;
	std::string word;
	std::string wordCopy;
	std::string botWordCopy;
	std::string playerScorea;
	std::string machineScorea;
	std::string tileNumbera;
	std::string testChain;
	std::string dictionaryPath;
	int jockerPos[2];
	int botJockerPos[2];
	int deckRow, deckPillar, horizontalFirst, horizontalLast, verticalFirst, verticalLast, botPillarSearch, botRowSearch, deadEndCounter;
	int CxReloc, CyReloc, CxRelocb, CyRelocb, wichpict, tmpPillar, tmpRow, stayInPillarOrRow, tmpFirstPillar, tmpFirstRow, unusedTile;
	int tmpTileX, tmpTileY, tmpSwapedTileNb, tmpSwap, tileNumberb, playerScoreb, machineScoreb, newScore, TNLopOffCounter, randTileNb;
	int tmpLeftPillar, tmpLeftRow, tmpRightPillar, tmpRightRow, tmpUpPillar, tmpUpRow, tmpDownPillar, tmpDownRow, noWordCounter;
	int botDownSideMax, botRightSideMax, newBotScore, botScoreb, horizontalBotFirst, horizontalBotLast, verticalBotFirst, verticalBotLast;
	int botUpSideMax, botLeftSideMax, availableTile, randomKey, noWordCounterb, roll;
	bool jocker[2];
	bool botJocker[2];
	bool Follow, Lockwichpict, isClicked, swapon, putBackTile, IsOnDeck, handLock, playAlreadyClicked, quitCheckWordListLoop;
	bool isPackedOnDeck, firsttile, firsttileafteraturn, secondtile, secondtileafteraturn, initBotHand, BotchosenDirection, quitCDLoop;
	bool noTileMoved, play, dreplswap, initGetHand, initPictClicked, lockSeekWord, isAword, sameWord, initTNLopOff, initBTNLopOff;
	bool GetBotRightSide, GetBotDownSide, noWord, botPass, firstWordIsFromBot, initRetrieveWord, ctrlInit, randTileNbFound, deadEnd;
	bool isInTheVector, isInTheVectorb, randomizeBotHand, GetBotLeftSide, GetBotUpSide;
};

