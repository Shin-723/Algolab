#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string check[20] = {"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011",
                        "1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};
string transrate(string str);
bool checkDirection(string str); //true : 왼->오, false : 오->왼
int main(){
    string input;
    cin >> input;
    string str[2];
    if (checkDirection(input.substr(3,7))){
        str[0] = input.substr(3,42);
        str[1] = input.substr(50,42);
        str[0] = transrate(str[0]);
        str[1] = transrate(str[1]);
    }else{
        reverse(input.begin(),input.end());
        str[0] = input.substr(3,42);
        str[1] = input.substr(50,42);
        str[0] = transrate(str[0]);
        str[1] = transrate(str[1]);
    }
    int ans1 = (str[0][1]-'0'+str[0][3]-'0'+str[0][5]-'0'+str[1][1]-'0'+str[1][3]-'0')+(str[0][0]-'0'+str[0][2]-'0'+str[0][4]-'0'+str[1][0]-'0'+str[1][2]-'0'+str[1][4]-'0')*3; //짝수 + 홀수*3
    int checkNum = 10-(ans1%10);
    if ((checkNum%10)==(str[1][5]-'0')){
        cout<<str[0]<<"-"<<str[1]<<endl;
    }else{
        cout<<str[0]<<"-"<<str[1]<<"*"<<(checkNum%10)<<endl;
    }
    return 0;
}
bool checkDirection(string str){
    for(int i=0;i<20;i++){
        if (check[i]==str){
            return true;
        }
    }
    return false;
}
string transrate(string str){
    string ans="";
    for(int i=0;i<42;i+=7){
        string s = str.substr(i,7);
        for(int j=0;j<20;j++){
            if (check[j]==s){
                if (j>=10){
                    ans+=to_string(j-10);
                    break;
                }else {
                    ans+=to_string(j);
                    break;
                }
            }
            
        }
    }
    return ans;
}