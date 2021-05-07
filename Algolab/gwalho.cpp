#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    char str[100];
    scanf("%s", str);
    int size =0;
    for(int i=0;i<100;i++){
        if ((str[i]!='(' )&&(str[i]!=')')){
            size = i;
            break;
        }
    }
    // cout<<"size: "<<size<<endl;
    int firstclose=-1;
    int firstopen=-1;
    int ans = 1;
    while(ans){
        for(int i=0;i<size;i++){
            if ((str[i]==')')&&(firstclose==-1)){
                firstclose = i;
                // cout<<"firstclose: "<<firstclose<<endl;
                for(int j=firstclose;j>=0;j--){
                    if (str[j]=='('){
                        str[j]='0';
                        // firstopen = j==firstopen?-1:firstopen;
                        str[firstclose] ='0';
                        firstclose = -1;
                        // cout<<"firstclose's open: "<<j<<endl;
                        break;
                    }if((str[j]!='(')&&(j==0)){
                        ans =0;
                    }
                }
            }
            // else if((str[i]=='(')&&(firstopen==-1)){
            //     firstopen = i;
            //     cout<<"firstopen: "<<firstopen<<endl;
            // }
        }
        if (firstclose==-1){
            for(int i=0;i<size;i++){
                if ((str[i]=='(')||(str[i]==')')){
                    ans = 0;
                }
            }
            break;
        }
    }cout<<ans;
}