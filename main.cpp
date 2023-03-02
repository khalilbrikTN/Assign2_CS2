#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <time.h>

#include "point.h"

using namespace std;

point Center(point *C, int n); // this function returns a point representing a cluster
char Close_Cluster(point *A, int n_A, point *B, int n_B, point p);

int main()
{

    srand(time(NULL)); // seeds the rand function

    int n; // number of points in cluster A
    cout << "Could you please enter the number of points in cluster A?" << endl;
    cin >> n;
    point *A = new point[n]; // a dynamic array of n points in A
    for (int i = 0; i < n; i++)
    {
        (*(A + i)).Set_X((70 + (rand() % 20)) + (0.01 + ((rand() % 100) / 100.0))); // a float between 70 and 90 excluded will be generated and added as x to a point
    }
    for (int i = 0; i < n; i++)
    {
        (*(A + i)).Set_Y((70 + (rand() % 20)) + (0.01 + ((rand() % 100) / 100.0))); // a float between 70 and 90 excluded will be generated and added as y to a point
    }

    int m; // number of points in cluster B
    cout << "Could you please enter the number of points in cluster B?" << endl;
    cin >> m;
    point *B = new point[m]; // a dynamic array of m points in B
    for (int i = 0; i < m; i++)
    {
        (*(B + i)).Set_X((20 + (rand() % 20)) + (0.01 + ((rand() % 100) / 100.0))); // a float between 20 and 40 excluded will be generated and added as x to a point
    }

    for (int i = 0; i < m; i++)
    {
        (*(B + i)).Set_Y((20 + (rand() % 20)) + (0.01 + ((rand() % 100) / 100.0))); // a float between 20 and 40 excluded will be generated and added as y to a point
    }

    int l; //the number of points p to test
    cout<<"Could you please enter the number of points to test"<<endl;
    cin>>l;

    cout << "The center of cluster A is the point with coordinates " << Center(A, n).Display() << endl;
    cout << "The center of cluster B is the point with coordinates " << Center(B, m).Display() << endl;
    cout << "-------------------------------------------------------" << endl
         << endl;
    point P; // a point P will be generated and labeled to belong to either cluster A or cluster B
    for (int i = 0; i < l; i++)
    {
        P.Set_X((5 + (rand() % 95)) + (0.01 + ((rand() % 100) / 100.0))); // an x will be generated between 5 and 100 excluded
        P.Set_Y((5 + (rand() % 95)) + (0.01 + ((rand() % 100) / 100.0))); // a y will be generated between 5 and 100 excluded
        cout << "The point P_" << i + 1 << " with coordinates" << P.Display() << " lies within cluster " << Close_Cluster(A, n, B, m, P) << endl;
    }

    return 0;
};

point Center(point *C, int n)
{
    float avg_x;     // will store the average of all the xs
    float avg_y;     /// will store the average of all the ys
    float sum_x = 0; // the sum of all the xs
    float sum_y = 0; // the sum of all the ys

    for (int i = 0; i < n; i++)
    {
        sum_x += C[i].Get_X();
        sum_y += C[i].Get_Y();
    };

    avg_x = sum_x / n; // by definition the average = total sum / number of values sumed
    avg_y = sum_y / n;

    point result(avg_x, avg_y); // creates a point center that represents the cluster
    return result;
}

char Close_Cluster(point *A, int n_A, point *B, int n_B, point p)
{

    point A_Center = Center(A, n_A); // the center of cluster A
    point B_Center = Center(B, n_B); // the center of cluster B

    float A_p = A_Center.distance(p); // the distance between p and the center of cluster A
    float B_p = B_Center.distance(p); // the distance between p and the center of cluster B

    if (A_p > B_p) // B is closer to P
    {
        return 'B';
    }
    else // A is closer to P
    {
        return 'A';
    }
}