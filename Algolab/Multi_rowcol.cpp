#include<iostream>
using namespace std;

int main(){
    int r,s,t;
    cin>>r>>s>>t;
    int a;
    int arr1[r][s]; int arr2[s][t]; int arr3[r][t];
    for(int i=0;i<r;i++){
        for(int j=0;j<s;j++){
            cin >> a;
            arr1[i][j]=a;
        }
    }
    for(int i=0;i<s;i++){
        for(int j=0;j<t;j++){
            cin >> a;
            arr2[i][j]=a;
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<r;j++){
            int sum=0;
            for(int k=0;k<s;k++){
                sum+=arr1[j][k]*arr2[k][i];
            }
            arr3[j][i]=sum;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<t;j++){
            cout <<arr3[i][j]<< " ";
        }
        cout <<endl;
        
    }


}
