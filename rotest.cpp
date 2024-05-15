#include <iostream>
#include <cmath>

using namespace std;

void rotate(int dx,int dy,double fi)
{
    double PI = 3.14;
    double length = sqrt(dx*dx+dy*dy);
    cout<<length<<endl;

    int xi = int(asin(dy/length)*180/PI);
    cout<<xi<<endl;
    
    dx=int(length*cos((xi+fi)*PI/180));
    cout<<dx<<endl;
    dy=int(length*sin((xi+fi)*PI/180));
    cout<<dy<<endl;
}

int main()
{
    rotate(0,100,0);
}