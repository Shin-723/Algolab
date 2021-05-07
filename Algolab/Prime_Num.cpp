#include<iostream>
#include<cmath>

using namespace std;

void sosoo();

int main()
{
    sosoo();
    return 0;
}

void sosoo()
{
    int x;
    int y=0;
    cin >> x;
    
    if(x==2) cout << 1;
    else
    {
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0){
                y=0;
                break;
                
            } 
            else y=1;
        }
        cout <<y;
    }
}
