#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Max(vector<int>v);
int main(){
    int n,x;
    vector<int>v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        v.push_back(x);
    }
    cout << Max(v);
    
}
int Max(vector<int>v){
    vector<int>a; vector<int>b; vector<int>c;
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
        if(v[i]>=0) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    sort(a.begin(),a.end(),greater<int>());
    if(a.size()>3&&a[3]!=0) c.push_back(a[0]*a[1]*a[2]);
    if(a.size()>2) c.push_back(a[0]*a[1]); 
    if(a.size()>1&&b.size()>=2&&a[0]!=0) c.push_back(a[0]*b[0]*b[1]);
    else c.push_back(b[0]*b[1]);
    sort(c.begin(),c.end(),greater<int>());
    return c[0];
}
