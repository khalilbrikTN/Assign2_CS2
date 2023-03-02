#include <iostream>
#include <string>
#include <cmath>
using namespace std;



class point
{
public:
    point();
    point(float a, float b);

    void Set_X(float a);
    void Set_Y(float b);

    float Get_X();
    float Get_Y();

    string Display();
    float distance(point p);

private:
    float x;
    float y;
};