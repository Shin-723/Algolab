#include <iostream>
using namespace std;

int main(){
    int x1, y1, x2, y2, x3, y3, a;
    float area,area2;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    area = ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)) / 2;
    area2 = area * 2;
    if(area < 0) {
        a = -1;
        area2 *= -1;
    }else if(area > 0) a = 1;
    else a = 0;
    cout << area2 << ' ' << a << endl;
}