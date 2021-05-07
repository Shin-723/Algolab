#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

void Hamming(int x);
int main(){
    int n;
    cin >> n;
    Hamming(n);
    return 0;
}
void Hamming(int x){
    int i,j,k;
    int a=0;
    int b=0;
    int arr[1350]; 
    for(i=0;i<=50;i++){
        for(j=0;j<=50;j++){
            for(k=0;k<=50;k++){
                if(pow(2,k)*pow(3,j)*pow(5,i)<=398580750){
                    arr[a]=pow(2,k)*pow(3,j)*pow(5,i);
                    a++;
                }
            }
        }
    }
    sort(arr,arr+1350); 
    cout << arr[x-1];
}