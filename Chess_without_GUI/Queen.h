#pragma once
#include "ChessFigure.h"
#include "Desk.h"

class Queen : public ChessFigure{
	Queen* qu;
	bool CheckMove(int x, int y) override;
	bool IsOnAWay(int x, int y) override;
	Queen();
public:
	void Move(int x, int y) override;
	Queen(int x, int y, bool color);
};

