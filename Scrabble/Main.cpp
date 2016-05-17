#include "StdAfx.h"
#include "Main.h"
using namespace std;


CMain::CMain(int passed_ScreenWidth, int passed_ScreenHeight)
{
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHeight;
	MouseX, MouseY= 0;
	clickSel, clickSwapSel = 0;
	dictionaryresponce = 0;
	quit = false;
	onlyOne= true;
	initHand = true;
	quitSelLoop = false;
	SwapLoop = false;
	checkWordSl = false;
	checkCheckWordSl = false;
	blockSwap = false;
	csdl_setup = new CSDL_Setup(&quit, passed_ScreenWidth, passed_ScreenHeight);
	Deck = new CSprite(csdl_setup->GetRenderer(), "data/deck/gamedeck.png", 0, 0, 800, 600, '-', 0, 0, 0);
	Deck2 = new CSprite(csdl_setup->GetRenderer(), "data/deck/gd_plusSwap.png", 0, 0, 800, 600, '-', 0, 0, 0);
	Swap = new CSprite(csdl_setup->GetRenderer(), "data/buttons/swap.png", 633, 421, 55, 23, '-', 0, 0, 0);
	Cancel = new CSprite(csdl_setup->GetRenderer(), "data/buttons/cancel.png", 702, 421, 57, 23, '-', 0, 0, 0);
	Pass = new CSprite(csdl_setup->GetRenderer(), "data/buttons/pass.png", 633, 457, 55, 23, '-', 0, 0, 0);
	Undo = new CSprite(csdl_setup->GetRenderer(), "data/buttons/undo.png", 633, 457, 55, 23, '-', 0, 0, 0);
	Play = new CSprite(csdl_setup->GetRenderer(), "data/buttons/play.png", 702, 457, 57, 23, '-', 0, 0, 0);
	Swap2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/swap2.png", 633, 421, 55, 23, '-', 0, 0, 0);
	Cancel2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/cancel2.png", 702, 421, 57, 23, '-', 0, 0, 0);
	Pass2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/pass2.png", 633, 457, 55, 23, '-', 0, 0, 0);
	Undo2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/undo2.png", 633, 457, 55, 23, '-', 0, 0, 0);
	Play2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/play2.png", 702, 457, 57, 23, '-', 0, 0, 0);
	Tiles = new CTiles(&SwapLoop, &MouseX, &MouseY, csdl_setup);//bool language
	Dictionary = new CDictionary(csdl_setup, csdl_setup->GetRenderer(), "data/font/LucidaSansRegular.ttf", "Enter a word", 14, 0, 0, 0, 0, 613, 496, 0, 0);
	CheckWord = new CSprite(csdl_setup->GetRenderer(), "data/buttons/checkWord.png", 608, 532, 93, 23, '-', 0, 0, 0);
	CheckWord2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/checkWord2.png", 608, 532, 93, 23, '-', 0, 0, 0);
	Wid = new CSprite(csdl_setup->GetRenderer(), "data/buttons/wid.png", 608, 569, 166, 18, '-', 0, 0, 0);
	Wind = new CSprite(csdl_setup->GetRenderer(), "data/buttons/wind.png", 608, 569, 184, 16, '-', 0, 0, 0);
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete Deck;
	delete Deck2;
	delete Swap;
	delete Cancel;
	delete Pass;
	delete Undo;
	delete Play;
	delete Swap2;
	delete Cancel2;
	delete Pass2;
	delete Undo2;
	delete Play2;
	delete CheckWord;
	delete CheckWord2;
	delete Wid;
	delete Wind;
	delete Tiles;
}

void CMain::GameLoop()
{
	while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		quitSelLoop = false;
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);
		Deck->Draw();
		if(Tiles->GetPlay())
		{
			if(!blockSwap)
			{
				Swap->Draw();
			}
			Undo->Draw();
			Play->Draw();
		}
		else if(!Tiles->GetPlay())
		{
			if(!blockSwap)
			{
				Swap->Draw();
			}
			Pass->Draw();
		}
		CheckWord->Draw();
		DictionaryCheck();
		Tiles->SetSwapOn(false);
		Tiles->PictClicked();
		Tiles->DrawBack();
		SelPoffLoff();
		if(SwapLoop)
		{
			while (!quit && SwapLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck2->Draw();
				Swap->Draw();
				Cancel->Draw();
				CheckWord->Draw();
				DictionaryCheck();
				Tiles->PictClicked();
				Tiles->DrawBack();
				SelPoffLon();
			}
		}
		//csdl_setup->End();
	}
}

void CMain::SelPoffLoff()
{
	if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN && csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
	{
		switch(CheckSel())
		{
		case 0:
			//cout<<"No button clicked. "<<endl;
			/*SDL_GetMouseState(&MouseX, &MouseY);
			cout<<"MouseX : "<<MouseX<<endl;
			cout<<"MouseY : "<<MouseY<<endl;
			SDL_Delay(500);*/
			clickSel = 0;
			break;
		case 1:
			cout<<"Button Swap clicked. "<<endl;
			while (!quit && !quitSelLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT &&!blockSwap)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck->Draw();
				Tiles->PictClicked();
				Swap2->Draw();
				Pass->Draw();
				CheckWord->Draw();
				Dictionary->DrawText();
				DictionaryCheck();
				Tiles->DrawBack();
				Tiles->SetSwapOn(true);
				//SDL_Delay(500);
				csdl_setup->End();
				SDL_Delay(500);
				SwapLoop = true;
				quitSelLoop = true;
			}
			clickSel = 0;
			break;
		case 2:
			cout<<"Button Pass clicked. "<<endl;
			while (!quit && !quitSelLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck->Draw();
				Tiles->PictClicked();
				Swap->Draw();
				Pass2->Draw();
				CheckWord->Draw();
				Dictionary->DrawText();
				DictionaryCheck();
				Tiles->DrawBack();
				//AI->Play();
				csdl_setup->End();
				SDL_Delay(500);
				blockSwap = false;
				quitSelLoop = true;
			}
			clickSel = 0;
			break;
		case 3:
			cout<<"Button Undo clicked. "<<endl;
			while (!quit && !quitSelLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck->Draw();
				Tiles->PictClicked();
				CheckWord->Draw();
				Dictionary->DrawText();
				DictionaryCheck();
				Tiles->DrawBack();
				Swap->Draw();
				Undo2->Draw();
				Play->Draw();
				Tiles->SetPlay(false);
				Tiles->SetSwapOn(false);
				Tiles->Undo();
				csdl_setup->End();
				//SDL_Delay(500);
				quitSelLoop = true;
			}
			clickSel = 0;
			break;
		case 4:
			cout<<"Button Play clicked. "<<endl;
			while (!quit && !quitSelLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck->Draw();
				Tiles->PictClicked();
				CheckWord->Draw();
				Dictionary->DrawText();
				Tiles->Play();
				Tiles->DrawBack();
				csdl_setup->End();
				SDL_Delay(500);
				Tiles->SetSwapOn(false);
				Tiles->SetPlay(false);
				Tiles->AiPlay();
				quitSelLoop = true;
				blockSwap = false;
			}
			clickSel = 0;
			break;
		case 5:
			cout<<"Button CheckWord clicked. "<<endl;
			while (!quit && !quitSelLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck->Draw();
				Tiles->PictClicked();
				if(Tiles->GetPlay())
				{
					if(!blockSwap)
					{
						Swap->Draw();
					}
					Undo->Draw();
					Play->Draw();
				}
				else if(!Tiles->GetPlay())
				{
					if(!blockSwap)
					{
						Swap->Draw();
					}
					Pass->Draw();
				}
				CheckWord2->Draw();
				if(Dictionary->IsAWord())
				{
					Wid->Draw();
					dictionaryresponce = 1;
				}
				else
				{
					Wind->Draw();
					dictionaryresponce = 2;
				}
				Dictionary->DrawText();
				Tiles->DrawBack();
				csdl_setup->End();
				SDL_Delay(500);
				quitSelLoop = true;
			}
			clickSel = 0;
			break;

		default:
			break;
		}
	}
	csdl_setup->End();
}

void CMain::SelPoffLon()
{
	if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN && csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
	{
		switch(CheckSwapSel())
		{
		case 0:
			//cout<<"No button clicked. "<<endl;
			/*SDL_GetMouseState(&MouseX, &MouseY);
			cout<<"MouseX : "<<MouseX<<endl;
			cout<<"MouseY : "<<MouseY<<endl;
			SDL_Delay(500);*/
			clickSwapSel = 0;
			break;
		case 1:
			cout<<"Button Swap clickedety. "<<endl;
			while (!quit && SwapLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck2->Draw();
				Tiles->SetSwapOn(true);
				Tiles->PictClicked();
				Swap2->Draw();
				Cancel->Draw();
				CheckWord->Draw();
				Dictionary->DrawText();
				Tiles->DrawBack();
				Tiles->Swapy();
				csdl_setup->End();
				SDL_Delay(500);
				SwapLoop = false;
				checkWordSl = false;
				blockSwap = true;
			}
			clickSel = 0;
			break;
		case 2:
			cout<<"Button Cancel clicked. "<<endl;
			while (!quit && SwapLoop && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck2->Draw();
				Tiles->SetSwapOn(false);
				Tiles->PictClicked();
				Tiles->CancelSwap();
				Swap->Draw();
				Cancel2->Draw();
				CheckWord->Draw();
				Dictionary->DrawText();
				DictionaryCheck();
				Tiles->DrawBack();
				//Tiles->GetHand();
				csdl_setup->End();
				SDL_Delay(500);
				SwapLoop = false;
				checkWordSl = false;
				blockSwap = false;
			}
			clickSel = 0;
			break;
		case 3:
			cout<<"Button CheckWordA clicked. "<<endl;
			if(checkWordSl)
			{
				checkWordSl=false;
			}
			while (!quit && SwapLoop && !checkWordSl && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				csdl_setup->Begin();
				SDL_GetMouseState(&MouseX, &MouseY);
				Deck2->Draw();
				Tiles->SetSwapOn(false);
				Tiles->PictClicked();
				if(Tiles->GetPlay())
				{
					if(!blockSwap)
					{
						Swap->Draw();
						Cancel->Draw();
					}
					else if(!blockSwap)
					{
						Swap->Draw();
						Undo->Draw();
						Play->Draw();
					}
				}
				else if(!Tiles->GetPlay())
				{
					if(!blockSwap)
					{
						Swap->Draw();
						Cancel->Draw();
					}
				}
				CheckWord2->Draw();
				Dictionary->DrawText();
				if(Dictionary->IsAWord())
				{
					Wid->Draw();
					dictionaryresponce = 1;
				}
				else
				{
					Wind->Draw();
					dictionaryresponce = 2;
				}
				Tiles->DrawBack();
				csdl_setup->End();
				SDL_Delay(500);
				checkWordSl = true;
			}
			clickSel = 0;
			break;
		default:
			break;
		}
	}
	csdl_setup->End();
}


int CMain::CheckSel()
{
	clickSel = 0;
	SDL_GetMouseState(&MouseX, &MouseY);
	//buttons#1
	if((MouseX >= 633 && MouseX <= 688) && (MouseY >= 421 && MouseY <= 444))
	{
		clickSel = 1;//swap
	}
	else if((MouseX >= 633 && MouseX <= 688) && (MouseY >= 457 && MouseY <= 480) && !Tiles->GetPlay())
	{
		clickSel = 2;//pass
	}
	else if((MouseX >= 633 && MouseX <= 688) && (MouseY >= 457 && MouseY <= 480) && Tiles->GetPlay())
	{
		clickSel = 3;//undo
	}
	else if((MouseX >= 702 && MouseX <= 757) && (MouseY >= 457 && MouseY <= 480))
	{
		clickSel = 4;//play
	}
	else if((MouseX >= 608 && MouseX <= 701) && (MouseY >= 532 && MouseY <= 555))
	{
		clickSel = 5;//checkword
	}	
	return clickSel;
}

int CMain::CheckSwapSel()
{
	clickSwapSel = 0;
	SDL_GetMouseState(&MouseX, &MouseY);
	//buttons#2(during swap)
	if((MouseX >= 633 && MouseX <= 688) && (MouseY >= 421 && MouseY <= 444))
	{
		clickSwapSel = 1;
	}
	else if((MouseX >= 702 && MouseX <= 757) && (MouseY >= 421 && MouseY <= 444))
	{
		clickSwapSel = 2;
	}
	else if((MouseX >= 608 && MouseX <= 701) && (MouseY >= 532 && MouseY <= 555))
	{
		clickSwapSel = 3;
	}
	return clickSwapSel;
}

void CMain::DictionaryCheck()
{
	Dictionary->DrawText();
	Dictionary->cleanEditB();
	Dictionary->RetrieveWord();
	if(Dictionary->DrawCursor())
	{
		Dictionary->DrawCurzor();
	}
	if(dictionaryresponce==1)
	{
		Wid->Draw();
	}
	else if(dictionaryresponce==2)
	{
		Wind->Draw();
	}
}
