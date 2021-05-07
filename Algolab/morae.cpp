#include<iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int x=0;
	for(int j=0; j<n;j++){
		for(int k=0;k<x;k++) cout << "-";
		
		for(int k=0; k<(n-x*2);k++){
			if(k%2==0) cout << "*";
			else cout <<"+";
			}
		for(int k=0;k<x;k++) cout << "-";

		if (j<n/2) x++;
		else x--;
		cout << endl;
		
	}


	return 0;
}