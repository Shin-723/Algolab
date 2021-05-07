#include<iostream>
#include<math.h>
#include<cmath>
#include<algorithm>

using namespace std;

int Triangle(int x1,int x2,int y1,int y2,int z1,int z2);
    
int main()
{
    int a1,a2,b1,b2,c1,c2;
    cin >>a1>>a2>>b1>>b2>>c1>>c2;
    cout << Triangle(a1,a2,b1,b2,c1,c2);


}
int Triangle(int x1,int x2,int y1,int y2,int z1,int z2)
{
    int a,b,c;//변의 길이 제곱
    a= pow(abs(x1-y1),2)+pow(abs(x2-y2),2);
    b= pow(abs(y1-z1),2)+pow(abs(y2-z2),2);
    c= pow(abs(x1-z1),2)+pow(abs(x2-z2),2);
    int lst[3] = {a,b,c};
    sort(lst,lst+3);
    a = lst[0];
    b = lst[1];
    c = lst[2];

    if(sqrt(a)+sqrt(b)<=sqrt(c)) return 0;
    else if(a+b==c) return 1;
    else if(a+b<c) return 2;
    else if(a+b>c) return 3;
    
    else return 0;
}