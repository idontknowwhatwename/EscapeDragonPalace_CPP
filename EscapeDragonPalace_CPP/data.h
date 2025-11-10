#pragma once
// 클래스
// 위치
class MyPoint
{
    float x;
    float y;

public:
    float getX();
    void setX(float p_x);
    float getY();
    void setY(float p_y);
};

struct Rect {
    float x;
    float y;
    float w;
    float h;

public:
    float getX();
    float getY();
    float getW();
    float getH();
};