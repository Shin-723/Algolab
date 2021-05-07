#include <iostream>

using namespace std;
#define MAX_TERMS 100
void add(int starta, int finisha, int stratb, int finishb, int startd, int finishd);
void sub(int starta, int finisha, int startb, int finishb, int startd, int finishd);
int compare(int a, int b);
void attach(int coefficient, int expon);
int startd, finishd;

typedef struct {
	float coef;
	int expon;
} Polynomial;
Polynomial terms[MAX_TERMS];

int main()
{
	char menu[50]; int coef = 0, expon = 0;
	cout << "Addition /  Subtraction? : ";
	cin >> menu;
	if((strcmp(menu, "Addition") == 0) || (strcmp(menu, "Subtraction") == 0)) {
		int starta = 0, finisha = 0;
		cout << "Enter A(X)" << endl;
		do {
			cin >> coef >> expon;
			terms[finisha].coef = coef;
			terms[finisha++].expon = expon;
		} while(expon != 0);
		finisha--;
		int startb = finisha + 1;
		int finishb = startb;
		cout << "Enter B(X)" << endl;
		do {
			cin >> coef >> expon;
			terms[finishb].coef = coef;
			terms[finishb++].expon = expon;
		} while(expon != 0);
		finishb--;
		startd = finishb +1;
		finishd = startd;
		if(strcmp(menu, "Addition") == 0) {
			add(starta, finisha, startb, finishb, startd, finishd);
			cout << "A(X) + B(X) = D(X) :" << endl;
			for(;startd < finishd; startd++)
				cout << terms[startd].coef << " " << terms[startd].expon << " ";
		}
		if(strcmp(menu, "Subtraction") == 0) {
			sub(starta, finisha, startb, finishb, startd, finishd);
			cout << "A(X) - B(X) = D(X) :" << endl;
			for(;startd < finishd; startd++)
				cout << terms[startd].coef << " " << terms[startd].expon << " ";
		}
	}
}
void add(int starta, int finisha, int startb, int finishb, int startd, int finishd)
{
	float coefficient;
	while(starta <= finisha && startb <= finishb) {
		switch(compare(terms[starta].expon, terms[startb].expon)) {
		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			startb++; break;
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			if(coefficient) {
				attach(coefficient, terms[starta].expon);
				starta++; startb++; break;
			}
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
		}
	}
}
void sub(int starta, int finisha, int startb, int finishb, int startd, int finishd)
{
	float coefficient;
	while(starta <= finisha && startb <= finishb) {
		switch(compare(terms[starta].expon, terms[startb].expon)) {
		case -1:
			attach(terms[startb].coef , terms[startb].expon);
			startb++; break;
		case 0:
			coefficient = terms[starta].coef - terms[startb].coef;
			if(coefficient) {
				attach(coefficient, terms[starta].expon);
				starta++; startb++; break;
			}
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++; break;
		}
	}
}
void attach(int coefficient, int exponent)
{
	if(finishd >= MAX_TERMS) {
		cout << "¥Ÿ«◊Ωƒø° «◊¿Ã ≥ π´ ∏πΩ¿¥œ¥Ÿ";
		exit(1);
	}
	terms[finishd].coef = coefficient;
	terms[finishd++].expon = exponent;
}
int compare(int a, int b)
{
	if(a > b)
		return 1;
	else if(a == b)
		return 0;
	else
		return -1;
}