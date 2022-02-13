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

    bool operator==(const Vector2& v){
        if(this->x == v.x && this->y == v.y)
            return true;
        return false;
    }
    Vector2 operator+(const Vector2& v) {
        return Vector2(this->x + v.x, this->y+v.y);
    }
    Vector2 operator-(const Vector2& v) {
        return Vector2(this->x - v.x, this->y - v.y);
    }
    Vector2& operator+=(const Vector2& v) {
        this->x += v.x;
        this->y += v.y;
        return *this;
    }
    Vector2& operator-=(const Vector2& v) {
        this->x -= v.x;
        this->y -= v.y;
        return *this;
    }
};





