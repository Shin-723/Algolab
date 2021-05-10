#include<iostream>

using namespace std;


int main(){
    int a, b;

    cin >> a >>b;
    int A[100] = { 0, };
    int B[100] = { 0, };
    int countA = 0, countB = 0;
    int hamcountA = 0, hamcountB = 0;
    int total = 0;
    for (int j = 32; j>0; j--)
    {
        
        A[countA]=a%2;
        a /= 2;
        if (A[countA] == 1)
            hamcountA++;
        countA++;
    }
    for (int j = 32; j>0; j--)
    {
        B[countB] = b%2;
        b /= 2;
        if (B[countB] == 1)
            hamcountB++;
        countB++;
    }
    for (int j = 0; j < countA; j++)
    {
        if (A[j] != B[j])
            total++;
    }
    cout << hamcountA << " " << hamcountB << " " << total << endl;

        
}

