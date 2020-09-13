#include "Knight.h"

bool Knight::CheckMove(int x, int y){
    return ::ChessFigure::CheckMove(x, y) &&
        (abs(coord->x - x) == 2 && abs(coord->y - y) == 1 ||
            abs(coord->x - x) == 1 && abs(coord->y - y) == 2);
}

bool Knight::IsOnAWay(int x, int y)
{
    return true;
}

void Knight::Move(int x, int y) {
    if (CheckMove(x, y)) {
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
        Desk::AddFig(x, y, kh);
    }
}

Knight::Knight() :ChessFigure() {
    weight = 2;
    name = "Knight";
}

Knight::Knight(int x, int y, bool color){
    kh = new Knight(); 
    coord->x = x; 
    coord->y = y; 
    this->color = color; 
    kh->color = color; 
    Desk::AddFig(x, y, kh);
}
