#include<iostream>

using namespace std;

class Kvector{
    int *m;
public:
    Kvector(int sz=0){
        cout << this << " : Kvector(int) called\n";
        if(sz>0) m=new int[sz];
        else m=NULL;
    }
    ~Kvector(){
        cout << this << " : Kvector() called\n";
        delete[] m;
    }
    int *getM(){
        return m;
    }
};
Kvector v2(2);
int main(){
    Kvector v1;
    cout << v1.getM() << endl;
    cout << v2.getM() << endl;
    return 0;
}