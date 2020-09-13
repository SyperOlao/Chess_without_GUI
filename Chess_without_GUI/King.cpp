#include "King.h"

bool King::CheckMove(int x, int y){
	return ::ChessFigure::CheckMove(x, y) &&
		(abs(x - coord->x) == 1 && abs(y - coord->y) == 1 || 
			(abs(coord->x - x) == 0 || abs(coord->y - y) == 0&&(abs(x - coord->x) == 1 ||
				abs(y - coord->y) == 1)));
}

bool King::IsOnAWay(int x, int y)
{
	return false;
}

void King::Move(int x, int y){
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
		Desk::AddFig(x, y, kg);
	}
}

King::King() :ChessFigure() {
	weight = 10;
	name = "King"; 
}

King::King(int x, int y, bool color){
	kg = new King();
	coord->x = x;
	coord->y = y;
	this->color = color;
	kg->color = color;
	Desk::AddFig(x, y, kg); 
}
