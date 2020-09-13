#include "Bishop.h"

bool Bishop::CheckMove(int x, int y){
	return ::ChessFigure::CheckMove(x, y) && 
		abs(coord->x - x) == abs(coord->y - y);
}

bool Bishop::IsOnAWay(int x, int y){
	int tempX = coord->x;
	int tempY = coord->y;
	while (tempX > x+1 && tempY > y+1) {
		tempX--; tempY--;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX < x-1 && tempY < y-1) {
		tempX++; tempY++;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX > x+1 && tempY < y-1) {
		tempX--; tempY++;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX < x-1 && tempY > y+1) {
		tempX++; tempY--;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	return false;
}

void Bishop::Move(int x, int y) {
	if (CheckMove(x, y) && !IsOnAWay(x, y)) {
		if (Desk::GetFigure(x, y) != nullptr) {
			if (Desk::GetFigure(x, y)->GetColor() != color) {
				Kill(Desk::GetFigure(x, y));
				Desk::RemoveFig(x, y);
			}
			else return;
		}
			Desk::RemoveFig(coord->x, coord->y);
			coord->x = x;
			coord->y = y;
			Desk::AddFig(x, y, bs);
	}
}

Bishop::Bishop() : ChessFigure() {
	name = "Bishop";
	weight = 3;
}
Bishop::Bishop(int x, int y, bool color):Bishop(){
	bs = new Bishop();
	coord->x = x;
	coord->y = y;
	this->color = color;
	bs->color = color;
	Desk::AddFig(x, y, bs);
}
