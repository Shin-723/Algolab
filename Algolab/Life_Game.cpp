#include<iostream>
#include<vector>

using namespace std;

void bacteria(vector<int>v,int k);
int main(){
    int n,k,x;
    vector<int>v;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >>x;
        v.push_back(x);
    }
    bacteria(v,k);
}

void bacteria(vector<int>v,int k){
    vector<int>v1(v);
    for(int i=0;i<k;i++){
        vector<int>v1(v);
        for(int j=0;j<v.size();j++){
            if(j==0){
                if(v1[j]==0){
                    if(v1[j+1]<3) v[j]=v1[j];
                    else if(v1[j+1]>3&&v1[j+1]<=7) v[j]=v1[j]+1;
                    else if(v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j];
                }
                
                else if(v1[j]==9){
                    if(v1[j+1]<3) v[j]=v1[j]-1;
                    else if(v1[j+1]>3&&v1[j+1]<=7) v[j]=v1[j];
                    else if(v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                    }

                else{
                    if(v1[j+1]<3) v[j]=v1[j]-1;
                    else if(v1[j+1]>3&&v1[j+1]<=7) v[j]=v1[j]+1;
                    else if(v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                    }
            }
            else if(j==v1.size()-1){
                if(v1[j]==0){
                    if(v1[j-1]<3) v[j]=v1[j];
                    else if(v1[j-1]>3&&v1[j-1]<=7) v[j]=v1[j]+1;
                    else if(v1[j-1]==3) v[j]=v1[j];
                    else v[j]=v1[j];
                }
                else if(v1[j]==9){
                    if(v1[j-1]<3) v[j]=v1[j]-1;
                    else if(v1[j-1]>3&&v1[j-1]<=7) v[j]=v1[j];
                    else if(v1[j-1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                }
                else{
                    if(v1[j-1]<3) v[j]=v1[j]-1;
                    else if(v1[j-1]>3&&v1[j-1]<=7) v[j]=v1[j]+1;
                    else if(v1[j-1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                }
            }
            else{
                if(v1[j]==0){
                    if(v1[j+1]+v1[j-1]<3) v[j]=v1[j];
                    else if(v1[j+1]+v1[j-1]>3&&v1[j+1]+v1[j-1]<=7) v[j]=v1[j]+1;
                    else if(v1[j-1]+v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j];
                }
                else if(v1[j]==9){
                    if(v1[j+1]+v1[j-1]<3) v[j]=v1[j]-1;
                    else if(v1[j+1]+v1[j-1]>3&&v1[j+1]+v1[j-1]<=7) v[j]=v1[j];
                    else if(v1[j-1]+v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                }
                else{
                    if(v1[j+1]+v1[j-1]<3) v[j]=v1[j]-1;
                    else if(v1[j+1]+v1[j-1]>3&&v1[j+1]+v1[j-1]<=7) v[j]=v1[j]+1;
                    else if(v1[j-1]+v1[j+1]==3) v[j]=v1[j];
                    else v[j]=v1[j]-1;
                }  
            }
        }
    }
    for(int i=0;i<v.size();i++) cout << v[i]<<" ";
}