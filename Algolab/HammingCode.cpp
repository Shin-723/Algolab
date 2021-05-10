
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

void haming1(int A[]);
void haming3(int A[], int B[]);
void haming1print(int A[]);
void print(int A[]);
int main()
{
	
	int num;
	int data;
    cin >> num >> data;
    int bit = data;
    int mask = 1;
    int A[100] = { 0, };
    int B[100] = { 0, };
    int count = 0;
    
    if (num ==0)
    {
        for (int j = 0; j < 31; j++)
        {
        while (count==0||count ==1|| count == 3 ||count==7||count==15)
                count += 1;
            A[count++] = ((bit & (mask << j)) ? 1 : 0);
        }
        haming1(A);
        haming1print(A);
    }
    
    else
    {
        for (int j = 0; j < 32; j++)
        {
            A[count] = ((bit & (mask << j)) ? 1 : 0);
            B[count] = A[count];

            count++;
        }
    
        haming1(B);
        haming3(A, B);
    }
	
	
	return 0;
}
void print(int A[])
{
	int sum = 0;
	int i = 0;
	for (int count = 0; count < 31; count++ )
	{
		if (count != 0 && count != 1 && count != 3 && count != 7 && count != 15)	
		{
			if (A[count] == 1)
				sum += pow(2, i);
			i++;
		}
	}
	cout << sum << endl;
}
void haming3(int A[], int B[])
{
	if (A[0] != B[0] || A[1] != B[1] || A[3] != B[3] || A[7] != B[7] || A[15] != B[15])
	{
		int result = 0;
		if (A[0] != B[0])
			result = result + 1;
		if (A[1] != B[1])
			result = result + 2;
		if (A[3] != B[3])
			result = result + 4;
		if (A[7] != B[7])
			result = result + 8;
		if (A[1] != B[1])
			result = result + 16;
			
		if (A[result] == 0)
			A[result-1] = 1;
		else
			A[result-1] = 0;
		print(A);
	}
	else
		print(A);
}
void haming1(int A[])
{
	int a = 0;
	a = 0;
	for (int k = 16; k < 31; k++)
	{
		if (A[k] == 1)
			a++;
	}
	if (a % 2 != 0)
		a = 1;
	else
		a = 0;
	A[15] = a;


	a = 0;
	for (int k = 8; k < 31; k++)
	{
		if (A[k] == 1)
			a++;
		if ((k + 2) % 8 == 0)
			k = k + 8;
	}
	if (a % 2 != 0)
		a = 1;
	else
		a = 0;
	A[7] = a;

	a = 0;
	for (int k = 4; k < 31; k++)
	{
		if (A[k] == 1)
			a++;
		if ((k + 2) % 4 == 0)
			k = k + 4;
	}
	if (a % 2 != 0)
		a = 1;
	else
		a = 0;
	A[3] = a;

	a = 0;
	for (int k = 2; k < 31; k++)
	{
		if (A[k] == 1)
			a++;
		if ((k + 2) % 2 == 0)
			k = k + 2;
	}
	if (a % 2 != 0)
		a = 1;
	else
		a = 0;
	A[1] = a;

	a = 0;

	for (int k = 2; k < 31; k = k + 2)
	{
		if (A[k] == 1)
			a++;
	}
	if (a % 2 != 0)
		a = 1;
	else
		a = 0;
	A[0] = a;
}
void haming1print(int A[])
{
	int sum = 0;
	for (int j = 0; j < 31; j++)
		if (A[j] == 1)
			sum += pow(2, j);

	cout << sum << endl;
}
