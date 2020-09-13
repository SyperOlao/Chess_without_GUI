#include "ChessFigure.h"

bool ChessFigure::CheckMove(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void ChessFigure::SetXY(int x, int y){
	if (CheckMove(x, y)) {
		coord->x = x; 
		coord->y = y; 
	}
}

void ChessFigure::SetLife(bool life){
	this->life = life; 
}

int ChessFigure::GetX(){
	return coord->x;
}

int ChessFigure::GetY()
{
	return coord->y;
}

int ChessFigure::GetWeight(){
	return weight;
}

bool ChessFigure::GetColor(){
	return color;
}

bool ChessFigure::GetLife(){
	return life;
}

std::string ChessFigure::GetName(){
	return name;
}

void ChessFigure::Kill(ChessFigure* figure){

	figure->life = false; 
	figure->SetLife(false); 
	figure->SetXY(-5, -5);
}


ChessFigure::ChessFigure(){
	name = "figure";
	life = true;
	weight = 0;
	coord->x = 0;
	coord->y = 0;
}


