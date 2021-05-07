#include<iostream>

using namespace std;

int Recur_Fibo(int n)
{
    if(n==0 ||n==1) return n;
    else return(Recur_Fibo(n-1)+Recur_Fibo(n-2));
}
int Inter_Fibo(int n)
{
    if(n==0||n==1) return n;
    else
    {
        int fn;
        int fnm1=1;
        int fnm2=0;
        for(int i=2;i<=n;i++)
        {
            fn=fnm1+fnm2;
            fnm2=fnm1;
            fnm1=fn;

        }
        return fn;
    }   
}
int main()
{
    int x,y;
    cout << "1.Recursive Fibonachi 2.Interactive Fibonachi";
    cin >> x;
    cout << "Number: ";
    cin >> y;
    if(x==1) cout << Recur_Fibo(y);
    else cout << Inter_Fibo(y);
    cout << Recur_Fibo(x);
}