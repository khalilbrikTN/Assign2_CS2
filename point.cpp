#include <iostream>
#include <string>
#include <cmath>

#include "point.h"

using namespace std;

point::point()
{
    x = 0;
    y = 0;
};

point::point(float a, float b)
{
    x = a;
    y = b;
};

void point::Set_X(float a)
{
    x = a;
};
void point::Set_Y(float b)
{
    y = b;
};

float point::Get_X() { return x; };
float point::Get_Y() { return y; };

string point::Display()
{
    string result = "(" + to_string(x) + "," + to_string(y) + ")";
    return result;
};
float point::distance(point p)
{
    float p_x = p.Get_X(); // x of the new point p
    float p_y = p.Get_Y(); // y of the new point p
    float D;               // the distance between the current point and point p
    D = sqrt(pow((p_x - x), 2) + pow((p_y - y), 2));
    return D;
};