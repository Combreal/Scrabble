#include "Score.h"
using namespace std;

CScore::CScore(CSDL_Setup* passed_csdl_setup)
{
	csdl_setup = passed_csdl_setup;
	theScore, score, decade_score, hundred_score = 0;
	theBotScore, Botscore, Botdecade_score, Bothundred_score = 0;
	dScore = 0;
	dBotScore = 0;
	Score = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 775, 12, 15, 25, 0, 0, 0, 0);
	Decade_score = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 755, 12, 15, 25, 0, 0, 0, 0);
	Hundred_score = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 735, 12, 15, 25, 0, 0, 0, 0);
	BotScore = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 775, 44, 15, 25, 0, 0, 0, 0);
	BotDecade_score = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 755, 44, 15, 25, 0, 0, 0, 0);
	BotHundred_score = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_18.png", 735, 44, 15, 25, 0, 0, 0, 0);
}


CScore::~CScore(void)
{
	delete Score;
	delete BotScore;
	delete Decade_score;
	delete BotDecade_score;
	delete Hundred_score;
	delete BotHundred_score;
}

void CScore::SetScore(int passed_score)
{
	dScore = (float)passed_score;
	theScore = dScore;
	score = 0;
	decade_score = 0;
	hundred_score = 0;
	comp = 0;
	compa = 0;
	if(dScore>=100)
	{
		comp = dScore/100;
		hundred_score = floorf(comp);
		compa = dScore - (hundred_score*100);
		compa = compa/10;
		decade_score = floor(compa);
		score = compa*10 - decade_score*10;
		Hundred_score->ScoreCrop((int)hundred_score);
		Decade_score->ScoreCrop((int)decade_score);
		Score->ScoreCrop((int)score);
		Hundred_score->Draw();
		Decade_score->Draw();
		Score->Draw();
	}
	else if(dScore>=10)
	{
		comp = dScore/10;
		decade_score = floorf(comp);
		score = dScore - decade_score*10;
		Decade_score->ScoreCrop((int)decade_score);
		Score->ScoreCrop((int)score);
		Decade_score->Draw();
		Score->Draw();
	}
	else if(dScore<10)
	{
		score = dScore;
		Score->ScoreCrop((int)score);
		Score->Draw();
	}
}

void CScore::SetBotScore(int passed_botscore)
{
	dBotScore = (float)passed_botscore;
	theBotScore = dBotScore;
	Botscore = 0;
	Botdecade_score = 0;
	Bothundred_score = 0;
	Botcomp = 0;
	Botcompa = 0;
	if(dBotScore>=100)
	{
		Botcomp = dBotScore/100;
		Bothundred_score = floor(Botcomp);
		Botcompa = dBotScore - (Bothundred_score*100);
		Botcompa = Botcompa/10;
		Botdecade_score = floor(Botcompa);
		Botscore = Botcompa*10 - Botdecade_score*10;
		BotHundred_score->ScoreCrop((int)Bothundred_score);
		BotDecade_score->ScoreCrop((int)Botdecade_score);
		BotScore->ScoreCrop((int)Botscore);
		BotHundred_score->Draw();
		BotDecade_score->Draw();
		BotScore->Draw();
	}
	else if(dScore>=10)
	{
		Botcomp = dBotScore/10;
		Botdecade_score = floor(Botcomp);
		Botscore = dBotScore - Botdecade_score*10;
		BotDecade_score->ScoreCrop((int)Botdecade_score);
		BotScore->ScoreCrop((int)Botscore);
		BotDecade_score->Draw();
		BotScore->Draw();
	}
	else if(dScore<10)
	{
		Botscore = dBotScore;
		BotScore->ScoreCrop((int)Botscore);
		BotScore->Draw();
	}
}
