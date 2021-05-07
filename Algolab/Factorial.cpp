#include<iostream>

using namespace std;

int Re_Factorial(int n)
{
    if(n==0) return 1 ;
    else return n*(n-1);
}

int Factorial(int n)
{
    int sum = 1;
    for(int i=1;i<n+1;i++)
    {
        sum*=i ;
    }
    return sum;
}

int main()
{
    int n;
    int type;
    cout << "1.Recursive 2.Recurrance" << endl;
    cin >> type ;
    cout << "n :" ;
    cin >> n;
    if(type==1)
    {
        cout << Re_Factorial(n);
    }
    else if(type==2)
    {
        cout << Factorial(n);
    }
    else ;
    
}