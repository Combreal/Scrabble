#include "Deck.h"

CDeck::CDeck(int passed_x, int passed_y, int passed_caseNumber, bool passed_occupied, int passed_caseCoefficient, char passed_letter, int passed_letterCoefficient, bool passed_couldbeReset,  int passed_tileId)
{
	occupied = passed_occupied;
	couldbeReset = passed_couldbeReset;
	letter = '\0';
	x=passed_x;
	y=passed_y;
	caseNumber=passed_caseNumber;
	caseCoefficient=passed_caseCoefficient;
	letterCoefficient=passed_letterCoefficient;
	tileId = passed_tileId;
}

CDeck::~CDeck(void)
{

}

void CDeck::SetOccupied(bool passed_Occupied)
{
	occupied=passed_Occupied;
}

void CDeck::SetCaseCoefficient(int passed_CaseCoefficient)
{
	caseCoefficient=passed_CaseCoefficient;
}

void CDeck::SetLetter(char passed_Letter)
{
	letter=passed_Letter;
}

void CDeck::SetLetterCoefficient(int passed_Coefficient)
{
	letterCoefficient=passed_Coefficient;
}

void CDeck::SetCouldBeReset(bool passed_CouldBeReset)
{
	couldbeReset = passed_CouldBeReset;
}

void CDeck::SetTileId(int passed_TileId)
{
	tileId = passed_TileId;
}

