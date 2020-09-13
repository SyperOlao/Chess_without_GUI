#pragma once
#include "ChessFigure.h"
#include "Desk.h"
//Конь
class Knight :public ChessFigure{
	Knight* kh;
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	Knight();
public:
	void Move(int x, int y) override;
	Knight(int x, int y, bool color);
};

