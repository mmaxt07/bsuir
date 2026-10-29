// rectangle.cpp
#include <iostream>
#include "rectangle.h"
using namespace std;
void Rectangle::getcoord()
{
    cout << "{(" << fpos.x << ", " << fpos.y << "), ("
         << spos.x << ", " << fpos.y << "), ("
         << fpos.x << ", " << spos.y << "), ("
         << spos.x << ", " << spos.y << ")}" << endl;
}
void Rectangle::drag(int rx, int ry)
{
    fpos.x += rx;
    spos.x += rx;
    fpos.y += ry;
    spos.y += ry;
}
void Rectangle::scalein(int k)
{
    if (k == 0)
        return;
    fpos.x /= k;
    spos.x /= k;
    fpos.y /= k;
    spos.y /= k;
}
void Rectangle::scaleout(int k)
{
    fpos.x *= k;
    spos.x *= k;
    fpos.y *= k;
    spos.y *= k;
}
Rectangle Rectangle::operator++()
{
    ++fpos.x;
    ++spos.x;
    ++fpos.y;
    ++spos.y;
    return *this;
}
Rectangle Rectangle::operator++(int)
{
    Rectangle res = *this;
    fpos.x++;
    spos.x++;
    fpos.y++;
    spos.y++;
    return res;
}
Rectangle Rectangle::operator--()
{
    --fpos.x;
    --spos.x;
    --fpos.y;
    --spos.y;
    return *this;
}
Rectangle Rectangle::operator--(int)
{
    Rectangle res = *this;
    fpos.x--;
    spos.x--;
    fpos.y--;
    spos.y--;
    return res;
}
Rectangle Rectangle::operator+(const Rectangle &rect)
{
    return Rectangle(
        (fpos.x < rect.fpos.x) ? fpos.x : rect.fpos.x,
        (fpos.y < rect.fpos.y) ? fpos.y : rect.fpos.y,
        (spos.x > rect.spos.x) ? spos.x : rect.spos.x,
        (spos.y > rect.spos.y) ? spos.y : rect.spos.y);
}

Rectangle Rectangle::operator+=(const Rectangle &rect)
{
    *this = *this + rect;
    return *this;
}
Rectangle Rectangle::operator-(const Rectangle &rect)
{
    return Rectangle(
        (fpos.x > rect.fpos.x) ? fpos.x : rect.fpos.x,
        (fpos.y > rect.fpos.y) ? fpos.y : rect.fpos.y,
        (spos.x < rect.spos.x) ? spos.x : rect.spos.x,
        (spos.y < rect.spos.y) ? spos.y : rect.spos.y);
}
Rectangle Rectangle::operator-=(const Rectangle &rect)
{
    *this = *this - rect;
    return *this;
}
