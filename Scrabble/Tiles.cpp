#include "Tiles.h"
using namespace std;

CTiles::CTiles(bool *passed_SwapLoop, int *passed_MouseX, int *passed_MouseY, CSDL_Setup* passed_SDL_Setup)
{
	csdl_setup = passed_SDL_Setup;
	srand(unsigned(time(0)));
	letter = '\0';
	horizontalFirst=0, horizontalLast=0, verticalFirst=0, verticalLast = 0;
	horizontalBotFirst=0, horizontalBotLast=0, verticalBotFirst=0, verticalBotLast = 0;
	CxRelocb=0, CyRelocb=0;
	wichpict = 0;
	CxReloc=0, CyReloc=0;
	deckRow=0, deckPillar = 0;
	botDownSideMax=0, botRightSideMax = 0;
	botUpSideMax=0, botLeftSideMax = 0;
	botPillarSearch=0, botRowSearch = 0;
	deadEndCounter = 0;
	tmpTileX=0, tmpTileY = 0;
	tmpPillar=0, tmpRow = 0;
	tmpFirstPillar=0, tmpFirstRow = 0;
	tmpSwapedTileNb = 0;
	tmpSwap = 0;
	randTileNb = 0;
	newBotScore = 0;
	botScoreb = 0;
	noWordCounter = 0;
	noWordCounterb = 0;
	roll = 0;
	TNLopOffCounter = 0;
	unusedTile = 0;
	availableTile = 0;
	randomKey = 0;
	found=0, botFound = 0;
	tileNumberb=93, playerScoreb=0, machineScoreb = 0;
	newScore = 0;
	playerScorea = "0";
	machineScorea = "0";
	tileNumbera = "93";
	dictionaryPath = "data/dictionary/enDict.txt";
	tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
	randTileNbFound = false;
	ctrlInit = false;
	quitCDLoop = false;
	deadEnd = false;
	noWord = false;
	botPass = false;
	noTileMoved = true;
	randomizeBotHand = false;
	initRetrieveWord = true;
	firstWordIsFromBot = false;
	GetBotRightSide=false, GetBotDownSide=false;
	GetBotLeftSide=false, GetBotUpSide=false;
	Follow=false, Lockwichpict=false, swapon=false;
	isInTheVector=false, isInTheVectorb=false;
	MouseX = passed_MouseX;
	MouseY = passed_MouseY;
	swapLoop = passed_SwapLoop;
	timeCheck = SDL_GetTicks();
	botJockerPos[0] = 0;
	botJockerPos[1] = 0;
	jockerPos[0] = 0;
	jockerPos[1] = 0;
	jocker[0] = false;
	jocker[1] = false;
	botJocker[0] = false;
	botJocker[1] = false;
	BotchosenDirection = false;
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
	initBotHand = true;
	initTNLopOff = true;
	initBTNLopOff = true;
	quitCheckWordListLoop = false;
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
			Deck[i][j] = new CDeck(10+j*39, 9+i*39, i*15+j, false, 0, '\0', 0, false, -1);
		}
	}
	InitSpecCase();
	for(int k=0; k<100;k++)
	{
		TilesNumber.insert(make_pair(k, false));
	}
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
		unusedTile = GetAvailableTile(TilesNumber);
		TilesNumber.at(unusedTile)=true;
		//tileNumberb--;
		Hand.push_back(unusedTile);
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
					if(Deck[k][l]->GetTileId()>0)
					{
						Deck[k][l]->SetTileId(-1);
					}
				}
			}
		}
	}
}

void CTiles::Swapy()
{
	for(size_t e=0, size=Swap.size(); e<size; ++e) 
	{
		itt = TilesNumber.begin();
		while(itt != TilesNumber.end())
		{
			if(itt->first==Swap.at(e))
			{
				itt->second=false;
				break;
			}
			itt++;
		}
	}
	for(size_t h = 0, sizec = Swap.size(); h < sizec; ++h) 
	{  
		for(size_t f = 0, sized = Hand.size(); f < sized; ++f) 
		{  
			if(Swap[h]==Hand[f])
			{
				randTileNbFound = true;
				while(randTileNbFound)
				{
					unusedTile = GetAvailableTile(TilesNumber);
					if(!IsInTheVectorb(unusedTile, OnDeck)&&!IsInTheVectorb(unusedTile, Hand)&&!IsInTheVectorb(unusedTile, OnDeckForeva)&&!IsInTheVectorb(unusedTile, keepBotHand)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(unusedTile, Hand)&&!IsInTheVectorb(unusedTile, Swap))
					{
						TilesNumber.at(randTileNb)=true;
						//tileNumberb--;
						Hand[f]=unusedTile;
						tiles[Hand.at(f)]->SetPosition(642,134+39*f);
						randTileNbFound = false;
					}
				}
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
			Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetTileId(-1);
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
	if(tileNumberb>7)
	{
		RetrievedWord();
		SetNewScore();
		playerScoreb = playerScoreb + newScore;
		if(isAword&&!ctrlInit)
		{
			for(size_t a = 0, size = OnDeck.size(); a < size; ++a) 
			{
				OnDeckForeva.push_back(OnDeck.at(a));
			}
			//LopOffPT();
			tmpPillar=0, tmpRow = 0;
			tmpFirstPillar=0, tmpFirstRow = 0;
			tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
			firsttile = false;
			secondtile = false;
			firsttileafteraturn = true;
			secondtileafteraturn = false;
			playAlreadyClicked = true;
			tileNumberb = tileNumberb - OnDeck.size();
			//OnDeck.clear();
			ResetPillar.clear();
			ResetRow.clear();
			Swap.clear();
		}
		if(!isAword&&!ctrlInit)
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
					Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetter('\0');
					Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetLetterCoefficient(0);
					Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetOccupied(false);
					Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetCouldBeReset(false);
					Deck[ResetPillar.at(m)][ResetRow.at(n)]->SetTileId(-1);
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
		ctrlInit = false;
	}
}

int CTiles::GetAvailableTile(map<int,bool>& passed_map)
{
	availableTile=0;
	quitCDLoop = false;
	itt = passed_map.begin();
	advance(itt, rand() % TilesNumber.size());//rand() % TilesNumber.size() //rand_a_b(0, TilesNumber.size()+1)
	randomKey = itt->first;
	if(!itt->second)
	{
		availableTile = randomKey;
	}
	else if(itt->second)
	{
		while(!quitCDLoop)
		{
			itt = passed_map.begin();
			advance(itt, rand() % TilesNumber.size());
			randomKey = itt->first;
			if(!itt->second)
			{
				availableTile = randomKey;
				quitCDLoop = true;
			}
		}
	}
	return availableTile;
}

void CTiles::LopOffPT()
{
	TNLopOffCounter = 0;
	if(tileNumberb>7)
	{
		for(size_t h = 0, size = OnDeck.size(); h < size; ++h)
		{
			for(size_t f = 0, size = Hand.size(); f < size; ++f) 
			{  
				randTileNbFound = true;
				if(OnDeck[h]==Hand[f])
				{
					while(randTileNbFound)
					{
						randTileNb = GetAvailableTile(TilesNumber);
						if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!IsInTheVectorb(randTileNb, keepBotHand)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
						{
							TilesNumber.at(randTileNb)=true;
							tileNumberb--;
							Hand[f]=randTileNb;				
							tiles[Hand.at(f)]->SetPosition(642,134+39*f);
							randTileNbFound = false;
						}
					}
				}
			}
		}
	}
	else if(tileNumberb<7)
	{
		tileNumberb = 0;
	}
	OnDeck.clear();
	if(firsttile&&botScoreb>0)
	{
		firsttile = false;
		secondtile = false;
		firsttileafteraturn = true;
		secondtileafteraturn = false;
	}
	randTileNbFound = true;
}

int CTiles::rand_a_b(int a, int b)//b+1 when using the arg
{
	return rand()%(b-a) +a;
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
	if((initRetrieveWord&&OnDeck.size()==1&&Deck[7][7]->GetLetter()=='a')||(initRetrieveWord&&OnDeck.size()==1&&Deck[7][7]->GetLetter()=='i'))
	{
		word.push_back(Deck[7][7]->GetLetter());
		OnDeckForeva.push_back(OnDeck.at(0));
		newScore++;
		initTNLopOff = false;
		initRetrieveWord = false;
		tmpPillar=0, tmpRow = 0;
		tmpFirstPillar=0, tmpFirstRow = 0;
		tmpLeftPillar=-1, tmpLeftRow=-1, tmpRightPillar=-1, tmpRightRow=-1, tmpUpPillar=-1, tmpUpRow=-1, tmpDownPillar=-1, tmpDownRow = -1;
		firsttile = false;
		secondtile = false;
		firsttileafteraturn = true;
		secondtileafteraturn = false;
		playAlreadyClicked = true;
		ctrlInit = true;
		tileNumberb = tileNumberb - 7;
		//OnDeck.clear();
		ResetPillar.clear();
		ResetRow.clear();
		Swap.clear();
		cout<<"gosh. "<<OnDeckForeva.at(0)<<endl;
	}
	else if((initRetrieveWord&&OnDeck.size()==1&&Deck[7][7]->GetLetter()!='a')||(initRetrieveWord&&OnDeck.size()==1&&Deck[7][7]->GetLetter()!='i'))
	{
		initRetrieveWord = false;
	}
	else if(initRetrieveWord&&OnDeck.size()>1)
	{
		initRetrieveWord = false;
	}
	if(tmpFirstPillar==tmpPillar&&!initRetrieveWord)
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
	else if(tmpFirstRow==tmpRow&&!initRetrieveWord)
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
	if(IsAWord())
	{
		newScore = 0;
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
	jocker[0] = false;
	jocker[1] = false;
	jockerPos[0] = 0;
	jockerPos[1] = 0;
	wordCopy = word;
	for(int i=0;i<2;i++)
	{
		found = wordCopy.find('_');
		if(wordCopy.find('_') != std::string::npos)
		{
			jocker[i]=true;
			jockerPos[i]=found;
			wordCopy.erase(found, 1);
		}
	}
	ifstream file(dictionaryPath, ios::in);
	if(file&&word.size()>1)
	{
		while(! file.eof())
		{
			file>>testChain;
			if(testChain.compare(word) == 0)
			{
				sameWord = true;
			}
			else if(jocker[0]&&!jocker[1])
			{
				if(testChain.size()==word.size())
				{
					testChain.erase(jockerPos[0], 1);
					if(testChain.compare(wordCopy) == 0)
					{
						sameWord = true;
					}
				}
			}
			else if(jocker[0]&&jocker[1])
			{
				if(testChain.size()==word.size())
				{
					testChain.erase(jockerPos[0], 1);
					testChain.erase(jockerPos[1], 1);
					if(testChain.compare(wordCopy) == 0)
					{
						sameWord = true;
					}
				}
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
	if(OnDeckForeva.size()>0)
	{
		for(size_t h = 0, size = OnDeckForeva.size(); h < size; ++h) 
		{
			tiles[OnDeckForeva.at(h)]->Draw();
		}
	}
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
	if(botScoreb>99)
	{
		MachineScore->SetX(735);
	}
	else if(botScoreb>9)
	{
		MachineScore->SetX(744);
	}
	else if(botScoreb<10)
	{
		MachineScore->SetX(755);
	}
	machineScorea = to_string((_ULonglong)botScoreb);
	MachineScore->loadFromRenderedText(machineScorea);
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
		if((tmpTileX>=642 && tmpTileX<=680) && (tmpTileY>=134 && tmpTileY<=405) && (*MouseX >= 642 && *MouseX <= 680) && (*MouseY >= 134+39*i && *MouseY <= 171+39*i) && !tiles[wichpict]->GetisOndeck() && !*swapLoop)
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
			if((*MouseX>=Deck[7][7]->GetX()&&*MouseX<=(Deck[7][7]->GetX()+36))&&(*MouseY>=Deck[7][7]->GetY()&&*MouseY<=(Deck[7][7]->GetY()+37))&&!handLock&&!swapon&&firsttile&&!firsttileafteraturn&&!secondtile&&!secondtileafteraturn&&!Deck[k][l]->GetOccupied())
			{//firsttile
				PlaceOnDeck(7, 7);
				tmpFirstPillar=7;
				tmpFirstRow=7;
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
	Deck[pillar][row]->SetTileId(wichpict);
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
				if(Dls[o]==Deck[m][n]->GetCaseNumber())
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
				if(Dws[q]==Deck[m][n]->GetCaseNumber())
				{
					Deck[m][n]->SetCaseCoefficient(3);
				}
			}
			for(int r=0;r<8;r++)
			{
				if(Tws[r]==Deck[m][n]->GetCaseNumber())
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

void CTiles::SetMachineScore(std::string passed_score)
{
	machineScorea=passed_score;
}

void CTiles::SetTilesNumber(std::string passed_tilesNumber)
{
	tileNumbera=passed_tilesNumber;
}

bool CTiles::CheckDeadEnd()
{
	deadEndCounter = 0;
	for(size_t i=0, size=OnDeckForeva.size();i<size;i++)
	{
		for(int j=0;j<15;j++)
		{
			for(int k=0;k<15;k++)
			{
				if(Deck[j][k]->GetTileId()==OnDeckForeva.at(i)&&OnDeckForeva.size()>0)
				{
					if((Deck[j][k+1]->GetOccupied()&&Deck[j+1][k]->GetOccupied())||(Deck[j][k-1]->GetOccupied()&&Deck[j+1][k]->GetOccupied())||(Deck[j-1][k]->GetOccupied()&&Deck[j][k+1]->GetOccupied())||(Deck[j][k-1]->GetOccupied()&&Deck[j-1][k]->GetOccupied()))
					{
						deadEndCounter++;
					}
				}
			}
		}
	}
	if(deadEndCounter==OnDeckForeva.size()&&OnDeckForeva.size()>0)
	{
		SDL_Delay(500);
		deadEnd = true;
	}
	else if(tileNumberb==0&&OnDeckForeva.size()>0)
	{
		SDL_Delay(500);
		deadEnd = true;
	}
	return deadEnd;
}

void CTiles::SetDictionaryPath(std::string passed_dictionaryPath)
{
	dictionaryPath = passed_dictionaryPath;
	cout<<dictionaryPath<<endl;
}

void CTiles::AiPlay()
{
	//Spot letter on deck with at least 3 cases unocuppied right or down next to it 
	//and the maximum space available (could be untill it reach an occupied case or the deck border)
	//Class each scenario number possible in a vector, randomize the vector and apply its first number
	//Search for a 3 letters min word with that letter selected and the BotHand ones
	//
	//					Repeat untill word match - including use of jockers
	//					Or handle the swap for the Ai
	//
	//Place tiles on deck, keep track on OnDeckForEva
	//Clean things up for next turn
	if(tileNumberb>7)
	{
		RandomizedOnDeckForeva = OnDeckForeva;
		BotHandTransf.push_back(9999);
		noWordCounter=0;
		roll = rand() % 100 + 1;
		if(roll<=10)
		{
			botPass = true;
			cout<<"Bot passed. "<<endl;
			if(!firstWordIsFromBot&&RandomizedOnDeckForeva.size()==0)
			{
				FirstWordIsFromBot();
				firstWordIsFromBot = true;
			}
		}
		while(!GetBotDownSide && !GetBotRightSide &&!botPass&&!noWord)
		{
			if(noWordCounter>=30 &&!botPass&&!firstWordIsFromBot)
			{
				noWord=true;
				forceBotHandRandomization();
				break;
			}
			noWordCounter++;
			cout<<"noWordCounter : "<<noWordCounter<<endl;
			random_shuffle(RandomizedOnDeckForeva.begin(), RandomizedOnDeckForeva.end());
			BotchosenDirection = rand() & 1;
			if(RandomizedOnDeckForeva.size()==0)
			{
				FirstWordIsFromBot();
				firstWordIsFromBot = true;
				break;
			}
			else if(BotchosenDirection&&!botPass&&!firstWordIsFromBot)
			{
				botDownSideMax = 0;
				GetDeckPillarAndRow(RandomizedOnDeckForeva.at(0));
				if(GetBotDownSideMax()&&GetBotUpSideMax())
				{
					break;
				}
				noWordCounter++;
			}
			else if(!BotchosenDirection &&!botPass&&!firstWordIsFromBot)
			{
				botRightSideMax = 0;
				GetDeckPillarAndRow(RandomizedOnDeckForeva.at(0));
				if(GetBotRightSideMax()&&GetBotLeftSideMax())
				{
					break;
				}
				noWordCounter++;
			}
		}
		if(BotchosenDirection&&!noWord &&!botPass&&!firstWordIsFromBot)
		{
			botDownSideNormal();
		}
		else if(!BotchosenDirection&&!noWord &&!botPass&&!firstWordIsFromBot)
		{
			botRightSideNormal();
		}
		if(!botPass&&!firstWordIsFromBot&&WordsFound.size()>0)
		{
			SetNewBotScore();
			botScoreb = botScoreb + newBotScore;
		}
		if(!initBTNLopOff&&!noWord &&!botPass&&!firstWordIsFromBot&&WordsFound.size()>0)
		{
			for(size_t c = 0, sizeh = BotHand.size(); c < sizeh; ++c) 
			{
				if(!IsInTheVectorb(BotHand.at(c), BotHandTransf))
				{
					keepBotHand.push_back(BotHand.at(c));
				}
			}
			tileNumberb = tileNumberb - (BotHand.size() - BotHandTransf.size()-1);//or WordsFound.at(0).size()-1
		}
		else if(initBTNLopOff&&!noWord&&!firstWordIsFromBot&&WordsFound.size()>0)
		{
			for(size_t b = 0, sizeg = BotHand.size(); b < sizeg; ++b) 
			{
				if(!IsInTheVectorb(BotHand.at(b), BotHandTransf))
				{
					keepBotHand.push_back(BotHand.at(b));
				}
			}
			tileNumberb = tileNumberb - 7;
			initTNLopOff = false;
		}
		if(noWord)
		{
			noWordCounterb++;
			if(noWordCounterb==2)
			{
				randomizeBotHand = true;
				noWordCounterb = 0;
			}
		}
		quitCheckWordListLoop = false;
		GetBotRightSide=false, GetBotDownSide=false;
		noWord = false;
		botPass = false;
		firstWordIsFromBot = false;
		noWordCounter=0;
		newBotScore=0;
		roll=0;
		horizontalBotFirst=0, horizontalBotLast=0, verticalBotFirst=0, verticalBotLast = 0;
		BotHand.clear();
		BotHandb.clear();
		BotHandc.clear();
		BotHandTransf.clear();
		BotHandChars.clear();
		TransitHand.clear();
		WordsFound.clear();
		LopOffPT();
	}
}

void CTiles::botDownSideNormal()
{
	InitBotHand(tiles[RandomizedOnDeckForeva.at(0)]->GetLetter());
	BotHandb = BotHand;
	string builtChars(BotHandChars.begin(), BotHandChars.end());
	TransitHand.push_back(builtChars);
	for(int i=0;i<63;i++)
	{
		quitCheckWordListLoop = false;
		while(!quitCheckWordListLoop)
		{
			random_shuffle(BotHandChars.begin(), BotHandChars.end());
			string builtChars(BotHandChars.begin(), BotHandChars.end());
			if(!IsInTheVector(builtChars, TransitHand))
			{
				TransitHand.push_back(builtChars);
				quitCheckWordListLoop = true;
			}
		}
	}
	findwords(TransitHand, WordsFound, tiles[RandomizedOnDeckForeva.at(0)]->GetLetter());
	random_shuffle(WordsFound.begin(), WordsFound.end());
	if(WordsFound.size()>0)
	{
		for(size_t w=0, size=WordsFound.size();w<size;w++)
		{
			if(WordsFound.at(w).size()-1 < (size_t)botDownSideMax)
			{
				cout<<"Word found : "<<WordsFound.at(w)<<endl;
				for(size_t l=1, sizea=WordsFound.at(w).size() ;l<sizea;l++)
				{
					for(size_t n=0, sizem=BotHand.size();n<sizem;n++)//was n=1 and n<=sizem super sh*ty caused the oor error
					{
						if(WordsFound.at(w).at(l)==tiles[BotHand.at(n)]->GetLetter()&&!Deck[botPillarSearch+l][botRowSearch]->GetOccupied()&&!IsInTheVectorb(BotHand.at(n), BotHandTransf))//if things goes wrong, make a vector to reorder BotHand
						{
							tiles[BotHand.at(n)]->SetPosition(Deck[botPillarSearch+l][botRowSearch]->GetX(),Deck[botPillarSearch+l][botRowSearch]->GetY());
							tiles[BotHand.at(n)]->SetisOndeck(true);
							cout<<"BotHand.at(n) : "<<BotHand.at(n)<<endl;
							Deck[botPillarSearch+l][botRowSearch]->SetLetterCoefficient(tiles[BotHand.at(n)]->GetPoints());
							Deck[botPillarSearch+l][botRowSearch]->SetLetter(tiles[BotHand.at(n)]->GetLetter());
							Deck[botPillarSearch+l][botRowSearch]->SetOccupied(true);
							Deck[botPillarSearch+l][botRowSearch]->SetTileId(BotHand.at(n));
							OnDeckForeva.push_back(BotHand.at(n));
							BotHandTransf.push_back(BotHand.at(n));
							break;
						}
					}
				}
			}
			break;
		}
		verticalBotFirst = botPillarSearch;
		verticalBotLast = verticalBotFirst+WordsFound.at(0).size()-1;
		horizontalBotFirst = botRowSearch;
	}
}

void CTiles::botRightSideNormal()
{
	InitBotHand(tiles[RandomizedOnDeckForeva.at(0)]->GetLetter());
	BotHandb = BotHand;
	string builtChars(BotHandChars.begin(), BotHandChars.end());
	TransitHand.push_back(builtChars);
	for(int j=0;j<63;j++)
	{
		quitCheckWordListLoop = false;
		while(!quitCheckWordListLoop)
		{
			random_shuffle(BotHandChars.begin(), BotHandChars.end());
			string builtChars(BotHandChars.begin(), BotHandChars.end());
			if(!IsInTheVector(builtChars, TransitHand))
			{
				TransitHand.push_back(builtChars);
				quitCheckWordListLoop = true;
			}
		}
	}
	findwords(TransitHand, WordsFound, tiles[RandomizedOnDeckForeva.at(0)]->GetLetter());
	random_shuffle(WordsFound.begin(), WordsFound.end());
	if(WordsFound.size()>0)
	{
		for(size_t v=0, size=WordsFound.size();v<size;v++)
		{
			if(WordsFound.at(v).size()-1 < (size_t)botRightSideMax)
			{
				cout<<"Word found : "<<WordsFound.at(v)<<endl;
				for(size_t m=1, sizeb=WordsFound.at(v).size();m<sizeb;m++)
				{
					for(size_t o=0, sizen=BotHand.size();o<sizen;o++)
					{
						if(WordsFound.at(v).at(m)==tiles[BotHand.at(o)]->GetLetter()&&!Deck[botPillarSearch][botRowSearch+m]->GetOccupied()&&!IsInTheVectorb(BotHand.at(o), BotHandTransf))
						{
							tiles[BotHand.at(o)]->SetPosition(Deck[botPillarSearch][botRowSearch+m]->GetX(),Deck[botPillarSearch][botRowSearch+m]->GetY());
							tiles[BotHand.at(o)]->SetisOndeck(true);
							Deck[botPillarSearch][botRowSearch+m]->SetLetterCoefficient(tiles[BotHand.at(o)]->GetPoints());
							Deck[botPillarSearch][botRowSearch+m]->SetLetter(tiles[BotHand.at(o)]->GetLetter());
							Deck[botPillarSearch][botRowSearch+m]->SetOccupied(true);
							Deck[botPillarSearch][botRowSearch+m]->SetTileId(BotHand.at(o));
							OnDeckForeva.push_back(BotHand.at(o));
							BotHandTransf.push_back(BotHand.at(o));
							break;
						}
					}
				}
			}
			break;
		}
		horizontalBotFirst = botRowSearch;
		horizontalBotLast = horizontalBotFirst+WordsFound.at(0).size()-1;
		verticalBotFirst = botPillarSearch;
	}
}

void CTiles::FirstWordIsFromBot()
{
	for(int i=0; i<7;i++)
	{
		randTileNbFound = true;
		while(randTileNbFound)
		{
			randTileNb = GetAvailableTile(TilesNumber);
			if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!IsInTheVectorb(randTileNb, keepBotHand)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
			{
				TilesNumber.at(randTileNb)=true;
				//tileNumberb--;
				BotHand.push_back(randTileNb);
				BotHandChars.push_back(tiles[BotHand.at(i)]->GetLetter());
				randTileNbFound = false;
			}
		}
	}
	string builtChars(BotHandChars.begin(), BotHandChars.end());
	TransitHand.push_back(builtChars);
	for(int j=0;j<49;j++)
	{
		quitCheckWordListLoop = false;
		while(!quitCheckWordListLoop)
		{
			random_shuffle(BotHandChars.begin(), BotHandChars.end());
			string builtChars(BotHandChars.begin(), BotHandChars.end());
			if(!IsInTheVector(builtChars, TransitHand))
			{
				TransitHand.push_back(builtChars);
				quitCheckWordListLoop = true;
			}
		}
	}
	findword(TransitHand, WordsFound);
	random_shuffle(WordsFound.begin(), WordsFound.end());
	cout<<"Word found : "<<WordsFound.at(0)<<endl;
	if(WordsFound.size()>0)
	{
		for(size_t m=0, sizeb=WordsFound.at(0).size();m<sizeb;m++)
		{
			for(size_t o=0, sizen=BotHand.size();o<sizen;o++)
			{
				if(WordsFound.at(0).at(m)==tiles[BotHand.at(o)]->GetLetter()&&!IsInTheVectorb(BotHand.at(o), BotHandTransf))//might needs to check if a letter is already sorted out
				{
					tiles[BotHand.at(o)]->SetPosition(Deck[7][7+m]->GetX(),Deck[7][7+m]->GetY());
					tiles[BotHand.at(o)]->SetisOndeck(true);
					Deck[7][7+m]->SetLetterCoefficient(tiles[BotHand.at(o)]->GetPoints());
					Deck[7][7+m]->SetLetter(tiles[BotHand.at(o)]->GetLetter());
					Deck[7][7+m]->SetOccupied(true);
					Deck[7][7+m]->SetTileId(BotHand.at(o));
					OnDeckForeva.push_back(BotHand.at(o));
					BotHandb.push_back(BotHand.at(o));
					BotHandTransf.push_back(BotHand.at(o));
					break;
				}
			}
		}
	}
	horizontalBotFirst = 7;
	horizontalBotLast = 7+WordsFound.at(0).size();
	verticalBotFirst = 7;
	SetNewBotScore();
	botScoreb = botScoreb + newBotScore;
	for(size_t q=0, sized = BotHandb.size(); q<sized; q++) 
	{
		it = find(BotHand.begin(), BotHand.end(), BotHandb.at(q));
		if(it != BotHand.end())
		{
			BotHand.erase(it);
		}
		else if(it == BotHand.end())
		{
			BotHand.pop_back();
		}
	}
	keepBotHand = BotHand;
	tileNumberb = tileNumberb - 7;
	initBotHand = false;
}

void CTiles::GetDeckPillarAndRow(int passed_witchPict)
{
	botPillarSearch=0, botRowSearch = 0;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(Deck[i][j]->GetTileId()==passed_witchPict)
			{
				botPillarSearch = i;
				botRowSearch = j;
			}
		}
	}
}

bool CTiles::GetBotUpSideMax()
{
	botUpSideMax = 0;
	if(!Deck[botPillarSearch-1][botRowSearch]->GetOccupied()&&!Deck[botPillarSearch+1][botPillarSearch]->GetOccupied())//&&!Deck[botPillarSearch+1][botPillarSearch]->GetOccupied()
	{
		for(int k=1;k<16;k++)
		{
			if(botPillarSearch+k>14)
			{
				break;
			}
			else if(Deck[botPillarSearch-k][botRowSearch]->GetOccupied())
			{
				break;
			}
			else if(!Deck[botPillarSearch-k][botRowSearch]->GetOccupied())
			{
				botUpSideMax++;
			}
		}
		if(botPillarSearch-botDownSideMax==14)
		{
			botUpSideMax++;
		}
		botUpSideMax--;
		GetBotUpSide = true;
	}
	return GetBotUpSide;
}

bool CTiles::GetBotDownSideMax()
{
	botDownSideMax = 0;
	if(!Deck[botPillarSearch-1][botRowSearch]->GetOccupied()&&!Deck[botPillarSearch+1][botPillarSearch]->GetOccupied())//&&!Deck[botPillarSearch+1][botPillarSearch]->GetOccupied()
	{
		for(int k=1;k<16;k++)
		{
			if(botPillarSearch+k>14)
			{
				break;
			}
			else if(Deck[botPillarSearch+k][botRowSearch]->GetOccupied())
			{
				break;
			}
			else if(!Deck[botPillarSearch+k][botRowSearch]->GetOccupied())
			{
				botDownSideMax++;
			}
		}
		if(botPillarSearch+botDownSideMax==14)
		{
			botDownSideMax++;
		}
		botDownSideMax--;//minus 1 case, don't want it to be stacked against an other word, not used yet anyway
		GetBotDownSide = true;
	}
	return GetBotDownSide;
}

bool CTiles::GetBotRightSideMax()
{
	botRightSideMax = 0;
	if(!Deck[botPillarSearch][botRowSearch-1]->GetOccupied()&&!Deck[botPillarSearch][botRowSearch+1]->GetOccupied())
	{
		for(int k=1;k<16;k++)
		{
			if(botRowSearch+k>14)
			{
				break;
			}
			else if(Deck[botPillarSearch][botRowSearch+k]->GetOccupied())
			{
				break;
			}
			else if(!Deck[botPillarSearch][botRowSearch+k]->GetOccupied())
			{
				botRightSideMax++;
			}
		}
		if(botRowSearch+botRightSideMax==14)
		{
			botRightSideMax++;
		}
		botRightSideMax--;
		GetBotRightSide = true;
	}
	return GetBotRightSide;
}

bool CTiles::GetBotLeftSideMax()
{
	botLeftSideMax = 0;
	if(!Deck[botPillarSearch][botRowSearch-1]->GetOccupied()&&!Deck[botPillarSearch][botRowSearch+1]->GetOccupied())
	{
		for(int k=1;k<16;k++)
		{
			if(botRowSearch+k>14)
			{
				break;
			}
			else if(Deck[botPillarSearch][botRowSearch-k]->GetOccupied())
			{
				break;
			}
			else if(!Deck[botPillarSearch][botRowSearch-k]->GetOccupied())
			{
				botLeftSideMax++;
			}
		}
		if(botRowSearch+botRightSideMax==14)
		{
			botLeftSideMax++;
		}
		botLeftSideMax--;
		GetBotLeftSide = true;
	}
	return GetBotLeftSide;
}

bool CTiles::IsInTheVector(string passed_word, vector<string>& passed_vector)
{
	isInTheVector=false;
	for(size_t i=0, size=passed_vector.size(); i<size; ++i) 
	{
		if(passed_vector.at(i)==passed_word)
		{
			isInTheVector = true;
			break;
		}
	}
	return isInTheVector;
}

bool CTiles::IsInTheVectorb(int passed_id, vector<int>& passed_vector)
{
	isInTheVectorb=false;
	for(size_t i=0, size=passed_vector.size(); i<size; ++i) 
	{
		if(passed_vector.at(i)==passed_id)
		{
			isInTheVectorb = true;
			break;
		}
	}
	return isInTheVectorb;
}

void CTiles::findwords(vector<string>& passed_TransitHand, vector<string>& passed_WordsFound, char passed_letter)
{
	bool passed_initVector = true;
	ifstream file(dictionaryPath, ios::in);
	if(file&&passed_TransitHand.size()>0)
	{       
		string botTestChain;		
		while(! file.eof())
		{
			file>>botTestChain;
			for(size_t i=0, size=passed_TransitHand.size(); i<size; ++i)
			{
				botJocker[0] = false;
				botJocker[1] = false;
				botJockerPos[0] = 0;
				botJockerPos[1] = 0;
				botWordCopy = passed_TransitHand.at(i);
				for(int j=0;j<2;j++)
				{
					found = botWordCopy.find('_');
					if(botWordCopy.find('_') != std::string::npos)
					{
						botJocker[j]=true;
						botJockerPos[j]=found;
						botWordCopy.erase(found, 1);
					}
				}
				if(botJocker[0]&&!botJocker[1]&&!IsInTheVector(botTestChain, passed_WordsFound)&&(botTestChain.at(0)==passed_letter)&&botTestChain.size()>1)
				{
					if(botTestChain.size()==passed_TransitHand.at(i).size())
					{
						botTestChain.erase(jockerPos[0], 1);
						if(botTestChain.compare(botWordCopy) == 0)
						{
							passed_WordsFound.push_back(botTestChain);
						}
					}
				}
				else if(botJocker[0]&&botJocker[1]&&!IsInTheVector(botTestChain, passed_WordsFound)&&(botTestChain.at(0)==passed_letter)&&botTestChain.size()>1)
				{
					if(botTestChain.size()==passed_TransitHand.at(i).size())
					{
						botTestChain.erase(jockerPos[0], 1);
						botTestChain.erase(jockerPos[1], 1);
						if(botTestChain.compare(botWordCopy) == 0)
						{
							passed_WordsFound.push_back(botTestChain);
						}
					}
				}
				else if((botTestChain.at(0)==passed_letter)&&botTestChain.size()>1 && passed_TransitHand.at(i).find(botTestChain) != string::npos && botTestChain!="i" && botTestChain!="a")//&&testChain.size()>2 //&& !passed_initVector 
				{
					if(!IsInTheVector(botTestChain, passed_WordsFound))
					{
						passed_WordsFound.push_back(botTestChain);
					}
				}
			}
		}
		file.close();
	}
	else
	{
		cerr << "Can't open the file !" << endl;
	}
}

void CTiles::findword(vector<string>& passed_TransitHand, vector<string>& passed_WordsFound)
{
	ifstream file(dictionaryPath, ios::in);
	if(file)
	{       
		string testChain;		
		while(! file.eof())
		{
			file>>testChain;
			for(size_t i=0, size=passed_TransitHand.size(); i<size; ++i)
			{

				if(testChain!="a" && testChain!="i" && passed_TransitHand.at(i).find(testChain) != string::npos)
				{
					if(!IsInTheVector(testChain, passed_WordsFound))
					{
						passed_WordsFound.push_back(testChain);
					}
				}
			}
		}
		file.close();
	}
	else
	{
		cerr << "Can't open the file !" << endl;
	}
}

void CTiles::InitBotHand(char passed_letter)
{
	BotHandChars.push_back(passed_letter);
	if(tileNumberb>7)
	{
		if(!initBotHand && !randomizeBotHand)
		{
			BotHand = keepBotHand;
			for(size_t k=0, size = BotHand.size(); k<size;k++)
			{
				BotHandChars.push_back(tiles[BotHand.at(k)]->GetLetter());
			}
			for(size_t j=0, sizen = 7-BotHand.size(); j<sizen;j++)
			{
				randTileNbFound = true;
				while(randTileNbFound)
				{
					randTileNb = GetAvailableTile(TilesNumber);
					if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!IsInTheVectorb(randTileNb, keepBotHand)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
					{
						TilesNumber.at(randTileNb)=true;
						//tileNumberb--;
						BotHand.push_back(randTileNb);
						BotHandChars.push_back(tiles[BotHand.at(j)]->GetLetter());
						randTileNbFound = false;
					}
				}
			}
			randomizeBotHand = true;//randomize botHand once every 2 round
			keepBotHand.clear();
		}
		else if(!initBotHand && randomizeBotHand)
		{
			for(size_t k=0, size = keepBotHand.size(); k<size;k++)
			{
				TilesNumber.at(keepBotHand.at(k))=false;
			}
			for(int j=0;j<7;j++)
			{
				randTileNbFound = true;
				while(randTileNbFound)
				{
					randTileNb = GetAvailableTile(TilesNumber);
					if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
					{
						TilesNumber.at(randTileNb)=true;
						BotHand.push_back(randTileNb);
						BotHandChars.push_back(tiles[BotHand.at(j)]->GetLetter());
						randTileNbFound = false;
					}
				}
			}
			cout<<"randomized botHand. "<<endl;
			keepBotHand.clear();
			randomizeBotHand = false;
		}
		else if(initBotHand)
		{
			for(int i=0; i<7;i++)
			{
				randTileNbFound = true;
				while(randTileNbFound)
				{
					randTileNb = GetAvailableTile(TilesNumber);
					if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!IsInTheVectorb(randTileNb, keepBotHand)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
					{
						TilesNumber.at(randTileNb)=true;
						//tileNumberb--;
						BotHand.push_back(randTileNb);
						BotHandChars.push_back(tiles[BotHand.at(i)]->GetLetter());
						randTileNbFound = false;
					}
				}
			}
			initBotHand = false;
		}
	}
	else if(tileNumberb<7)
	{
		tileNumberb = 0;
	}
}

void CTiles::forceBotHandRandomization()
{
	for(size_t k=0, size = keepBotHand.size(); k<size;k++)
	{
		TilesNumber.at(keepBotHand.at(k))=false;
	}
	keepBotHand.clear();
	for(int j=0;j<7;j++)
	{
		randTileNbFound = true;
		while(randTileNbFound)
		{
			randTileNb = GetAvailableTile(TilesNumber);
			if(!IsInTheVectorb(randTileNb, OnDeck)&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, OnDeckForeva)&&!tiles[randTileNb]->GetisOndeck()&&!IsInTheVectorb(randTileNb, Hand)&&!IsInTheVectorb(randTileNb, Swap))
			{
				TilesNumber.at(randTileNb)=true;
				keepBotHand.push_back(randTileNb);
				randTileNbFound = false;
			}
		}
	}
	cout<<"forced botHand randomization. "<<endl;
}

void CTiles::SetNewBotScore()
{
	newBotScore = 0;
	if(horizontalBotFirst>0&&horizontalBotLast>0)
	{
		for(int i=horizontalBotFirst; i<=horizontalBotLast; i++)
		{
			newBotScore =  newBotScore + Deck[verticalBotFirst][i]->GetLetterCoefficient();
		}
		for(int j=horizontalBotFirst; j<=horizontalBotLast; j++)
		{
			switch(Deck[verticalBotFirst][j]->GetCaseCoefficient())
			{
			case 0:
				break;
			case 1:
				newBotScore =  newBotScore - Deck[verticalBotFirst][j]->GetLetterCoefficient();
				newBotScore =  newBotScore + (Deck[verticalBotFirst][j]->GetLetterCoefficient() * 2);
				break;
			case 2:
				newBotScore =  newBotScore - Deck[verticalBotFirst][j]->GetLetterCoefficient();
				newBotScore =  newBotScore + (Deck[verticalBotFirst][j]->GetLetterCoefficient() * 3);
				break;
			case 3:
				newBotScore = newBotScore*2;
				break;
			case 4:
				newBotScore = newBotScore*3;
				break;
			default:
				break;
			}
		}
	}
	else if(verticalBotFirst>0&&verticalBotLast>0)
	{
		for(int k=verticalBotFirst; k<=verticalBotLast; k++)
		{
			newBotScore =  newBotScore + Deck[k][horizontalBotFirst]->GetLetterCoefficient();
		}
		for(int l=verticalBotFirst; l<=verticalBotLast; l++)
		{
			switch(Deck[l][horizontalBotFirst]->GetCaseCoefficient())
			{
			case 0:
				break;
			case 1:
				newBotScore =  newBotScore - Deck[l][horizontalBotFirst]->GetLetterCoefficient();
				newBotScore =  newBotScore + (Deck[l][horizontalBotFirst]->GetLetterCoefficient() * 2);
				break;
			case 2:
				newBotScore =  newBotScore - Deck[l][horizontalBotFirst]->GetLetterCoefficient();
				newBotScore =  newBotScore + (Deck[l][horizontalBotFirst]->GetLetterCoefficient() * 3);
				break;
			case 3:
				newBotScore = newBotScore*2;
				break;
			case 4:
				newBotScore = newBotScore*3;
				break;
			default:
				break;
			}
		}
	}
}