#include "Deck.h"

CDeck::CDeck(int passed_x, int passed_y, int passed_caseNumber, bool passed_occupied, int passed_casseCoefficient, char passed_letter, int passed_letterCoefficient)
{
	occupied = passed_occupied;
	letter = '\0';
	x=passed_x;
	y=passed_y;
	caseNumber=passed_caseNumber;
	caseCoefficient=passed_casseCoefficient;
	letterCoefficient=passed_letterCoefficient;
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
	letter=passed_Coefficient;
}
