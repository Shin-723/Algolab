#include<iostream>

using namespace std;

int main()
{
    int k;
    cin >> k ;
    
    for ( int i = 0; i < k; i++ )
    {
        for ( int j = 0; j < i; j++)
        {
            cout << "-";
        }
        for ( int l = 0; l < k-i-1; l++ )
        {
            cout << "*+";
        }
        cout << "*";
        for ( int m = 0; m < i; m++ )
        {
            cout << "-";
        }
        
        cout << endl;
        }
    
}