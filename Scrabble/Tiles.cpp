#include "Tiles.h"
using namespace std;

CTiles::CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup)
{
	csdl_setup = passed_SDL_Setup;
	srand(unsigned(time(0)));
	letter = '\0';
	theTilesnb, tilesnb, decade_tilesnb = 0;
	CxRelocb=0, CyRelocb=0;
	wichpict = 0;
	CxReloc=0, CyReloc=0;
	deckRow, deckPillar = 0;
	tmpTileX, tmpTileY = 0;
	tmpPillar, tmpRow = 0;
	tmpPrevPillar, tmpPrevRow = 0;//not sure of any use
	tmpSwapedTileNb = 0;
	tmpSwap = 0;
	stayInPillarOrRow = 0;
	playerScore = 0;
	machineScore = 0;
	noTileMoved = true;
	Follow=false, Lockwichpict=false, swapon=false;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;
	swapLoop = passed_SwapLoop;
	timeCheck = SDL_GetTicks();
	dTilesnb = 0;
	comp = 0;
	tileCounter = 93;
	play = false;
	playAlreadyClicked = false;
	isPackedOnDeck = false;
	IsOnDeck = false;
	isClicked = false;
	putBackTile = false;
	handLock = false;
	firsttileafteraturn = false;
	direction = false;
	directionCheck = false;
	firsttile = true;
	dreplswap = true;
	initGetHand = true;
	initPictClicked = true;
	initStayInDirection = true;
	stayInDirection = false;
	Score = new CScore(csdl_setup);
	TilesNb = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_14.png", 637, 95, 11, 15, '-', 0, 0, 0);
	Decade_TilesNb = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_14.png", 627, 95, 11, 15, '-', 0, 0, 0);
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
			Deck[i][j] = new CDeck(10+j*39, 9+i*39, i*15+j, false, 0, '\0', 0, false);//was 39before
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
	delete TilesNb;
	delete Decade_TilesNb;
	delete Score;
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
	if(!initGetHand)
	{
		tmpPillar = 0;
		tmpRow = 0;
		tmpPrevPillar = 0;
		tmpPrevRow = 0;
		stayInPillarOrRow = 0;
		initStayInDirection = true;
		direction = false;
		OnDeck.clear();
		Swap.clear();
		if(playAlreadyClicked)
		{
			firsttile = false;
			firsttileafteraturn = true;
		}
		else if(!playAlreadyClicked)
		{
			firsttile = true;
			
		}
		for(int i=0; i<7;i++)
		{
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
	else if(initGetHand)
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
		initGetHand = false;
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

void CTiles::Play()
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
	tileCounter = tileCounter - OnDeck.size();
	playAlreadyClicked = true;
	firsttile = false;
	initStayInDirection = true;
	direction = false;
	firsttileafteraturn = true;
	tmpPillar = 0;
	tmpRow = 0;
	stayInPillarOrRow = 0;
	OnDeck.clear();
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
	Score->SetScore(playerScore);
	Score->SetBotScore(machineScore);
}

void CTiles::PictClicked()
{
	if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			WichPict();
			//cout<<"FirstTile : "<<firsttile<<endl;
		}
	}
	else if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONUP && Lockwichpict)
	{
		if(initPictClicked)
		{
			//cout<<"FirstTileAfterTurn : "<<firsttileafteraturn<<endl;
			SetTileOnDeck();
			//cout<<"FirstTileAfterTurn aftersettileondeck : "<<firsttileafteraturn<<endl;
			/*cout<<"PutBackTile : "<<putBackTile<<endl;
			cout<<"handLock : "<<handLock<<endl;
			cout<<"Tiles-wichpict getisondeck : "<<tiles[wichpict]->GetisOndeck()<<endl;
			cout<<"Swapon : "<<swapon<<endl;
			cout<<"FirstTile : "<<firsttile<<endl;*/
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
			Hand.at(i) = wichpict;//tile moved new index
			tiles[Hand.at(tmpSwapedTileNb)]->SetPosition(tmpTileX, tmpTileY);
			tiles[Hand.at(i)]->SetPosition(642,134+39*i);
			tiles[Hand.at(tmpSwapedTileNb)]->SetisOnswap(false);
			tiles[Hand.at(i)]->SetisOnswap(false);
			handLock = true;
			noTileMoved = false;
		}
		else if((*MouseX >= 720 && *MouseX <= 758) && (*MouseY >= 134+39*i && *MouseY <= 171+39*i) && *swapLoop && !tiles[wichpict]->GetisOndeck()&& !tiles[wichpict]->GetisOnswap())
		{
			//Swap.clear();
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
				tiles[wichpict]->SetPosition(720,134+39*i);//TilesNumber.at(i)
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
			if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&!handLock&&!swapon&&!firsttile&&!Deck[k][l]->GetOccupied()&&!firsttileafteraturn) //&&!Deck[k][l]->GetOccupied()  ??
			{
				if(PackedOnDeck())
				{
					if((k==tmpPillar&&k==tmpPrevPillar)||(l==tmpRow&&l==tmpPrevRow))
					{
						direction = true;
					}
					else
					{
						direction = false;
					}
					if(initStayInDirection)
					{
						if((k==tmpPrevPillar||l==tmpPrevRow)&&playAlreadyClicked)
						{
							tmpPillar=k;
							tmpRow=l;
							PlaceOnDeck(k, l);
							initStayInDirection=false;
						}
						else if(!playAlreadyClicked)
						{
							tmpPillar=k;
							tmpRow=l;
							PlaceOnDeck(k, l);
							initStayInDirection=false;
						}
					}
					if(direction)
					{
						PlaceOnDeck(k, l);
					}
				}
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&firsttile&&!handLock&&!swapon)
			{
				PlaceOnDeck(k, l);
				tmpPrevPillar=k;
				tmpPrevRow=l;
			}
			else if((*MouseX>=Deck[k][l]->GetX()&&*MouseX<=(Deck[k][l]->GetX()+36))&&(*MouseY>=Deck[k][l]->GetY()&&*MouseY<=(Deck[k][l]->GetY()+37))&&firsttileafteraturn&&!handLock&&!swapon)
			{
				if(PackedOnDeck())
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
	Deck[pillar][row]->SetLetterCoefficient(tiles[pillar*15+row]->GetPoints());
	Deck[pillar][row]->SetLetter(tiles[pillar*15+row]->GetLetter());
	Deck[pillar][row]->SetOccupied(true);
	Deck[pillar][row]->SetCouldBeReset(true);
	deckPillar=pillar;
	deckRow=row;
	IsOnDeck=true;
}

bool CTiles::PackedOnDeck()
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
						/*cout<<"j-1 : "<<Deck[i][j-1]->GetOccupied()<<endl;
						cout<<"j+1 : "<<Deck[i][j+1]->GetOccupied()<<endl;
						cout<<"i-1 : "<<Deck[i-1][j]->GetOccupied()<<endl;
						cout<<"i+1 : "<<Deck[i+1][j]->GetOccupied()<<endl;
						cout<<"Tiles Packed on Deck. "<<endl;*/
						tmpPrevPillar=i;
						tmpPrevRow=j-1;
						isPackedOnDeck = true;
					}
					else if(Deck[i][j+1]->GetOccupied())
					{
						tmpPrevPillar=i;
						tmpPrevRow=j+1;
						isPackedOnDeck = true;
					}
					else if(Deck[i-1][j]->GetOccupied())
					{
						tmpPrevPillar=i-1;
						tmpPrevRow=j;
						isPackedOnDeck = true;
					}
					else if(Deck[i+1][j]->GetOccupied())
					{
						tmpPrevPillar=i+1;
						tmpPrevRow=j;
						isPackedOnDeck = true;
					}
				}
				else if(i-1<0)
				{
					if(Deck[i][j-1]->GetOccupied()||Deck[i][j+1]->GetOccupied()||Deck[i+1][j]->GetOccupied())
					{
						isPackedOnDeck = true;
					}
				}
				else if(i+1>14)//bottom line
				{
					if(Deck[i][j-1]->GetOccupied()||Deck[i][j+1]->GetOccupied()||Deck[i-1][j]->GetOccupied())
					{
						isPackedOnDeck = true;
					}
				}
				else if(j-1<0)
				{
					if(Deck[i][j+1]->GetOccupied()||Deck[i-1][j]->GetOccupied()||Deck[i+1][j]->GetOccupied())
					{
						isPackedOnDeck = true;
					}
				}
				else if(j+1>14)
				{
					if(Deck[i][j-1]->GetOccupied()||Deck[i-1][j]->GetOccupied()||Deck[i+1][j]->GetOccupied())
					{
						isPackedOnDeck = true;
					}
				}
			}
		}
	}
	return isPackedOnDeck;
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
	//if(((m*15+n)==3)||((m*15+n)==11))
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

void CTiles::TilesCounter()
{
	dTilesnb = (float)tileCounter;
	theTilesnb = dTilesnb;
	tilesnb = 0;
	decade_tilesnb = 0;
	comp = 0;
	if(dTilesnb>=10)
	{
		comp = dTilesnb/10;
		decade_tilesnb = floor(comp);
		tilesnb = dTilesnb - decade_tilesnb*10;
		Decade_TilesNb->TilesNbCrop((int)decade_tilesnb);
		TilesNb->TilesNbCrop((int)tilesnb);
		Decade_TilesNb->Draw();
		TilesNb->Draw();
	}
	else if(dTilesnb<10)
	{
		tilesnb = dTilesnb;
		TilesNb->TilesNbCrop((int)tilesnb);
		TilesNb->Draw();
	}
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
