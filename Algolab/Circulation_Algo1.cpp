#include<iostream>

using namespace std;

int ADD(int i, int j)
{
    if(i==0) return j;
    else return ADD(--i,++j);
}

int main()
{
    int a,b;

    cin >> a >> b ;

    cout << ADD(a,b);
}
