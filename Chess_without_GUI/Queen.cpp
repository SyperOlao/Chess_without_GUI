#include "Queen.h"

bool Queen::CheckMove(int x, int y){
	return ::ChessFigure::CheckMove(x, y) && (abs(coord->x - x) == abs(coord->y - y) ||
		(abs(coord->x - x) == 0 || abs(coord->y - y) == 0));
}

bool Queen::IsOnAWay(int x, int y){
	int tempX = coord->x;
	int tempY = coord->y;
	while (tempX > x + 1 && tempY > y + 1) {
		tempX--; tempY--;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX < x - 1 && tempY < y - 1) {
		tempX++; tempY++;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX > x + 1 && tempY < y - 1) {
		tempX--; tempY++;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX < x - 1 && tempY > y + 1) {
		tempX++; tempY--;
		if (Desk::GetFigure(tempX, tempY) != nullptr) return true;
	}
	while (tempX > x + 1 && tempY == y) {
		tempX--;
		if (Desk::GetFigure(tempX, y) != nullptr) return true;
	}
	while (tempX < x - 1 && tempY == y) {
		tempX++;
		if (Desk::GetFigure(tempX, y) != nullptr) return true;
	}
	while (tempY > y + 1 && tempX == x ) {
		tempY--;
		if (Desk::GetFigure(x, tempY) != nullptr) return true;
	}
	while (tempY < y - 1 && tempX == x) {
		tempY++;
		if (Desk::GetFigure(x, tempY) != nullptr) return true;
	}
	return false;
}

void Queen::Move(int x, int y){
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
			Desk::AddFig(x, y, qu);
		
	}
}

Queen::Queen() :ChessFigure() {
	name = "Queen";
	weight = 5;
}

Queen::Queen(int x, int y, bool color):Queen(){
	qu = new Queen();
	coord->x = x;
	coord->y = y;
	this->color = color;
	qu->color = color;
	Desk::AddFig(x, y, qu);
}
