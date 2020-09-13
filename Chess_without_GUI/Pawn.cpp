#include "Pawn.h"
//����� �����, ������ ������
bool Pawn::CheckMove(int x, int y) {
	return ::ChessFigure::CheckMove(x, y) &&
		((color && (coord->x == x + 1 && coord->y == y ||
			abs(coord->x - x) == abs(coord->y - y) && coord->x - x == 1)) ||
			(!color && (coord->x == x - 1 && coord->y == y || 
				abs(coord->x - x) == abs(coord->y - y)&&coord->x-x==-1)));
		
	//TODO:: ��������, ���� �� 1 ���� + 2 � ����������� �� ����� 
}

bool Pawn::IsOnAWay(int x, int y){
	int tempX = coord->x;
	while (tempX < x) {
		tempX++; 
		if (Desk::GetFigure(tempX, y) != nullptr) return true;
	}
    return false;
}

void Pawn::Move(int x, int y){
	if (CheckMove(x, y) && !IsOnAWay(x, coord->y)) {
		if (Desk::GetFigure(x, y) == nullptr && abs(coord->x - x) == abs(coord->y - y)) return;
		if (Desk::GetFigure(x, y) != nullptr &&
			abs(coord->x - x) == abs(coord->y - y)) {
			if (Desk::GetFigure(x, y)->GetColor() != color) {
				Kill(Desk::GetFigure(x, y));
				Desk::RemoveFig(x, y);
			}
			else return;
		}
		Desk::RemoveFig(coord->x, coord->y);
		coord->x = x;
		coord->y = y;
		Desk::AddFig(x, y, pw);
	}
}

Pawn::Pawn() :ChessFigure() {
    name = "Pawn";
    weight = 1;
}
Pawn::Pawn(int x, int y, bool color){
	pw = new Pawn();
	coord->x = x;
	coord->y = y;
	this->color = color;
	pw->color = color;
	Desk::AddFig(x, y, pw);
}
