#include<iostream>

using namespace std;

int Triangle(int x,int y,int z);

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << Triangle(a,b,c);

}

int Triangle(int x, int y, int z)
{
    if(x>=y+z||y>=x+z||z>=x+y) return 0;
    else if(x==y&&y==z) return 1;
    else if(x==y ||x==z ||y==z)
        if(x==y&&y==z) return 1;
        else return 3;
    else if(x*x+y*y==z*z) return 2;
    else return 4;
    
}