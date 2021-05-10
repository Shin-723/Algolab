#include <iostream>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <cstdlib> 
#include <string>
using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    vector<int> P;
    int Pb[32]={0,};
    int p=0;
    string ans="";
    if (k==0){
        bitset<26> binary(n);
        string b = binary.to_string();
        P.push_back(0);
        for(int i=0;i<15;i++){
            P.push_back(b[i]-48);
        }P.push_back(0);
        for(int i=15;i<22;i++){
            P.push_back(b[i]-48);
        }P.push_back(0);
        for(int i=22;i<25;i++){
            P.push_back(b[i]-48);
        }P.push_back(0);
        P.push_back(b[25]-48);
        P.push_back(0);
        P.push_back(0);
        for(int i=1;i<30;i+=2){//P1
            if (P[i]){
                p++;
            }
        }
        P[31] = ((p%2)==0)?0:1;
        p=0;
        for(int i=1;i<30;i+=4){//P2
            p+=P[i]+P[i+1];
        }
        P[30] = ((p%2)==0)?0:1;
        p=0;
        for(int i=1;i<29;i+=8){//P4
            if((P[i]+P[i+1]+P[i+2]+P[i+3])%2){
                p+=1;
            }
        }
        P[28] = ((p%2)==0)?0:1;
        p=0;
        for(int i=1;i<25;i+=16){//P8
            for(int j=0;j<8;j++){
                p+=P[i+j];
            }
        }
        P[24] = ((p%2)==0)?0:1;
        p=0;
        for(int i=1;i<16;i++){//P16
            p+=P[i];
        }
        P[16] = ((p%2)==0)?0:1;
        p=0;
    for(int i=0;i<32;i++){
        ans.append(to_string(P[i]));
    }
    cout<<(bitset<32> (ans)).to_ulong()<<endl;
    } else{
        bitset<32> binary(n);
        string b = binary.to_string();
        for(int i=0;i<32;i++){
            p+=(b[i]-48);
        }
        if (p%2){//오류난 경우 
            int p=0;
            int err =0;
            for(int i=1;i<32;i+=2){ //P1
                if (b[i]-48){
                    p+=1;
                }
            }
            if (p%2) err+=1;
            p=0;
            for(int i=1;i<31;i+=4){ //P2
                if (((b[i]-48)+(b[i+1]-48))%2){
                    p+=1;
                }
            }
            if (p%2) err+=2;
            p=0;
            for(int i=1;i<29;i+=8){ //P4
                if (((b[i]-48)+(b[i+1]-48)+(b[i+2]-48)+(b[i+3]-48))%2){
                    p+=1;
                }
            }
            if (p%2) err+=4;
            p=0;
            for(int i=1;i<17;i+=8){ //P8
                for(int j=0;j<8;j++){
                    if ((b[i+j]-48))
                    p++;
                }
            }
            if (p%2) err+=8;
            p=0;
            for(int i=1;i<17;i++){ //P16
                if (b[i]-48)
                p++;
            }
            if (p%2) err+=16;
            b[32-err] = (b[32-err]==48)?49:48; //오류 비트 수정
            }
        for(int i=0;i<16;i++){
            ans.append(to_string(b[i]-48));
        }
        for(int i=17;i<24;i++){
            ans.append(to_string(b[i]-48));
        }
        for(int i=25;i<28;i++){
            ans.append(to_string(b[i]-48));
        }
        ans.append(to_string(b[29]-48));
        cout<<(bitset<27> (ans)).to_ulong()<<endl;
    }
}