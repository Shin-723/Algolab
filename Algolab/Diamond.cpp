#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int j=1;
    int k=n/2;
    for(int i=0;i<n;i++)
    {
        if(i<n/2)
        {
            for(int l=0;l<k;l++)
            {
                cout << "*";
            }
            for(int l=0;l<j;l++)
            {
                cout << "+";
            }
            for(int l=0;l<k;l++)
            {
                cout << "*";
            }
            cout << endl;
            j+=2;
            k--;
        }

        else 
        {
            for(int l=0;l<k;l++)
            {
                cout << "*";
            }
            for(int l=0;l<j;l++)
            {
                cout << "+";
            }
            for(int l=0;l<k;l++)
            {
                cout << "*";
            }
            cout << endl;
            j-=2;
            k++;
        }
    }
}