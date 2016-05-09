#include "Tiles.h"
using namespace std;

CTiles::CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup)
{
	csdl_setup = passed_SDL_Setup;
	srand(unsigned(time(0)));
	letter = '\0';
	horizontalFirst=0, horizontalLast=0, verticalFirst=0, verticalLast = 0;
	CxRelocb=0, CyRelocb=0;
	wichpict = 0;
	CxReloc=0, CyReloc=0;
	deckRow=0, deckPillar = 0;
	tmpTileX=0, tmpTileY = 0;
	tmpPillar=0, tmpRow = 0;
	tmpFirstPillar=0, tmpFirstRow = 0;
	tmpSwapedTileNb = 0;
	tmpSwap = 0;
	tileNumberb=93, playerScoreb=0, machineScoreb = 0;
	newScore = 0;
	playerScorea = "0";
	machineScorea = "0";
	tileNumbera = "93";
	tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
	noTileMoved = true;
	Follow=false, Lockwichpict=false, swapon=false;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;
	swapLoop = passed_SwapLoop;
	timeCheck = SDL_GetTicks();
	play = false;
	playAlreadyClicked = false;
	isPackedOnDeck = false;
	IsOnDeck = false;
	isClicked = false;
	putBackTile = false;
	handLock = false;
	lockSeekWord = true;
	firsttile = true;
	firsttileafteraturn = false;
	secondtile = false;
	secondtileafteraturn = false;
	dreplswap = true;
	initGetHand = true;
	initPictClicked = true;
	isAword = false;
	sameWord = false;
	PlayerScore = new CTextSprite(csdl_setup, csdl_setup->GetRenderer(), "data/font/LucidaSansRegular.ttf", playerScorea, 18, 0, 0, 0, 0, 755, 11, 15, 25);//735 for >99 744 for>9 755 for<10
	MachineScore = new CTextSprite(csdl_setup, csdl_setup->GetRenderer(), "data/font/LucidaSansRegular.ttf", machineScorea, 18, 0, 0, 0, 0, 755, 45, 15, 25);
	TileNumber = new CTextSprite(csdl_setup, csdl_setup->GetRenderer(), "data/font/LucidaSansRegular.ttf", tileNumbera, 14, 0, 0, 0, 0, 639, 94, 11, 15); //631 if tileCounter>9
	tiles[0] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/joker.png", 0, 0, 37, 37, '_', 0, 0, 0);
	tiles[1] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/joker.png", 0, 0, 37, 37, '_', 0, 0, 0);
	tiles[2] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[3] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[4] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[5] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[6] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[7] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[8] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[9] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[10] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 37, 37, 'a', 1, 0, 0);
	tiles[11] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/B.png", 0, 0, 37, 37, 'b', 3, 0, 0);
	tiles[12] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/B.png", 0, 0, 37, 37, 'b', 3, 0, 0);
	tiles[13] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/C.png", 0, 0, 37, 37, 'c', 3, 0, 0);
	tiles[14] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/C.png", 0, 0, 37, 37, 'c', 3, 0, 0);
	tiles[15] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 37, 37, 'd', 2, 0, 0);
	tiles[16] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 37, 37, 'd', 2, 0, 0);
	tiles[17] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 37, 37, 'd', 2, 0, 0);
	tiles[18] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 37, 37, 'd', 2, 0, 0);
	tiles[19] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[20] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[21] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[22] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[23] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[24] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[25] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[26] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[27] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[28] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[29] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[30] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 37, 37, 'e', 1, 0, 0);
	tiles[31] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/F.png", 0, 0, 37, 37, 'f', 4, 0, 0);
	tiles[32] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/F.png", 0, 0, 37, 37, 'f', 4, 0, 0);
	tiles[33] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 37, 37, 'g', 2, 0, 0);
	tiles[34] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 37, 37, 'g', 2, 0, 0);
	tiles[35] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 37, 37, 'g', 2, 0, 0);
	tiles[36] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/H.png", 0, 0, 37, 37, 'h', 4, 0, 0);
	tiles[37] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/H.png", 0, 0, 37, 37, 'h', 4, 0, 0);
	tiles[38] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[39] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[40] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[41] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[42] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[43] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[44] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[45] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[46] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 37, 37, 'i', 1, 0, 0);
	tiles[47] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/J.png", 0, 0, 37, 37, 'j', 8, 0, 0);
	tiles[48] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/K.png", 0, 0, 37, 37, 'k', 5, 0, 0);
	tiles[49] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 37, 37, 'l', 1, 0, 0);
	tiles[50] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 37, 37, 'l', 1, 0, 0);
	tiles[51] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 37, 37, 'l', 1, 0, 0);
	tiles[52] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 37, 37, 'l', 1, 0, 0);
	tiles[53] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/M.png", 0, 0, 37, 37, 'm', 3, 0, 0);
	tiles[54] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/M.png", 0, 0, 37, 37, 'm', 3, 0, 0);
	tiles[55] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[56] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[57] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[58] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[59] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[60] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 37, 37, 'n', 1, 0, 0);
	tiles[61] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[62] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[63] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[64] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[65] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[66] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[67] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[68] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 37, 37, 'o', 1, 0, 0);
	tiles[69] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/P.png", 0, 0, 37, 37, 'p', 3, 0, 0);
	tiles[70] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/P.png", 0, 0, 37, 37, 'p', 3, 0, 0);
	tiles[71] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Q.png", 0, 0, 37, 37, 'q', 10, 0, 0);
	tiles[72] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[73] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[74] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[75] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[76] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[77] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 37, 37, 'r', 1, 0, 0);
	tiles[78] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 37, 37, 's', 1, 0, 0);
	tiles[79] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 37, 37, 's', 1, 0, 0);
	tiles[80] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 37, 37, 's', 1, 0, 0);
	tiles[81] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 37, 37, 's', 1, 0, 0);
	tiles[82] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[83] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[84] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[85] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[86] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[87] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 37, 37, 't', 1, 0, 0);
	tiles[88] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 37, 37, 'u', 1, 0, 0);
	tiles[89] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 37, 37, 'u', 1, 0, 0);
	tiles[90] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 37, 37, 'u', 1, 0, 0);
	tiles[91] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 37, 37, 'u', 1, 0, 0);
	tiles[92] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/V.png", 0, 0, 37, 37, 'v', 4, 0, 0);
	tiles[93] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/V.png", 0, 0, 37, 37, 'v', 4, 0, 0);
	tiles[94] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/W.png", 0, 0, 37, 37, 'w', 4, 0, 0);
	tiles[95] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/W.png", 0, 0, 37, 37, 'w', 4, 0, 0);
	tiles[96] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/X.png", 0, 0, 37, 37, 'x', 8, 0, 0);
	tiles[97] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Y.png", 0, 0, 37, 37, 'y', 4, 0, 0);
	tiles[98] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Y.png", 0, 0, 37, 37, 'y', 4, 0, 0);
	tiles[99] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Z.png", 0, 0, 37, 37, 'z', 10, 0, 0);
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			Deck[i][j] = new CDeck(10+j*39, 9+i*39, i*15+j, false, 0, '\0', 0, false);
		}
	}
	InitSpecCase();
	for(int k=0; k<100;k++)
	{
		TilesNumber.push_back(k);
	}
	random_shuffle(TilesNumber.begin(), TilesNumber.end());
	GetHand();
}


CTiles::~CTiles(void)
{
	delete PlayerScore;
	delete MachineScore;
	delete TileNumber;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			delete Deck[i][j];
		}
	}
	for(int k=0; k<100; k++)
	{
		delete tiles[k];
	}
}

void CTiles::GetHand()
{
	Hand.clear();
	Swap.clear();
	for(int i=0; i<7;i++)
	{
		Hand.push_back(TilesNumber.at(i));
		tiles[Hand.at(i)]->SetPosition(642,134+39*i);
		tiles[Hand.at(i)]->SetisOndeck(false);
		tiles[Hand.at(i)]->SetisOnswap(false);
		for(int k=0;k<15;k++)
		{
			for(int l=0;l<15;l++)
			{
				if(Deck[k][l]->GetCouldBeReset())
				{
					Deck[k][l]->SetOccupied(false);
					Deck[k][l]->SetCouldBeReset(false);
				}
			}
		}
	}
}

void CTiles::Swapy()
{
	TilesNumberb = TilesNumber;
	TilesNumberb.erase(TilesNumberb.begin(), TilesNumberb.begin()+7);
	for(size_t e=0, size=Swap.size(); e<size; ++e) 
	{
		TilesNumberb.push_back(Swap.at(e));
	}
	random_shuffle(TilesNumberb.begin(), TilesNumberb.end());
	for(size_t h = 0, size = Swap.size(); h < size; ++h) 
	{  
		for(size_t f = 0, size = Hand.size(); f < size; ++f) 
		{  
			if(Swap[h]==Hand[f])
			{
				Hand[f]=TilesNumberb[f];
				tiles[Hand.at(f)]->SetPosition(642,134+39*f);
			}
		}
	}
	wichpict=9999;
}

void CTiles::Undo()
{
	if(playAlreadyClicked)
	{
		tmpPillar=0, tmpRow = 0;
		tmpFirstPillar=0, tmpFirstRow = 0;
		tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
		firsttile = false;
		secondtile = false;
		firsttileafteraturn = true;
		secondtileafteraturn = false;
	}
	else if(!playAlreadyClicked)
	{
		tmpPillar=0, tmpRow = 0;
		tmpFirstPillar=0, tmpFirstRow = 0;
		tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
		firsttile = true;
		secondtile = false;
		firsttileafteraturn = false;
		secondtileafteraturn = false;		
	}		
	for(size_t m = 0, size = ResetPillar.size(); m < size; ++m) 
	{
		for(size_t n = 0, size = ResetRow.size(); n < size; ++n) 
		{
			cout<<"ResetPillar.at(m) : "<<ResetPillar.at(m)<<endl;
			cout<<"ResetRow.at(n) : "<<ResetRow.at(n)<<endl;
			Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetter('-');
			Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetterCoefficient(0);
			Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetOccupied(false);
			Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetCouldBeReset(false);
		}
	}
	for(size_t h = 0, size = Hand.size(); h < size; ++h) 
	{  
		for(size_t i = 0, size = OnDeck.size(); i < size; ++i) 
		{
			if(Hand.at(h)==OnDeck.at(i))
			{
				tiles[Hand.at(h)]->SetPosition(642,134+39*h);
				tiles[Hand.at(h)]->SetisOndeck(false);
				tiles[Hand.at(h)]->SetisOnswap(false);
			}
		}
	}
	ResetPillar.clear();
	ResetRow.clear();
	OnDeck.clear();
}

void CTiles::Play()
{
	RetrievedWord();
	SetNewScore();
	playerScoreb = playerScoreb + newScore;
	if(isAword)
	{
		TilesNumber.erase(TilesNumber.begin(), TilesNumber.begin()+7);
		random_shuffle(TilesNumber.begin(), TilesNumber.end());
		for(size_t a = 0, size = OnDeck.size(); a < size; ++a) 
		{
			OnDeckForeva.push_back(OnDeck.at(a));
		}
		for(size_t h = 0, size = OnDeck.size(); h < size; ++h) 
		{  
			for(size_t f = 0, size = Hand.size(); f < size; ++f) 
			{  
				if(OnDeck[h]==Hand[f])
				{
					Hand[f]=TilesNumber[h];
					tiles[Hand.at(f)]->SetPosition(642,134+39*f);
				}
			}
		}
		tmpPillar=0, tmpRow = 0;
		tmpFirstPillar=0, tmpFirstRow = 0;
		tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
		firsttile = false;
		secondtile = false;
		firsttileafteraturn = true;
		secondtileafteraturn = false;
		playAlreadyClicked = true;
		tileNumberb = tileNumberb - OnDeck.size();
		OnDeck.clear();
		ResetPillar.clear();
		ResetRow.clear();
		Swap.clear();
	}
	if(!isAword)
	{
		for(int i=0; i<7;i++)
		{
			tiles[Hand.at(i)]->SetPosition(642,134+39*i);
			tiles[Hand.at(i)]->SetisOndeck(false);
			tiles[Hand.at(i)]->SetisOnswap(false);
		}
		for(size_t m = 0, size = ResetPillar.size(); m < size; ++m) 
		{
			for(size_t n = 0, size = ResetRow.size(); n < size; ++n) 
			{
				Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetter('-');
				Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetterCoefficient(0);
				Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetOccupied(false);
				Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetCouldBeReset(false);
			}
		}
		tmpPillar=0, tmpRow = 0;
		tmpFirstPillar=0, tmpFirstRow = 0;
		tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
		firsttile = true;
		secondtile = false;
		firsttileafteraturn = false;
		secondtileafteraturn = false;
		playAlreadyClicked = true;
		ResetPillar.clear();
		ResetRow.clear();
		OnDeck.clear();
		Swap.clear();
	}
}

void CTiles::CancelSwap()
{
	for(size_t h = 0, size = Hand.size(); h < size; ++h) 
	{  
		for(size_t i = 0, size = Swap.size(); i < size; ++i) 
		{
			if(Hand.at(h)==Swap.at(i))
			{
				tiles[Hand.at(h)]->SetPosition(642,134+39*h);
			}
		}
	}
	Swap.clear();
}

void CTiles::RetrievedWord()
{
	word = "";
	horizontalFirst=0, horizontalLast=0, verticalFirst=0, verticalLast = 0;
	if(tmpFirstPillar==tmpPillar)
	{//horizontal
		for(int i=tmpRow;i<15;i++)
		{
			if(!Deck[tmpPillar][i]->GetOccupied()&&lockSeekWord)
			{
				horizontalLast = i-1;
				lockSeekWord = false;
			}
		}
		for(int j=tmpRow;j>0;j--)
		{
			if(!Deck[tmpPillar][j]->GetOccupied()&&!lockSeekWord)
			{
				horizontalFirst = j+1;
				lockSeekWord = true;
			}
		}
		for(int k=horizontalFirst; k<=horizontalLast; k++)
		{
			word.push_back(Deck[tmpPillar][k]->GetLetter());
		}
	}
	else if(tmpFirstRow==tmpRow)
	{//vertical
		for(int l=tmpPillar;l<15;l++)
		{
			if(!Deck[l][tmpRow]->GetOccupied()&&lockSeekWord)
			{
				verticalLast = l-1;
				lockSeekWord = false;
			}
		}
		for(int m=tmpPillar;m>0;m--)
		{
			if(!Deck[m][tmpRow]->GetOccupied()&&!lockSeekWord)
			{
				verticalFirst = m+1;
				lockSeekWord = true;
			}
		}
		for(int n=verticalFirst; n<=verticalLast; n++)
		{
			word.push_back(Deck[n][tmpRow]->GetLetter());
		}
	}
	cout<<"The word : "<<word.c_str()<<endl;
}

void CTiles::SetNewScore()
{
	newScore = 0;
	if(IsAWord())
	{
		if(horizontalFirst>0&&horizontalLast>0)
		{
			for(int i=horizontalFirst; i<=horizontalLast; i++)
			{
				newScore =  newScore + Deck[tmpPillar][i]->GetLetterCoefficient();
			}
			for(int j=horizontalFirst; j<=horizontalLast; j++)
			{
				switch(Deck[tmpPillar][j]->GetCaseCoefficient())
				{
				case 0:
					break;
				case 1:
					newScore =  newScore - Deck[tmpPillar][j]->GetLetterCoefficient();
					newScore =  newScore + (Deck[tmpPillar][j]->GetLetterCoefficient() * 2);
					break;
				case 2:
					newScore =  newScore - Deck[tmpPillar][j]->GetLetterCoefficient();
					newScore =  newScore + (Deck[tmpPillar][j]->GetLetterCoefficient() * 3);
					break;
				case 3:
					newScore = newScore*2;
					break;
				case 4:
					newScore = newScore*3;
					break;
				default:
					break;
				}
			}
		}
		else if(verticalFirst>0&&verticalLast>0)
		{
			for(int k=verticalFirst; k<=verticalLast; k++)
			{
				//Deck[j][tmpRow]->GetCaseCoefficient()
				newScore =  newScore + Deck[k][tmpRow]->GetLetterCoefficient();
			}
			for(int l=verticalFirst; l<=verticalLast; l++)
			{
				switch(Deck[l][tmpRow]->GetCaseCoefficient())
				{
				case 0:
					break;
				case 1:
					newScore =  newScore - Deck[l][tmpRow]->GetLetterCoefficient();
					newScore =  newScore + (Deck[l][tmpRow]->GetLetterCoefficient() * 2);
					break;
				case 2:
					newScore =  newScore - Deck[l][tmpRow]->GetLetterCoefficient();
					newScore =  newScore + (Deck[l][tmpRow]->GetLetterCoefficient() * 3);
					break;
				case 3:
					newScore = newScore*2;
					break;
				case 4:
					newScore = newScore*3;
					break;
				default:
					break;
				}
			}
		}
	}
}

bool CTiles::IsAWord()
{
	isAword = false;
	ifstream file("data/dictionary/dEn.txt", ios::in);
	if(file&&word.size()>1) //&&word.size()>1
	{
		while(! file.eof())
		{
			file>>testChain;
			if(testChain.compare(word) == 0)
			{
				sameWord = true;
			}
		}
		if(sameWord)
		{
			cout<<word<<" is in the dictionary."<<endl;
			isAword = true;
		}
		else
		{
			cout<<word<<" is not in the dictionary."<<endl;
			isAword = false;
		}
		file.close();
	}
	return isAword;
}

void CTiles::DrawBack()
{
	if(noTileMoved)
	{
		for(int j=0; j<7;j++)
		{
			tiles[Hand.at(j)]->Draw();
		}
	}
	else if(!noTileMoved)
	{
		for(int j=0; j<7;j++)
		{
			if(Hand.at(j)!=wichpict)
			{
				tiles[Hand.at(j)]->Draw();
			}
		}
		if(wichpict!=9999)
		{
			tiles[wichpict]->Draw();
		}
	}
	if(OnDeckForeva.size()>0)
	{
		for(size_t h = 0, size = OnDeckForeva.size(); h < size; ++h) 
		{
			tiles[OnDeckForeva.at(h)]->Draw();
		}
	}
	if(tileNumberb>9)
	{
		TileNumber->SetX(631);
	}
	else if(tileNumberb<10)
	{
		TileNumber->SetX(639);
	}
	tileNumbera = to_string((_ULonglong)tileNumberb);
	TileNumber->loadFromRenderedText(tileNumbera);
	TileNumber->DrawText();
	if(playerScoreb>99)
	{
		PlayerScore->SetX(735);
	}
	else if(playerScoreb>9)
	{
		PlayerScore->SetX(744);
	}
	else if(playerScoreb<10)
	{
		PlayerScore->SetX(755);
	}
	playerScorea = to_string((_ULonglong)playerScoreb);
	PlayerScore->loadFromRenderedText(playerScorea);
	PlayerScore->DrawText();
	MachineScore->DrawText();
}

void CTiles::PictClicked()
{
	if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			WichPict();
		}
	}
	else if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONUP && Lockwichpict)
	{
		SetTileOnDeck();
		if(!putBackTile&&!handLock&&!tiles[wichpict]->GetisOndeck()&&!swapon&&!firsttile&&!firsttileafteraturn)
		{
			tiles[wichpict]->SetPosition(Deck[deckPillar][deckRow]->GetX(),Deck[deckPillar][deckRow]->GetY());
			tiles[wichpict]->SetisOndeck(true);
			play = true;
			noTileMoved =false;
		}
		else if(!putBackTile&&!handLock&&!tiles[wichpict]->GetisOndeck()&&!swapon&&firsttile&&!firsttileafteraturn)
		{
			firsttile = false;
			tiles[wichpict]->SetPosition(283,282);
			tiles[wichpict]->SetisOndeck(true);
			play = true;
			noTileMoved = false;
		}
		else if(!putBackTile&&!handLock&&!tiles[wichpict]->GetisOndeck()&&!swapon&&firsttileafteraturn)
		{
			firsttileafteraturn = false;
			tiles[wichpict]->SetPosition(Deck[deckPillar][deckRow]->GetX(),Deck[deckPillar][deckRow]->GetY());
			tiles[wichpict]->SetisOndeck(true);
			play = true;
			noTileMoved = false;
		}
		else if(putBackTile&&!handLock)
		{
			//cout<<"Put back tile. "<<endl;
			tiles[wichpict]->SetPosition(tmpTileX, tmpTileY);
		}
		Follow = false;
		Lockwichpict = false;
		putBackTile = false;
		IsOnDeck = false;
		handLock = false;
		dreplswap = true;
		isPackedOnDeck = false;
		CxReloc=0, CyReloc=0;
		tmpTileX, tmpTileY=0;
	}
	if (timeCheck+5 < SDL_GetTicks() && Follow && !tiles[wichpict]->GetisOndeck())
	{
		//distances between card corners & the mouse location
		if((CxReloc==0)&&(CyReloc==0))
		{
			CxReloc=*MouseX-tiles[wichpict]->GetX();
			CyReloc=*MouseY-tiles[wichpict]->GetY();
		}
		//new card location
		CxRelocb=*MouseX-CxReloc;
		CyRelocb=*MouseY-CyReloc;
		if((tiles[wichpict]->GetX()!=CxRelocb)&&(tiles[wichpict]->GetY()!=CyRelocb))
		{
			tiles[wichpict]->SetPosition(*MouseX-CxReloc, *MouseY-CyReloc);
		}
		timeCheck = SDL_GetTicks();
	}
}

void CTiles::SetTileOnDeck()
{
	for(int i=0;i<7;i++)
	{
		if((tmpTileX>=642 && tmpTileX<=680) && (tmpTileY>=134 && tmpTileY<=405) && (*MouseX >= 642 && *MouseX <= 680) && (*MouseY >= 134+39*i && *MouseY <= 171+39*i) && !tiles[wichpict]->GetisOndeck())
		{
			for(int j=0;j<7;j++)
			{
				if(Hand.at(j)==wichpict)
				{
					tmpSwapedTileNb = j;
				}
			}
			Hand.at(tmpSwapedTileNb) = Hand.at(i);
			Hand.at(i) = wichpict;//new index of the tile moved
			tiles[Hand.at(tmpSwapedTileNb)]->SetPosition(tmpTileX, tmpTileY);
			tiles[Hand.at(i)]->SetPosition(642,134+39*i);
			tiles[Hand.at(tmpSwapedTileNb)]->SetisOnswap(false);
			tiles[Hand.at(i)]->SetisOnswap(false);
			handLock = true;
			noTileMoved = false;
		}
		else if((*MouseX >= 720 && *MouseX <= 758) && (*MouseY >= 134+39*i && *MouseY <= 171+39*i) && *swapLoop && !tiles[wichpict]->GetisOndeck()&& !tiles[wichpict]->GetisOnswap())
		{
			for(int j=0;j<7;j++)
			{
				if(Hand.at(j)==wichpict)
				{
					tmpSwapedTileNb = j;
				}
			}
			if(!tiles[Hand.at(i)]->GetisOnswap()&&!tiles[Hand.at(tmpSwapedTileNb)]->GetisOnswap())
			{
				Swap.push_back(wichpict);
				tiles[wichpict]->SetPosition(720,134+39*i);
				tiles[wichpict]->SetisOnswap(true);
				handLock = true;
				noTileMoved = false;
			}
		}
	}
	for(int k=0;k<15;k++)
	{
		for(int l=0;l<15;l++)
		{
			if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&firsttile&&!firsttileafteraturn&&!secondtile&&!secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//firsttile
				PlaceOnDeck(k, l);
				tmpFirstPillar=k;
				tmpFirstRow=l;
				firsttile=false;
				secondtile=true;
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&!firsttile&&!firsttileafteraturn&&secondtile&&!secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//secondtile
				PackedOnDeck();
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&!firsttile&&firsttileafteraturn&&!secondtile&&!secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//firsttileafteraturn
				PackedOnDeckSecond();
				if(Deck[k][l-1]->GetOccupied() || Deck[k][l+1]->GetOccupied() || Deck[k-1][l]->GetOccupied() || Deck[k+1][l]->GetOccupied())
				{
					tmpFirstPillar=k;
					tmpFirstRow=l;
					PlaceOnDeck(k, l);
					firsttileafteraturn=false;
					secondtileafteraturn=true;
				}
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&!firsttile&&!firsttileafteraturn&&!secondtile&&secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//secondtileafteraturn
				if(Deck[k][l-1]->GetOccupied() || Deck[k][l+1]->GetOccupied() || Deck[k-1][l]->GetOccupied() || Deck[k+1][l]->GetOccupied())
				{
					if((k==tmpLeftPillar||k==tmpRightPillar||k==tmpUpPillar||k==tmpDownPillar)||(l==tmpLeftRow||l==tmpRightRow||l==tmpUpRow||l==tmpDownRow))
					{
						if(k==tmpFirstPillar||l==tmpFirstRow)
						{
							tmpPillar=k;
							tmpRow=l;
							PlaceOnDeck(k, l);
							secondtileafteraturn=false;
						}
					}
				}
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&!firsttile&&!firsttileafteraturn&&!secondtile&&!secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//third tiles and beyond
				if((k==tmpPillar&&k==tmpFirstPillar)||(l==tmpRow&&l==tmpFirstRow))
				{
					PlaceOnDeck(k, l);
				}
			}
		}
	}
	if(IsOnDeck)
	{
		putBackTile = false;
		noTileMoved = false;
	}
	else if(!IsOnDeck)
	{
		putBackTile = true;
	}
}

void CTiles::PlaceOnDeck(int pillar, int row)
{
	OnDeck.push_back(wichpict);
	ResetPillar.push_back(pillar);
	ResetRow.push_back(row);
	Deck[pillar][row]->SetLetterCoefficient(tiles[wichpict]->GetPoints());
	Deck[pillar][row]->SetLetter(tiles[wichpict]->GetLetter());
	Deck[pillar][row]->SetOccupied(true);
	Deck[pillar][row]->SetCouldBeReset(true);
	deckPillar=pillar;
	deckRow=row;
	IsOnDeck=true;
}

void CTiles::PackedOnDeck()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if((*MouseX>=Deck[i][j]->GetX()&&*MouseX<=(Deck[i][j]->GetX()+36))&&(*MouseY>=Deck[i][j]->GetY()&&*MouseY<=(Deck[i][j]->GetY()+37)))
			{
				if(i-1>=0 && i+1<15 && j-1>=0 && j+1<15)
				{
					if(Deck[i][j-1]->GetOccupied() || Deck[i][j+1]->GetOccupied() || Deck[i-1][j]->GetOccupied() || Deck[i+1][j]->GetOccupied())
					{
						tmpPillar=i;
						tmpRow=j;
						PlaceOnDeck(i, j);
						secondtile=false;
					}
				}
			}
		}
	}
}

void CTiles::PackedOnDeckSecond()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if((*MouseX>=Deck[i][j]->GetX()&&*MouseX<=(Deck[i][j]->GetX()+36))&&(*MouseY>=Deck[i][j]->GetY()&&*MouseY<=(Deck[i][j]->GetY()+37)))
			{
				if(i-1>=0 && i+1<15 && j-1>=0 && j+1<15)
				{
					if(Deck[i][j-1]->GetOccupied())
					{
						tmpLeftPillar=i;
						tmpLeftRow=j-1;
					}
					else if(Deck[i][j+1]->GetOccupied())
					{
						tmpRightPillar=i;
						tmpRightRow=j+1;
					}
					else if(Deck[i-1][j]->GetOccupied())
					{
						tmpUpPillar=i-1;
						tmpUpRow=j;
					}
					else if(Deck[i+1][j]->GetOccupied())
					{
						tmpDownPillar=i+1;
						tmpDownRow=j;
					}
				}
			}
		}
	}
}

void CTiles::InitSpecCase()
{
	int Dls[24] = {3, 11, 36, 38, 45, 52, 59, 92, 96, 98, 102, 108, 116, 122, 126, 128, 132, 165, 172, 179, 186, 188, 213, 221};
	int Tls[12] = {20, 24, 76, 80, 84, 88, 136, 140, 144, 148, 200, 204};
	int Dws[16] = {16, 28, 32, 42, 48, 56, 64, 70, 154, 160, 168, 176, 182, 192, 196, 208};
	int Tws[8] = {0, 7, 14, 105, 119, 210, 217, 224};
	for(int m=0;m<15;m++)
	{
		for(int n=0;n<15;n++)
		{
			for(int o=0;o<24;o++)
			{
				if(Tls[o]==Deck[m][n]->GetCaseNumber())
				{
					Deck[m][n]->SetCaseCoefficient(1);
				}
			}
			for(int p=0;p<12;p++)
			{
				if(Tls[p]==Deck[m][n]->GetCaseNumber())
				{
					Deck[m][n]->SetCaseCoefficient(2);
				}
			}
			for(int q=0;q<16;q++)
			{
				if(Tls[q]==Deck[m][n]->GetCaseNumber())
				{
					Deck[m][n]->SetCaseCoefficient(3);
				}
			}
			for(int r=0;r<8;r++)
			{
				if(Tls[r]==Deck[m][n]->GetCaseNumber())
				{
					Deck[m][n]->SetCaseCoefficient(4);
				}
			}
		}
	}
}

void CTiles::WichPict()
{
	for(int i=0;i<100;i++)
	{
		if((*MouseX>=tiles[i]->GetX() && *MouseX<=tiles[i]->GetX()+36) && (*MouseY>=tiles[i]->GetY() && *MouseY<=tiles[i]->GetY()+36) && !Lockwichpict)//was+35 &+36 before
		{
			tmpTileX=tiles[i]->GetX();
			tmpTileY=tiles[i]->GetY();
			wichpict = i;
			Lockwichpict = true;
			Follow = true;
		}
	}
}

void CTiles::SetSwapOn(bool passed_SwapOn)
{
	swapon=passed_SwapOn;
}

void CTiles::SetPlay(bool passed_play)
{
	play = passed_play;
}

void CTiles::SetFirstTile(bool passed_FirstTile)
{
	firsttile=passed_FirstTile;
}

void CTiles::SetFirstTileAfteraTurn(bool passed_FirstTileAfteraTurn)
{
	firsttileafteraturn=passed_FirstTileAfteraTurn;
}
