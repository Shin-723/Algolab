#include<iostream>

using namespace std;

int main(){
    int a,b,n,w;
    int sheep,goat,count;
    cin >>a>>b>>n>>w;
    for(int i=0;i<n;i++){
        if(a*i+b*(n-i)==w) sheep=i;
        count++;
    }
    
    if(count!=1||sheep==n||sheep==0) cout <<-1;
    else{
        goat=n-sheep;
        cout <<sheep<<" "<<goat;
        }
}