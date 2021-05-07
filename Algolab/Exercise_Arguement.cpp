#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
    int n= atoi(argv[1]);
    srand(n);
    for (int i=0;i<10;i++){
        int dice = rand()%6 + 1;
        cout<<dice<<" ";
    }
    cout<<endl;
}