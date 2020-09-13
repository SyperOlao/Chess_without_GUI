#include "Desk.h"

ChessFigure* Desk::chess_desk[8][8];

ChessFigure* Desk::GetFigure(int x, int y){	
	return Desk::chess_desk[x][y];
}

Desk::Desk(){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Desk::chess_desk[i][j] = nullptr;
		}
	}
}


void Desk::AddFig(int x, int y, ChessFigure* fig){
	Desk::chess_desk[x][y] = fig;
}

void Desk::RemoveFig(int x, int y){
	if (Desk::chess_desk[x][y] != nullptr)
		Desk::chess_desk[x][y]->SetLife(false); 
	Desk::chess_desk[x][y] = nullptr;
}
