#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

void Happy(int x);
int main(){
    int n;
    cin >> n;
    Happy(n);
}
void Happy(int x){
    vector<int>v;
    int a;
    while(x>=10){
        a=x%10;
        v.push_back(a);
        x/=10;
    }
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=pow(v[i],2);
    }
    x=pow(x,2);
    sum=sum+x;
    if(sum==1) cout << "HAPPY";
    else if(sum<10&&sum!=1) cout <<"UNHAPPY";
    else Happy(sum);
}