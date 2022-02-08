#pragma once

class Vector2
{
private:

public:
    float x, y;
    Vector2(){
        x = 0;
        y = 0;
    }
    Vector2(float x, float y){
        this->x = x;
        this->y = y;
    }
    ~Vector2(){}
    Vector2 operator+(const Vector2& v) {
    this->x += v.x;
    this->y += v.y;
    }
};





