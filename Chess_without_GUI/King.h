#pragma once
#include "ChessFigure.h"
#include "Desk.h"

class King : public ChessFigure{
	King* kg;
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	King();
public:
	void Move(int x, int y) override;
	King(int x, int y, bool color);
};

