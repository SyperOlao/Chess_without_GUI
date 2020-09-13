#pragma once
#include "ChessFigure.h"
#include "Desk.h"
//����(������� �� ��������� �����)
class Bishop : public ChessFigure{ 
    Bishop* bs;
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	Bishop(); 
public: 
	void Move(int x, int y) override;
	Bishop(int x, int y, bool color);
};

