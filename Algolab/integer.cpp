#include<iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    cout << a+b << " " << a-b <<" " ;
    if(a>b) cout << a-b << " ";
    else cout << b-a << " "; 
    cout << a*b << " " << a/b << " " << a%b << " ";
    if(a>=b) cout << a << " ";
    else cout << b << " ";
    if(a==b) cout << 1;
    else cout << 0;
}