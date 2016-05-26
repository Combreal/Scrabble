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
	victoryCounter = 0;
	quit = false;
	onlyOne= true;
	initHand = true;
	quitSelLoop = false;
	SwapLoop = false;
	checkWordSl = false;
	checkCheckWordSl = false;
	blockSwap = false;
	victoryDrawn = false;
	changeDictionary = true;
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
	DictionaryChange = new CSprite(csdl_setup->GetRenderer(), "data/buttons/dictionary.png", 711, 532, 81, 23, '-', 0, 0, 0);
	DictionaryChange2 = new CSprite(csdl_setup->GetRenderer(), "data/buttons/dictionary2.png", 711, 532, 81, 23, '-', 0, 0, 0);
	Wid = new CSprite(csdl_setup->GetRenderer(), "data/buttons/wid.png", 608, 569, 166, 18, '-', 0, 0, 0);
	Wind = new CSprite(csdl_setup->GetRenderer(), "data/buttons/wind.png", 608, 569, 184, 16, '-', 0, 0, 0);
	pWon = new CSprite(csdl_setup->GetRenderer(), "data/deck/youWon.png", 615, 125, 167, 362, '-', 0, 0, 0);
	mWon = new CSprite(csdl_setup->GetRenderer(), "data/deck/machineWon.png", 615, 125, 167, 362, '-', 0, 0, 0);
	execo = new CSprite(csdl_setup->GetRenderer(), "data/deck/execo.png", 615, 125, 167, 362, '-', 0, 0, 0);
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
	delete DictionaryChange;
	delete DictionaryChange2;
	delete Wid;
	delete Wind;
	delete Tiles;
	delete pWon;
	delete mWon;
	delete execo;
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
		if(changeDictionary)
		{
			DictionaryChange->Draw();
		}
		DictionaryCheck();
		Tiles->SetSwapOn(false);
		Tiles->PictClicked();
		Tiles->DrawBack();
		if(Tiles->CheckDeadEnd()&&Tiles->GetPlayerScore()>Tiles->GetBotScore())
		{
			pWon->Draw();
			SDL_Delay(500);
			victoryDrawn = true;
		}
		else if(Tiles->CheckDeadEnd()&&Tiles->GetPlayerScore()<Tiles->GetBotScore())
		{
			mWon->Draw();
			SDL_Delay(500);
			victoryDrawn = true;
		}
		else if(Tiles->CheckDeadEnd()&&Tiles->GetPlayerScore()==Tiles->GetBotScore())
		{
			execo->Draw();
			csdl_setup->End();
			SDL_Delay(500);
			victoryDrawn = true;
		}
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
		if(victoryDrawn)
		{
			victoryCounter++;
		}
		if(victoryCounter==2)
		{
			quit = true;
		}
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
		case 6:
			cout<<"Button ChangeDictionary clicked. "<<endl;
			while (!quit && !quitSelLoop && changeDictionary && csdl_setup->GetMainEvent()->type != SDL_QUIT)
			{
				if(changeDictionary)
				{
					csdl_setup->Begin();
					SDL_GetMouseState(&MouseX, &MouseY);
					Deck->Draw();
					if(!Tiles->GetPlay())
					{
						if(!blockSwap)
						{
							Swap->Draw();
						}
						Pass->Draw();
					}
					Tiles->DrawBack();
					CheckWord->Draw();
					Dictionary->DrawText();
					DictionaryChange2->Draw();
					csdl_setup->End();
					SDL_Delay(500);
					//thread t1(changeDirectoryPath(), *this, arg1, arg2);
					//changeDirectoryPath();
					thread = SDL_CreateThread(TestThread, "TestThread", (void *)NULL);
					if(thread==NULL)
					{
						cout<<"SDL_CreateThread failed: "<<SDL_GetError()<<endl;
					}
					else
					{
						SDL_WaitThread(thread, &threadReturnValue);
						cout<<"Thread returned value: "<<threadReturnValue<<endl;
					}
					changeDictionary = false;
					quitSelLoop = true;
				}
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
	else if((MouseX >= 711 && MouseX <= 792) && (MouseY >= 532 && MouseY <= 555))
	{
		clickSel = 6;//changedict
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

void CMain::changeDirectoryPath()
{
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = NULL;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("Text Files\0*.txt\0Any File\0*.*\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrTitle   = TEXT("Select dictionary");
	ofn.lpstrInitialDir = L"data\\dictionary";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
	if(GetOpenFileName(&ofn))
	{
		OutputDebugString(ofn.lpstrFile);
		int cSize = WideCharToMultiByte (CP_ACP, 0, ofn.lpstrFile, wcslen(ofn.lpstrFile), NULL, 0, NULL, NULL);
		string output(static_cast<size_t>(cSize), '\0');
		WideCharToMultiByte (CP_ACP, 0, ofn.lpstrFile, wcslen(ofn.lpstrFile), reinterpret_cast<char*>(&output[0]), cSize, NULL, NULL);
		cout<<output<<endl;
		//Dictionary->SetDictionaryPath(str);
		Tiles->SetDictionaryPath(output);
	}
}

int CMain::TestThread(void *ptr)
{
	int cnt=1;
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = NULL;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("Text Files\0*.txt\0Any File\0*.*\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrTitle   = TEXT("Select dictionary");
	ofn.lpstrInitialDir = L"data\\dictionary";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
	if(GetOpenFileName(&ofn))
	{
		OutputDebugString(ofn.lpstrFile);
		int cSize = WideCharToMultiByte (CP_ACP, 0, ofn.lpstrFile, wcslen(ofn.lpstrFile), NULL, 0, NULL, NULL);
		string output(static_cast<size_t>(cSize), '\0');
		WideCharToMultiByte (CP_ACP, 0, ofn.lpstrFile, wcslen(ofn.lpstrFile), reinterpret_cast<char*>(&output[0]), cSize, NULL, NULL);
	}
    return cnt;
}
