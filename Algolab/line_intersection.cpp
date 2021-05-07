#include<iostream>
#include<algorithm>

using namespace std;

int Lineinter1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);
int Lineinter2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4);

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    if(x1==x2) cout << Lineinter1(x1,y1,x2,y2,x3,y3,x4,y4);
    else cout << Lineinter2(x1,y1,x2,y2,x3,y3,x4,y4);
    
}

int Lineinter1(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int type;
    int xlst[2]={x3,x4}; int ylst[2]={y1,y2};
    sort(xlst,xlst+2); sort(ylst,ylst+2);
    x3=xlst[0]; x4=xlst[1]; 
    y1=ylst[0]; y2=ylst[1];
    if((x3<=x1&&x1<=x4)&&(y1<=y3&&y3<=y2))
        {
            if((x1==x3||x1==x4)&&(y1<=y3&&y3<=y2)) type=2;
            else if((x3<=x1&&x1<=x4)&&(y1==y3||y2==y3)) type=2;
            else type=1;
        }
    else type=0;
    return type;
}
int Lineinter2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int type;
    int xlst[2]={x1,x2}; int ylst[2]={y3,y4};
    sort(xlst,xlst+2); sort(ylst,ylst+2);
    x1=xlst[0]; x2=xlst[1]; 
    y3=ylst[0]; y4=ylst[1];
    if((x1<=x3&&x3<=x2)&&(y3<=y1&&y1<=y4))
        {
            if((x3==x1||x3==x2)&&(y3<=y1&&y1<=y4)) type=2;
            else if((x1<=x3&&x3<=x2)&&(y3==y1||y4==y1)) type=2;
            else type=1;
        }
    else type=0;
    return type;
}

