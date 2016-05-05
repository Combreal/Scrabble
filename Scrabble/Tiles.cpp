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
	noTileMoved = true;
	Follow=false, Lockwichpict=false, swapon=false;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;
	swapLoop = passed_SwapLoop;
	timeCheck = SDL_GetTicks();
	dTilesnb = 0;
	comp = 0;
	IsOnDeck = false;
	isClicked = false;
	putBackTile = false;
	handLock = false;
	TilesNb = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_14.png", 637, 95, 11, 15, '-', 0);
	Decade_TilesNb = new CSprite(csdl_setup->GetRenderer(), "data/counter/numbers_14.png", 627, 95, 11, 15, '-', 0);
	tiles[0] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/joker.png", 0, 0, 36, 37, '_', 0);
	tiles[1] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/joker.png", 0, 0, 36, 37, '_', 0);
	tiles[2] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[3] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[4] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[5] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[6] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[7] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[8] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[9] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[10] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/A.png", 0, 0, 36, 37, 'a', 1);
	tiles[11] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/B.png", 0, 0, 36, 37, 'b', 3);
	tiles[12] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/B.png", 0, 0, 36, 37, 'b', 3);
	tiles[13] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/C.png", 0, 0, 36, 37, 'c', 3);
	tiles[14] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/C.png", 0, 0, 36, 37, 'c', 3);
	tiles[15] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 36, 37, 'd', 2);
	tiles[16] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 36, 37, 'd', 2);
	tiles[17] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 36, 37, 'd', 2);
	tiles[18] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/D.png", 0, 0, 36, 37, 'd', 2);
	tiles[19] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[20] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[21] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[22] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[23] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[24] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[25] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[26] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[27] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[28] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[29] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[30] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/E.png", 0, 0, 36, 37, 'e', 1);
	tiles[31] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/F.png", 0, 0, 36, 37, 'f', 4);
	tiles[32] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/F.png", 0, 0, 36, 37, 'f', 4);
	tiles[33] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 36, 37, 'g', 2);
	tiles[34] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 36, 37, 'g', 2);
	tiles[35] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/G.png", 0, 0, 36, 37, 'g', 2);
	tiles[36] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/H.png", 0, 0, 36, 37, 'h', 4);
	tiles[37] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/H.png", 0, 0, 36, 37, 'h', 4);
	tiles[38] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[39] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[40] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[41] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[42] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[43] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[44] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[45] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[46] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/I.png", 0, 0, 36, 37, 'i', 1);
	tiles[47] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/J.png", 0, 0, 36, 37, 'j', 8);
	tiles[48] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/K.png", 0, 0, 36, 37, 'k', 5);
	tiles[49] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 36, 37, 'l', 1);
	tiles[50] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 36, 37, 'l', 1);
	tiles[51] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 36, 37, 'l', 1);
	tiles[52] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/L.png", 0, 0, 36, 37, 'l', 1);
	tiles[53] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/M.png", 0, 0, 36, 37, 'm', 3);
	tiles[54] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/M.png", 0, 0, 36, 37, 'm', 3);
	tiles[55] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[56] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[57] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[58] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[59] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[60] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/N.png", 0, 0, 36, 37, 'n', 1);
	tiles[61] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[62] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[63] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[64] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[65] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[66] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[67] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[68] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/O.png", 0, 0, 36, 37, 'o', 1);
	tiles[69] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/P.png", 0, 0, 36, 37, 'p', 3);
	tiles[70] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/P.png", 0, 0, 36, 37, 'p', 3);
	tiles[71] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Q.png", 0, 0, 36, 37, 'q', 10);
	tiles[72] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[73] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[74] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[75] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[76] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[77] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/R.png", 0, 0, 36, 37, 'r', 1);
	tiles[78] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 36, 37, 's', 1);
	tiles[79] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 36, 37, 's', 1);
	tiles[80] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 36, 37, 's', 1);
	tiles[81] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/S.png", 0, 0, 36, 37, 's', 1);
	tiles[82] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[83] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[84] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[85] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[86] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[87] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/T.png", 0, 0, 36, 37, 't', 1);
	tiles[88] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 36, 37, 'u', 1);
	tiles[89] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 36, 37, 'u', 1);
	tiles[90] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 36, 37, 'u', 1);
	tiles[91] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/U.png", 0, 0, 36, 37, 'u', 1);
	tiles[92] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/V.png", 0, 0, 36, 37, 'v', 4);
	tiles[93] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/V.png", 0, 0, 36, 37, 'v', 4);
	tiles[94] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/W.png", 0, 0, 36, 37, 'w', 4);
	tiles[95] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/W.png", 0, 0, 36, 37, 'w', 4);
	tiles[96] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/X.png", 0, 0, 36, 37, 'x', 8);
	tiles[97] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Y.png", 0, 0, 36, 37, 'y', 4);
	tiles[98] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Y.png", 0, 0, 36, 37, 'y', 4);
	tiles[99] = new CSprite(csdl_setup->GetRenderer(), "data/tiles/Z.png", 0, 0, 36, 37, 'z', 10);
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			Deck[i][j] = new CDeck(10+j*39, 9+i*39, i*15+j, false, 0, '\0', 0);
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
	for(int i=0; i<7;i++)
	{
		Hand.push_back(TilesNumber.at(i));
		tiles[TilesNumber.at(i)]->SetPosition(642,134+39*i);
		//tiles[TilesNumber.at(i)]->SetWidth(tiles[TilesNumber.at(i)]->GetWidth()-1);
		//cout<<Hand.at(i)<<endl;
		//cout<<"Hand : "<<Hand.at(i)<<endl;
	}
	//TilesNumber.erase (TilesNumber.begin(),TilesNumber.begin()+8);
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
		tiles[wichpict]->Draw();
	}
	//tiles[Hand.at(7)]->Draw();//use value instead of pos in the vector, fixed hopefully
	//tiles[TilesNumber.at(8)]->SetPosition(Deck[15][15]->GetX(), Deck[15][15]->GetY());
	//tiles[TilesNumber.at(8)]->Draw();
	//cout<<*swapLoop<<endl;
}

void CTiles::PictClicked()
{
	if (csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || csdl_setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			WichPict();
			//Follow = true;
			//cout<<"wichpict : "<<wichpict<<endl;
			//cout<<Deck[deckPillar][deckRow]->Get
		}
	}
	else if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONUP && Lockwichpict)
	{
		SetTileOnDeck(*MouseX, *MouseY, wichpict);
		if(!putBackTile&&!handLock)
		{
			tiles[wichpict]->SetPosition(Deck[deckPillar][deckRow]->GetX(),Deck[deckPillar][deckRow]->GetY());
			noTileMoved =false;
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
		CxReloc=0, CyReloc=0;
		tmpTileX, tmpTileY=0;
		//SDL_Delay(500);
	}
	if (timeCheck+5 < SDL_GetTicks() && Follow)
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

void CTiles::SetTileOnDeck(int setTx, int setTy, int tileNumber)
{
	for(int i=0;i<7;i++)
	{
		if((setTx >= 720 && setTx <= 758) && (setTy >= 134+39*i && setTy <= 171+39*i) && *swapLoop)
		{
			tiles[tileNumber]->SetPosition(720,134+39*i);
			handLock = true;
			noTileMoved = false;
		}
	}
	for(int k=0;k<15;k++)
	{
		for(int l=0;l<15;l++)
		{
			if((setTx>=Deck[k][l]->GetX()&&setTx<=(Deck[k][l]->GetX()+36))&&(setTy>=Deck[k][l]->GetY()&&setTy<=(Deck[k][l]->GetY()+37))&&!handLock&&!Deck[k][l]->GetOccupied()) //&&!Deck[k][l]->GetOccupied()  ??
			{
				Deck[k][l]->SetLetterCoefficient(tiles[k+l]->GetPoints());
				Deck[k][l]->SetLetter(tiles[k+l]->GetLetter());
				Deck[k][l]->SetOccupied(true);
				deckPillar=k;
				deckRow=l;
				IsOnDeck=true;
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
		if((*MouseX>=tiles[i]->GetX() && *MouseX<=tiles[i]->GetX()+36) && (*MouseY>=tiles[i]->GetY() && *MouseY<=tiles[i]->GetY()+37) && !Lockwichpict)
		{
			tmpTileX=tiles[i]->GetX();
			tmpTileY=tiles[i]->GetY();
			wichpict = i;
			//cout<<"Wichpict : "<<wichpict<<endl;
			Lockwichpict = true;
			Follow = true;
		}
		/*else
		{
			putBackTile=true;
		}
		cout<<"lockwichPict : "<<Lockwichpict<<endl;
		cout<<"Putbacktile : "<<putBackTile<<endl;*/
	}
}

void CTiles::SetSwapOn(bool passed_SwapOn)
{
	swapon=passed_SwapOn;
}

void CTiles::SetTilesNb(int passed_tilesnb)//all the tiles not on the deck
{
	dTilesnb = (float)passed_tilesnb;
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