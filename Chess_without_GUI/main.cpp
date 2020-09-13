#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Desk.h"

using namespace std; 
void ShowDesk();

//Белые внизу, черные вверху

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

SDL_Window* window = NULL;
SDL_Surface* screen_surface = NULL;
SDL_Surface* picture = NULL;

bool Initialization();
bool Load(); 
int Qiut();

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "ru"); 

	//Rook rook(2, 2, 0);
	//Rook rook1(2, 4, 0);
	//Rook rook2(4, 2, 1);
	//Rook rook3(2, 6, 1);
	//Bishop bishop(6, 6, 1);
	//Pawn pawn(5, 5, 0);
	//ShowDesk();
	//rook.Move(4, 2);
	//cout << "Coord X: " << rook.GetX() << endl;
	//cout << "Coord Y: " << rook.GetY() << endl;
 //    bishop.Move(2, 2);
	//pawn.Move(5, 6);
	//ShowDesk();
	//cout << "Coord X: " << bishop.GetX() << endl;
	//cout << "Coord Y: " << bishop.GetY() << endl;
	//cout << "Life rook: " << rook.GetLife();
	//Pawn pawn1(4, 4, 0);
	//Pawn pawn2(1, 1, 1);
	//Pawn pawn3(5, 4, 0);
	//Pawn pawn4(3, 3, 0);
	//ShowDesk(); 
	//pawn1.Move(5, 5);
	//pawn1.Move(6, 6);
	//pawn1.Move(5, 4);
	//pawn2.Move(0, 1);
	//cout << "Coord X1: " << pawn1.GetX() << endl;
 //   cout << "Coord Y1: " << pawn1.GetY() << endl<<endl;
	//cout << "Coord X2: " << pawn2.GetX() << endl;
	//cout << "Coord Y2: " << pawn2.GetY() << endl;
	//Queen queen1(4, 4, 1);
	//Pawn pw(3, 3, 0);
	//Knight knight1(4, 4, 1);
	//King kg(4, 4, 1);
	//ShowDesk();
	//pw.Move(4, 4);
	//cout << "Coord X: " << kg.GetX() << endl;
	//cout << "Coord Y: " << kg.GetY() << endl;
	//cout << "Life King: " << kg.GetLife() << endl; 
	//cout << kg.GetName() << endl;
	//cout << "Desk: " << Desk::GetFigure(4, 4)->GetName() << endl;
	//cout << "Desk color: " << Desk::GetFigure(4, 4)->GetColor() << endl;
	//ShowDesk();

	if (!Initialization()) 
		return 1; 
	
	if (!Load())
		return 1; 

	bool run = true; 
	SDL_Event Keyboard; 
	SDL_Rect Move; 

	int x = 0;
	int y = 0; 

	Move.x = x; 
	Move.y = y; 

	while (run) {
		while (SDL_PollEvent(&Keyboard) != 0)
		{
			if (Keyboard.type == SDL_QUIT)
				run = false;
		}

		if (Keyboard.type == SDL_KEYDOWN) {
			if (Keyboard.key.keysym.sym == SDLK_UP) {
				y -= 1;
			}
			if (Keyboard.key.keysym.sym == SDLK_DOWN) {
				y += 1;
			}
			if (Keyboard.key.keysym.sym == SDLK_RIGHT) {
				x += 1;
			}
			if (Keyboard.key.keysym.sym == SDLK_LEFT) {
				x -= 1;
			}
		}
		Move.x = x;
		Move.y = y;

		SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 217, 217, 217));

		SDL_BlitSurface(picture, NULL, screen_surface, &Move);

		SDL_UpdateWindowSurface(window);

	}

	return Qiut();
}

void ShowDesk() {
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Desk::GetFigure(i, j) == nullptr) cout << "*\t";
			else cout << "F\t";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool Initialization() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Can't initialize video: " << SDL_GetError() << endl;
		return false;
	}

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags)) {
		cout << "Can't init image: " << IMG_GetError() << endl;
		return false;
	}

	window = SDL_CreateWindow("THE BEST CHESS EVER!!", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_RESIZABLE);

	if (window == NULL) {
		cout << "Can't create window: " << SDL_GetError() << endl;
		return false;
	}

	screen_surface = SDL_GetWindowSurface(window);
	return true;
}

bool Load() {

	picture = IMG_Load("ham.png");

	if (picture == NULL) {
		cout << "Can't load: " << IMG_GetError() << endl;
		return false;
	}
	picture = SDL_ConvertSurface(picture, screen_surface->format, NULL);
	if (picture == NULL) {
		cout << "Can't convert: " << SDL_GetError() << endl;
		return false;
	}

	return true;
}

int Qiut(){
	SDL_FreeSurface(picture);
	SDL_FreeSurface(screen_surface);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	return 0;
}




