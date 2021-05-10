#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    unsigned int x; int a; int sum=0; int checksum=0;
    vector<int>chsum;
    vector<int>v;
    vector<int>v1;
    cin >>x;
    if(x==0) cout <<0;
    else if(x==255) cout <<1;
    else{
        while(x!=0){
            a=x%2;
            v.push_back(a);
            x=x/2;
        }
    
        int i=0;
        while(i<v.size()){
            if(chsum.size()<8){
                chsum.push_back(v[i]);
            }
            else v1.push_back(v[i]);
            
            i++;
        }
        for(int j=0;j<v1.size();j++){
            
            if(j<8){
                chsum[j]=chsum[j]*pow(2,j);
                v1[j]=v1[j]*pow(2,j);
                checksum+=chsum[j];
            }
            else{
                v1[j]=v1[j]*pow(2,j%8);
            }
        }

        for(int j=0;j<v1.size();j++){
            sum+=v1[j];
        }
        while(sum>=256){
            sum-=256;
        }
        if(255-sum==checksum) cout << 1;
        else cout << 0;
    }    
}
