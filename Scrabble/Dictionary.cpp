#include "Dictionary.h"
using namespace std;

CDictionary::CDictionary(CSDL_Setup* passed_SDL_Setup, SDL_Renderer* passed_renderer, std::string passed_FilePath, std::string passed_Sentence, int passed_PoliceSize, Uint8 passed_r, Uint8 passed_g, Uint8 passed_b, Uint8 passed_a, int x, int y, int w, int h)
{
	csdl_setup = passed_SDL_Setup;
	renderer = passed_renderer;
	policeSize = passed_PoliceSize;
	filePath = passed_FilePath;
	sentence = passed_Sentence;
	Message = NULL;
	time = 0;
	timerb = 0;
	counta = -1;
	counter = 0;
	counterb = 0;
	MouseX = 0;
	MouseY = 0;
	renderText = false;
	lastbool = false;
	keyReleased = true;
	keyReleasedd = true;
	Cursor = false;
	cleanOnce = true;
	isAword = false;
	sameWord = false;
	Origin_X = x;
	Origin_Y = y;
	r = passed_r;
	g = passed_g;
	b = passed_b;
	a = passed_a;
	TTF_Init();
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Coudn't initialise TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	textColor.r=r;
	textColor.g=g;
	textColor.b=b;
	textColor.a=a;
	cout<<r<<g<<b<<a<<endl;
	font = TTF_OpenFont(filePath.c_str(), policeSize);
	text = TTF_RenderText_Solid(font, sentence.c_str(), textColor);
	position.x=Origin_X;
	position.y=Origin_Y;
	position.w=text->w;
	position.h=text->h;
	Message = SDL_CreateTextureFromSurface(renderer, text);
	if (Message == NULL)
	{
		cout << "Couldn't create " << filePath.c_str() << endl;
	}
	timerb = SDL_GetTicks();
}


CDictionary::~CDictionary(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	Message = NULL;
	font = NULL;
	renderer = NULL;
	TTF_Quit();
}

void CDictionary::DrawText()
{
	SDL_RenderCopy(renderer, Message, NULL, &position);
}

void CDictionary::DrawCurzor()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	for(int i=497; i<512; i++)
	{
		SDL_RenderDrawPoint(renderer, position.w+613, i );
	}
}

bool CDictionary::DrawCursor()
{
	counterb = SDL_GetTicks();
	if(counterb-timerb>300)
	{
		if((Cursor==false)&& !cleanOnce)
		{
			Cursor=true;
		}
		else
		{
			Cursor=false;
		}
		timerb = counterb;
	}
	return Cursor;
}

bool CDictionary::loadFromRenderedText(std::string textureText)
{
	if(Message!=NULL)
	{
		SDL_DestroyTexture(Message);
		Message = NULL;
		TTF_CloseFont(font);
	}
	font = TTF_OpenFont(filePath.c_str(), policeSize);
	textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if(textSurface != NULL)
	{
		Message = SDL_CreateTextureFromSurface(renderer, textSurface);
		if(Message==NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			position.x=613;
			position.y=496;
			position.w=textSurface->w;
			position.h=textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	return Message != NULL;
}

void CDictionary::RetrieveWord()
{
	time=0;
	SDL_StartTextInput();
	renderText = false;
	if(csdl_setup->GetMainEvent()->type == SDL_KEYDOWN && keyReleased)
	{
		if(csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_BACKSPACE && sentence.length() > 0)
		{
			sentence.pop_back();
			counter = SDL_GetTicks();
			renderText = true;
		}
		else if(csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL)
		{
			SDL_SetClipboardText(sentence.c_str());
		}
		else if(csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL)
		{
			sentence = SDL_GetClipboardText();
			renderText = true;
		}
		keyReleased = false;
		lastbool = true;
	}
	else if(csdl_setup->GetMainEvent()->type == SDL_TEXTINPUT && keyReleasedd)
	{
		if(!(( csdl_setup->GetMainEvent()->text.text[ 0 ] == 'c' || csdl_setup->GetMainEvent()->text.text[ 0 ] == 'C') && (csdl_setup->GetMainEvent()->text.text[ 0 ] == 'v' || csdl_setup->GetMainEvent()->text.text[ 0 ] == 'V') && SDL_GetModState() & KMOD_CTRL))
		{
			sentence += csdl_setup->GetMainEvent()->text.text;
			renderText = true;
		}
		keyReleasedd = false;
	}
	else if((csdl_setup->GetMainEvent()->type == SDL_KEYUP))
	{
		keyReleased = true;
		keyReleasedd = true;
		lastbool= false;
	}
	time = SDL_GetTicks()-counter;
	if((time==1200) && lastbool)
	{
		counta++;
		if(counta==0)
		{
			sentence = " ";
			loadFromRenderedText(" ");
			lastbool = false;
			counta=-1;
		}
	}
	if(renderText)
	{
		if(sentence != "")
		{
			loadFromRenderedText(sentence.c_str());
		}
		else
		{
			loadFromRenderedText(" ");
		}
	}
}

void CDictionary::cleanEditB()
{
	if(csdl_setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN && csdl_setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&MouseX, &MouseY);
		if((MouseX >= 609 && MouseX <= 792) && (MouseY >= 493 && MouseY <= 515) && cleanOnce)
		{
			sentence=" ";
			loadFromRenderedText(" ");
			cleanOnce=false;
		}
	}
}

bool CDictionary::IsAWord()
{
	isAword = false;
	sameWord = false;
	ifstream file("data/dictionary/dEn.txt", ios::in);
	lopSentence = sentence;
	if(lopSentence.compare(0,1," ") == 0)
	{
		lopSentence.erase(0,1);
	}
	if(file)
	{
		while(! file.eof())
		{
			file>>testChain;
			if(testChain.compare(lopSentence) == 0)
			{
				sameWord = true;
			}
		}
		if(sameWord)
		{
			cout<<"the word is in the dictionary."<<endl;
			isAword = true;
		}
		else
		{
			cout<<"The word is not in the dictionary."<<endl;
			isAword = false;
		}
		file.close();
	}
	return isAword;
}