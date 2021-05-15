#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    unsigned long x; int a; int b; int c; int y;
    cin >> x;
    vector<int>v;
    while(x>0){
        a=x%10;
        x/=10;
        v.push_back(a);
    }
    // for(int i=0;i<v.size();i++){
    //     cout <<v[i]<<" ";
    // }
    // cout << endl;
    y=v[0];
    
    v.erase(v.begin()+0);
    for(int i=0;i<v.size();i++){
        if(i%2==0){
            if(v[i]*2<10) v[i]=v[i]*2;
            else{
                v[i]=(v[i]*2)-9;
            }
        }
        
    }
    // for(int i=0;i<v.size();i++){
    //     cout <<v[i]<< " ";
    // }
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }
    // cout << sum<<endl;
    int p=v[v.size()];//카드 발행 회사
    if(p==3&&(v.size()+1==15||v.size()+1==14)){
        if((sum+y)%10==0) cout <<1;
        else cout <<0;
    } 
    else if((p==6||p==5)&&v.size()+1==16){
        if((sum+y)%10==0) cout <<1;
        else cout <<0;
    }
    else if(p==4&&(v.size()+1==13||v.size()+1==16)){
        if((sum+y)%10==0) cout <<1;
        else cout <<0;
    }
    else cout <<0;

}    