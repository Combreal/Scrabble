#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include "Sprite.h"

class CDeck
{
public:
	CDeck(int passed_x, int passed_y, int passed_caseNumber, bool passed_occupied, int passed_caseCoefficient, char passed_letter, int passed_letterCoefficient, bool passed_couldbeReset, int passed_tileId);
	~CDeck(void);
	int GetX() {return x;}
	int GetY() {return y;}
	int GetCaseNumber() {return caseNumber;}
	int GetCaseCoefficient() {return caseCoefficient;}
	bool GetOccupied() {return occupied;}
	char GetLetter() {return letter;}
	int GetLetterCoefficient() {return letterCoefficient;}
	bool GetCouldBeReset() {return couldbeReset;}
	int GetTileId() {return tileId;}
	void SetCaseCoefficient(int passed_CaseCoefficient);
	void SetOccupied(bool passed_Occupied);
	void SetLetter(char passed_Letter);
	void SetLetterCoefficient(int passed_Coefficient);
	void SetCouldBeReset(bool passed_CouldBeReset);
	void SetTileId(int passed_TileId);
private:
	bool occupied, couldbeReset;
	char letter;
	int x, y, caseNumber, caseCoefficient, letterCoefficient, tileId;
};

