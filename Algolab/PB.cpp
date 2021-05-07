#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, mok, spare, idx=0;
    int answer = 1;
    int arr[32] ={0, };

    cin >> n;

    do {
        mok = n/2;
        spare = n%2;
        n = mok;
        arr[idx++] = spare;
    }while(mok !=0);

    int sumBit = 0;
    for(int i = 30; i >= 0; i--) {
        if(arr[i] == 1) sumBit += 1;
    }

    if(sumBit%2) arr[31] = 1;
    else arr[31] = 0;

    long sum = 0;
    for(int i = 31; i >= 0; i--) {
        if(arr[i] == 1) {
            sum += pow(2, i);
        }
    }

    cout << sum << endl;

    return 0;
}