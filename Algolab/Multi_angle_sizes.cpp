#include<iostream>
#include<cmath>

using namespace std;

void size();

int main()
{
    size();
}

void size()
{
    int n;
    cin >> n;
    int x[n]; int y[n];
    int s=0;
    int p=0;
    for(int i=0;i<n;i++) cin >>x[i]>>y[i];
    for(int j=0;j<n-1;j++)
    {
        s+=(x[j+1]+x[j])*(y[j+1]-y[j]);
    }
    s=s+((x[0]+x[n-1])*(y[0]-y[n-1]));
    if(s<0) cout << -1*s<< " -1"; 
    else cout << s << " 1";
    
}