#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
    int check;
    cin >> check;

    
    if(check ==1)
    {
        string A;
        int one[10] ={0} , two[10]={0} , three[10]={0} , four[10]={0} ;
        int arr[100] = {0};
        int count =0;
        int Ca=0 ,Cb=0 ,Cc=0 ,Cd=0 ;
        cin >> A;
        for(int i=0; i<16; i++)
        {
            if(A[i]=='.')
            {
                count++;
            }

            if(count == 0)
            {
                one[Ca++]= A[i]-48;
            }
            else if(count == 1)
            {
                if(A[i]!='.'){
                    two[Cb++] = A[i]-48;
                }
                
            }
            else if(count == 2)
            {
                if(A[i]!='.'){
                    three[Cc++] = A[i]-48;
                }
                
            }
            else if(count == 3)
            {
                if(A[i]!='.'&& A[i]>='0'&& A[i] <='9'){
                    four[Cd++] = A[i]-48;
                }
                
            }
            // cout << A[i] <<" ";
        }
        // cout << endl;
        unsigned int a ,b ,c ,d ;
        
        if(Ca == 1) a = one[0]; 
        if(Cb == 1) b = two[0];
        if(Cc == 1) c = three[0];
        if(Cd == 1) d = four[0];

        if(Ca == 2) a = one[0]*10 + one[1];
        if(Cb == 2) b = two[0]*10 + two[1];
        if(Cc == 2) c = three[0]*10 + three[1];
        if(Cd == 2) d = four[0]*10 + four[1];

        if(Ca == 3) a = one[0]*100 + one[1]*10 +one[2];
        if(Cb == 3) b = two[0]*100 + two[1]*10 +two[2];
        if(Cc == 3) c = three[0]*100 + three[1]*10 +three[2];
        if(Cd == 3) d = four[0]*100 + four[1]*10 +four[2];

        // cout << a <<" " << b<<" " << c <<" "<< d ;
    

        for(int i=7; i>=0; i--)
        {
            arr[i] = a%2;
            a /= 2;
        }
        for(int i=15; i>7; i--)
        {
            arr[i] = b % 2;
            b /= 2;
        }
        for(int i=23; i>15; i--)
        {
            arr[i] = c % 2;
            c /= 2;
        }
        for(int i=31; i>23; i--)
        {
            arr[i] = d % 2;
            d /= 2;
        }
        unsigned int result = 0;
        for(int i = 31; i >= 0; i--)
        {
            result += arr[i]*pow(2,31 - i);
        }
        // for(int i=0; i<32; i++){
        //     cout << arr[i] <<" ";
        // }
        // cout << endl; 

        cout << result << endl;
        
    }
    else 
    {
        unsigned int N;
        unsigned int a1=0, b1=0, c1=0, d1=0;
        int arr[100] = {0};
        cin >> N;
        for(int i=31; i>=0; i--)
        {
            arr[i] = N % 2;
            N /= 2;
            
        }

        // for(int i=0; i<32; i++)
        // {
        //     cout << arr[i] <<" ";
        // }
        // cout << endl;
        
        for(int i=7; i>=0; i--)
        {
            a1 += arr[i]* pow(2,7-i);
        }
        for(int i=15; i>7; i--)
        {
            b1 += arr[i]* pow(2,15-i);
        }
        for(int i=23; i>15; i--)
        {
            c1 += arr[i]* pow(2, 23-i);
        }
        for(int i=31; i>23; i--)
        {
            d1 += arr[i]* pow(2,31-i);
        }
        string s = to_string(a1) + '.' + to_string(b1) + '.' +to_string(c1) +'.'+to_string(d1);
        
        cout << s << endl;
            
        
        
    }
    return 0;
}
