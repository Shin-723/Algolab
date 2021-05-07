#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

int Squareline(int x1,int y1,int x2,int y2, int x,int y);
int Squarezic(int x1,int y1,int x2,int y2, int x,int y);


int main()
{
    int x1,y1,x2,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x >> y;
    cout << Squareline(x1,y1,x2,y2,x,y)<< " " << Squarezic(x1,y1,x2,y2,x,y);
    
}
int Squareline(int x1,int y1,int x2,int y2, int x,int y)
{
    int line;

    if(x1<=x&&x<=x2&&y1<=y&&y<=y2) line=0;

    else if(x>x2&&y1<=y&&y<=y2)line= pow(x2-x,2);
    
    else if(x<x1&&y1<=y&&y<=y2)line= pow(x1-x,2);
    
    else if(x1<=x&&x<=x2&&y>y2)line= pow(y2-y,2);
    
    else if(x1<=x&&x<=x2&&y<y1)line= pow(y1-y,2);
   
    else if(x<x1&&y<y1)line=pow(x1-x,2)+pow(y1-y,2);
 
    else if(x<x1&&y<y2)line=pow(x1-x,2)+pow(y2-y,2);

    else if(x>x2&&y<y1)line=pow(x2-x,2)+pow(y1-y,2);

    else if(x>x2&&y>y2)line=pow(x2-x,2)+pow(y2-y,2);

    return line;


}

int Squarezic(int x1,int y1,int x2,int y2, int x,int y)
{
    int zic;
    if(x1<=x&&x<=x2&&y1<=y&&y<=y2)zic=0;
    else if(x>x2&&y1<=y&&y<=y2)zic= abs(x2-x);
    
    else if(x<x1&&y1<=y&&y<=y2)zic= abs(x1-x);
    
    else if(x1<=x&&x<=x2&&y>y2)zic= abs(y2-y);
    
    else if(x1<=x&&x<=x2&&y<y1)zic= abs(y1-y);
   
    else if(x<x1&&y<y1)zic=abs(x1-x)+abs(y1-y);

    else if(x<x1&&y<y2)zic=abs(x1-x)+abs(y2-y);

    else if(x>x2&&y<y1)zic=abs(x2-x)+abs(y1-y);

    else if(x>x2&&y>y2)zic=abs(x2-x)+abs(y2-y);

    return zic;


}
