#pragma once
#include <string>

class ChessFigure{
protected:
    std::string name; 
    bool color; 
    bool life; 
    int weight; 
    struct Coordinates {
        int x; 
        int y; 
    };
    
    virtual bool CheckMove(int x, int y);
    void Kill(ChessFigure* figure);
    virtual bool IsOnAWay(int x, int y)=0; 
    Coordinates* coord = new Coordinates;
    ChessFigure* figure;  
public:
    void SetXY(int x, int y);
    void SetLife(bool life);
    int GetX(); 
    int GetY(); 
    int GetWeight(); 
    bool GetColor();
    bool GetLife();
    std::string GetName(); 
    virtual void Move(int x, int y) = 0;  
    ChessFigure(); 
};

