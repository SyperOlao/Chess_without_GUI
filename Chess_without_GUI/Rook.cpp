#include "Rook.h"

bool Rook::CheckMove(int x, int y){
	return ::ChessFigure::CheckMove(x, y) &&
		abs(coord->x - x) == 0 || abs(coord->y - y) == 0;
}

void Rook::Move(int x, int y){
	if (CheckMove(x, y) && !IsOnAWay(x, y)) {
		if (Desk::GetFigure(x, y) != nullptr) {
			if (Desk::GetFigure(x, y)->GetColor() != color) {
				Kill(Desk::GetFigure(x, y)); 
				Desk::RemoveFig(x, y);
			} else return; 
		}
		Desk::RemoveFig(coord->x, coord->y);
		coord->x = x;
		coord->y = y;
		Desk::AddFig(x, y, rk);
	}
}
bool Rook::IsOnAWay(int x, int y) {
	int tempX = coord->x;
	int tempY = coord->y; 
	while (tempX > x+1) {
		tempX--;
		if (Desk::GetFigure(tempX, y) != nullptr) return true;
	}
	while (tempX < x-1) {
		tempX++;
		if (Desk::GetFigure(tempX, y) != nullptr) return true;
	}
	while (tempY > y+1) {
		tempY--;
		if (Desk::GetFigure(x, tempY) != nullptr) return true;
	}
	while (tempY < y-1) {
		tempY++;
		if (Desk::GetFigure(x, tempY) != nullptr) return true;
	}
	return false;
}

Rook::Rook():ChessFigure() {
	name = "Rook";
	weight = 3;
}

Rook::Rook(int x, int y, bool color) :Rook() {
	rk = new Rook();
	coord->x = x;
	coord->y = y;
	this->color = color; 
	rk->color = color;
	Desk::AddFig(x, y, rk); 
}





