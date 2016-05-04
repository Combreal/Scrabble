#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class CScore
{
public:
	CScore(CSDL_Setup* passed_csdl_setup);
	~CScore(void);
	int GetScore() {return theScore;}
	int GetBotScore() {return theBotScore;}
	void SetScore(int passed_score);
	void SetBotScore(int passed_botscore);
private:
	int theScore, score, decade_score, hundred_score;
	int theBotScore, Botscore, Botdecade_score, Bothundred_score;
	float dScore, comp, compa;
	float dBotScore, Botcomp, Botcompa;
	CSDL_Setup* csdl_setup;
	CSprite* Score;
	CSprite* BotScore;
	CSprite* Decade_score;
	CSprite* BotDecade_score;
	CSprite* Hundred_score;
	CSprite* BotHundred_score;
};

