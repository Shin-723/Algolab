#include<iostream>

using namespace std;

int Hotel(int H,int W,int N);

int main()
{
    int h,w,n;//h:층수 w:방수 n:n번째 손님
    cin>>h>>w>>n;
    cout << Hotel(h,w,n);
}
int Hotel(int H,int W,int N)
{
    int fstnum;
    int scdnum;
    int bang[H*W];
    int k=0;
    for(int i=0;i<W;i++)
    {
        for(int j=0;j<H;j++)
        {
            
            fstnum=j+1;
            scdnum=i+1;
            bang[k]=fstnum*100+scdnum;
            k++;
        }
    }
    return bang[N-1];    
   
}