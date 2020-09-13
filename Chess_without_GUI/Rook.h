#pragma once
#include "ChessFigure.h"
#include "Desk.h"
//����� (����� �����-����\������-�����)
class Rook: public ChessFigure{
	Rook *rk; 
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	Rook();
public:
	void Move(int x, int y) override; 
	Rook(int x, int y, bool color); 
};

