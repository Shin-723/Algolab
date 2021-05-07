#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    vector<int> v;
    for(int i=0;i<100;i++) v.push_back(rand());
    sort(v.begin(),v.end());
    for(int i=0;i<100;i++) cout <<v[i]<<" ";
}