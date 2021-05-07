#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Sum(vector<int>v1,vector<int>v2);
void Contraction(vector<int>v1,vector<int>v2);
void Inter(vector<int>v1,vector<int>v2);
int main(){
    int a,b,x,y;
    cin >> x;
    vector<int>v1;
    for(int i=0;i<x;i++) {
        cin >>a; 
        v1.push_back(a);
    }
    cin >> y;
    vector<int>v2;
    for(int i=0;i<y;i++){
        cin >> b;
        v2.push_back(b);
    }
    Inter(v1,v2);
    Sum(v1,v2);
    Contraction(v1,v2);
   
    
}
void Sum(vector<int>v1,vector<int>v2){
    
    vector<int>v3;
    int i = 0;
    for(;i<v1.size();i++) v3.push_back(v1[i]);
    int j = i;
    for(i =0; i< v2.size(); i++) v3.push_back(v2[i]);
    sort(v3.begin(),v3.end());
    v3.erase(unique(v3.begin(),v3.end()),v3.end());
    cout << v3.size()<<" ";
    for(int k=0;k<v3.size();k++) cout << v3[k]<<" ";
    cout << endl;
}
void Inter(vector<int>v1,vector<int>v2){
    vector<int>v3;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                v3.push_back(v1[i]);
            }
        }
    }
    sort(v3.begin(),v3.end());
    cout << v3.size()<< " ";
    for(int k=0;k<v3.size();k++) cout<<v3[k]<<" ";
    cout << endl;

}
void Contraction(vector<int>v1,vector<int>v2){
    vector<int>v3(v1);
    for(int a=0;a<v3.size();a++){
        for(int b=0;b<v1.size();b++){
            for(int c=0;c<v2.size();c++){
                if(v3[a]==v1[b]&&v3[a]==v2[c]){
                v3.erase(v3.begin()+a);
                }
            }
        }
    }
    sort(v3.begin(),v3.end());
    cout << v3.size()<<" ";
    for(int k=0;k<v3.size();k++) cout << v3[k]<<" ";
    cout << endl;
}
