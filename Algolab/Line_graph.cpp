#include<iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    int x = k;
    for (int i = 0; i < k; i++) {
        if (i + 1 == k / 2 + k % 2) {
            for (int j = 0; j < k; j++) {
                if (j + 1 == k / 2 + k % 2) {
                    cout << "O";
                    x--;
                } else cout << "+";
            }
        } else {
            for (int j = 0; j < k; j++) {
                if (j + 1 == x) {
                    cout << "*";
                    x--;
                } 
                else if (j + 1 == k / 2 + k % 2) cout << "I";
                else cout << ".";

            }
            

        }
        cout << endl;
    }
}