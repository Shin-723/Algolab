#include<iostream>
using namespace std;

int main()
{
    int n, num = 1;
    cin >> n;
    for(int j=0;j<n;j++)
    {
        for(int k=0;k<=j;k++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}