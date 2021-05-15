#include<iostream>
#include<string>

using namespace std;
bool check(string A)
{
	string one,two,three,four;
	int checksum = 0;
		char check;
	int countH = 0;
		if(A.size()!=13) 
		{
			// cout <<1;
			return false;

			
		}

		for(int i=0; i<A.size(); i++)
		{
			if(A[i]=='-')
			{
				countH++;

			}

			if(countH == 0)
			{
				if(!(A[i]>='0'&&A[i]<='9'))
				{
					return false;
				}
				one.push_back(A[i]);
			}
			else if(countH ==1)
			{
				if(A[i]!='-'&&!(A[i]>='0'&&A[i]<='9'))
				{
					return false;
				}
				two.push_back(A[i]);
			}
			else if(countH == 2)
			{
				if(A[i]!='-'&&!(A[i]>='0'&&A[i]<='9'))
				{
					return false;
				}
				three.push_back(A[i]);
			}
			else if(countH == 3)
			{
				if(A[i]!='-'&&!(A[i]>='0'&&A[i]<='9')&&A[i]!='X')
				{
					return false;
				}
				four.push_back(A[i]);
			}
			else{
				return false;
			}
			
		}
		if(countH!=3)
		{
			// cout <<2;
			return false;

		}
		if(one.size()>5 || one.size()==0){
			// cout <<3;
		return false;} 

		if(two.size()>8 || two.size()==1) {
			// cout <<4;
		return false;} 

		if(three.size()>7 || three.size()==1){
			// cout <<5;
		return false;} 

		if(four.size()>2 || four.size()==1) {
			// cout <<6;
		return false;} 

		
		for(int i=0; i<13; i++)
		{
			if(A[i] != '-'&&A[i] != 'X' && !(A[i] >= '0' && A[i] <= '9'))
			{
				// cout <<7;
				return false;
			
			}
			
		}
		int a = 10;
		for(int i = 0;i<12; i++)
		{
			if(A[i]>='0'&&A[i]<='9')
			{
				checksum +=(A[i]-'0')*a;
				// cout << checksum <<endl;
				a--;
			}
			
		}
		// cout << checksum<<endl;
		if (checksum%11==0){
			check = '0';
		}
		else if((checksum%11)==1){
			check = 'X';
		}
		else{
			check = 11 - checksum%11 +'0';
		}

		if(four[1]==check){
			return true;
			
		}

		else return false;



			
		

	
}
int main(){
	int t;
	cin >> t;
	for(int i=0; i< t; i++)
	{
		
		string A;
		cin >> A;
		if(check(A))
		{
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}
}
