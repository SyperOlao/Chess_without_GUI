#pragma once
#include "ChessFigure.h"
#include "Desk.h"
//Пешка Навального 
class Pawn : public ChessFigure{
	Pawn* pw;
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	Pawn();
public:
	void Move(int x, int y) override;
	Pawn(int x, int y, bool color);
};

