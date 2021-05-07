#include <iostream>
#include <fstream>
#define MAX_SIZE 50 

char bufferEval[MAX_SIZE]; 

using namespace std;

class Stack {
public:
	char *stack;
    int top;
	int max_size;

	Stack(int size);
	bool IsFull();
	bool IsEmpty();
	void push(char data);
	char pop();
};

Stack::Stack(int size){
		top = -1;
		stack = new char[size];
		max_size = size;
	}

bool Stack::IsFull() {
	if (top + 1 == max_size) { 
        return true;
    }

	else {
        return false;
    }
}

bool Stack::IsEmpty() {
	if (top == -1){ 
        return true;
    }

	else {
        return false;
    }
}

void Stack::push(char data) {
	if (IsFull()) {
        cout << "Stack is Full" << endl;
    }

	else {
		top++;
		stack[top] = data;	
	}
}

char Stack::pop() {
	if (IsEmpty()) {	
		cout << "Stack is empty" << endl;
		return 0;
	}

	else {
        return stack[top--]; 
    }
}

class IntStack {
public:
    int* stack;
	int top;
	int max_size;

	IntStack(int size);
	bool IsFull();
	bool IsEmpty();
	void push(int data);
	int pop();
};

IntStack::IntStack(int size) {
    top = -1;
    stack = new int[size];
    max_size = size;
}

bool IntStack::IsFull() {
	if (top + 1 == max_size){  
        return true;
    } 

	else {
        return false;
    }
}

bool IntStack::IsEmpty() {
	if (top == -1) { 
        return true;
    }
    	
	else {
        return false;
    }
}

void IntStack::push(int data) {
	if (IsFull()) {
        cout << "Stack is Full" << endl;
    }

	else {
		top++;	
		stack[top] = data;	
	}
}

int IntStack::pop() {
	if (IsEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}

	else {
        return stack[top--]; 
    }
}

int priority(char input); 
void infixToPostfix(char *buffer);
int postfixEvaluation(char *buffer);

int main() {

	char buffer[MAX_SIZE]; 

	ifstream infile("infix_postfix.txt");
	
	while (infile.getline(buffer, MAX_SIZE)) {	

		cout << "Infix expression : " << buffer<<" " ;

		cout << "The Postfix conversion: ";

		infixToPostfix(buffer);

		cout << endl;

		cout << "The  Result : " << postfixEvaluation(bufferEval) << endl;

        cout << endl;
	}
}

int priority(char input) {
	
	if (input == ')'){
        return 4;
    }

	else if (input == '*' || input == '/') {
        return 3;
    }

	else if (input == '+' || input == '-') {
        return 2;
    }

	else if (input == '(') {
        return 1;
    }

	else if (input == ' ') {
        return -1; 
    }

	else{
        return 0;
    }
}

void infixToPostfix(char *buffer) {

	Stack conversion(MAX_SIZE);
	
	int i = 0, j = 0;

	while (buffer[i] != '\0') {
		switch (priority(buffer[i])) { 
		case 0: 
			bufferEval[j++] = buffer[i]; 
			cout << buffer[i] << " ";
			break;

		case 4: 
			while (conversion.stack[conversion.top] != '(') {
				bufferEval[j] = conversion.pop();
				cout << bufferEval[j++] << " ";
			}
			break;

		case 3: 
		case 2:
			if (priority(buffer[i]) >= priority(conversion.stack[conversion.top])){
                
                conversion.push(buffer[i]);
            }

			else{ 
				bufferEval[j] = conversion.pop();	
				cout << bufferEval[j++] << " ";
				conversion.push(buffer[i]);
			}
			break;

		case 1: 
			conversion.push(buffer[i]);
			break;
			
		default: 
			break; 
		}
		i++;
	}

	while (conversion.top != -1) { 
		if (conversion.stack[conversion.top] == '(') { 
			conversion.pop();
			continue;
		}
        
		else {
			bufferEval[j] = conversion.pop();
			cout << bufferEval[j++] << " ";
		}
	}

	bufferEval[j] = '\0'; 
}


int postfixEvaluation(char *buffer) {

	IntStack evaluation(MAX_SIZE);

	int i = 0;
	int op1, op2;

	while (buffer[i] != '\0') { 
		switch (priority(buffer[i])) { 
		case 0:	
			evaluation.push(buffer[i]-'0');
			break;

		case 3: 
		case 2:
			op2 = evaluation.pop();
			op1 = evaluation.pop();

			switch (buffer[i]) { 
			case '+':
				evaluation.push(op1 + op2);
				break;

			case '-':
				evaluation.push(op1 - op2);
				break;

			case '*':
				evaluation.push(op1 * op2);
				break;

			case '/':
				evaluation.push(op1 / op2);
				break;
			}
			break;
		default: 
			break;
		}
		i++;
	} 
	return evaluation.pop(); 
}
