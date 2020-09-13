#pragma once
#include "ChessFigure.h"

class Desk{
	 static ChessFigure* chess_desk[8][8];
	 Desk();
public:
	static void AddFig(int x, int y, ChessFigure *fig); 
	static void RemoveFig(int x, int y);
	static ChessFigure* GetFigure(int x, int y); 
};


