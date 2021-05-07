#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int Find_Max(int x,int y,int z)
{
    int Max = x;

    if(y>Max&&y>z) Max=y;
    else if(z>Max&&z>y) Max=z;
    else ;
    
    return Max;
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << Find_Max(a,b,c);
}