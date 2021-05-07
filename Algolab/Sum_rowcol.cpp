#include<iostream>

using namespace std;

int main()
{
    int a,b;
    int x;
    cin >>a>>b;
    int arr1[a][b];
    int arr2[a][b];
    int arr3[a][b];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >>x;
            arr1[i][j]=x;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >>x;
            arr2[i][j]=x;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            
            cout << arr3[i][j]<<" ";
        }
        cout <<endl;
    }

}