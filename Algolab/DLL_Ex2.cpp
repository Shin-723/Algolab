#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
	string name;
	int weight;
	int height;
	Node* prev;
	Node* next;
	Node(string name, int weight, int height)
	{
		this->name = name;
		this->weight = weight;
		this->height = height;
		prev = NULL;
		next = NULL;
	}
};

class Dll
{
public:
	Dll();
	~Dll();
	bool isEmpty();
	void insertDll(string n, int w, int h);
	void insertAfter(string n, int w, int h, int value);
	void deleteDll(string n);
	void forward();
	void backward();
	void searchDll(string n);
	void findNth(int n);
private:
	Node* head;
};

Dll::Dll()
{
	head = NULL;
}

Dll::~Dll()
{
	while (head != NULL)
	{
		Node *p = head;
		head = head->next;
		delete p;
	}
}

bool Dll::isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void Dll::insertDll(string n, int w, int h)
{
	Node* temp = new Node(n, w, h);
	
	if (head == NULL)
		head = temp;
	else if (temp->name < head->name)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		Node *p, *q;
		p = head;
		q = NULL;
		while ((p != NULL) && (temp->name > head->name))
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
		{
			q->next = temp;
			temp->prev = q;
		}
		else
		{
			q->next = temp;	temp->prev = q;
			temp->next = p;	p->prev = temp;
		}
	}
}

void Dll::insertAfter(string n, int w, int h, int value)
{
	Node *temp = new Node(n, w, h);
	Node *p, *q;
	int cnt = 0;
	p = head;
	q = NULL;
	
	while ((p != NULL) && (cnt != value))
	{
		q = p;
		p = p->next;
		cnt++;
	}
	if (p == NULL || value < 0)
		cout << "Can't insert" << endl;
	else
	{
		q->next = temp;	temp->prev = q;
		temp->next = p;	p->prev = temp;
	}
}

void Dll::deleteDll(string n)
{
	Node *p, *q;
	p = head;
	q = NULL;


	if (isEmpty())
		cout << "List is empty" << endl;
	else
	{
		if (head->name == n)
		{
			if (head->next == NULL)
				delete p;
			else
			{
				head = head->next;
				head->prev = NULL;
				delete p;
			}
		}
		else
		{
			while ((p != NULL) && p->name != n)
			{
				q = p;
				p = p->next;
			}
			if (p->name == n)
			{
				if (p->next == NULL)
				{
					q->next = NULL;
					delete p;
				}
				else
				{
					q->next = p->next;
					p->next->prev = q;
					delete p;
				}
			}
			else
				cout << n << " is not in the list" << endl;
		}
	}
	/*if (isEmpty())
		cout << "List is empty" << endl;
	else if (head->name == n)
	{
		if (head->next != NULL)
		{
			p = head;
			head = head->next;
			delete p;
		}
		else
			head = NULL;
	}
	else
	{
		while ((p != NULL) && (p->name != n))
		{
			q = p;
			p = p->next;
		}
		if (p == NULL)
			cout << n << "'s Node is not in the list" << endl;
		else
		{
			
		}
	}*/
}

void Dll::forward()
{
	Node *p = head;

	cout << "Name\tWeight\tHeight" << endl;
	cout << "--------------------------" << endl;

	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	while (p != NULL)
	{
		cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
		p = p->next;
	}
}

void Dll::backward()
{
	Node *p;
	p = head;

	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	while (p->next != NULL)
		p = p->next;

	cout << "Name\tWeight\tHeight" << endl;
	cout << "--------------------------" << endl;

	while (p != NULL)
	{
		cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
		p = p->prev;
	}
}

void Dll::searchDll(string n)
{
	Node *p;
	p = head;

	if (isEmpty())
	{
		cout << "List is empty" << endl;
		return;
	}

	while ((p != NULL) && (p->name != n))
		p = p->next;

	if (p == NULL)
		cout << n << " is not in the list" << endl;
	else
		cout << n << " is in the list" << endl;
}

void Dll::findNth(int n)
{
	Node *p = head;
	int cnt = 1;

	while ((p != NULL) && (cnt != n))
	{
		p = p->next;
		cnt++;
	}
	
	if (p == NULL)
	{
		switch (n)
		{
		case 1:
			cout << n << "st Node is not in the list" << endl;
			break;
		case 2:
			cout << n << "nd Node is not in the list" << endl;
			break;
		case 3:
			cout << n << "rd Node is not in the list" << endl;
			break;
		default:
			cout << n << "th Node is not in the list" << endl;
			break;
		}
	}
	else
	{
		cout << p->name << "\t" << p->weight << "\t" << p->height << endl;
	}
}

int main()
{
	Dll dll;
	ifstream input;
	string name;
	int weight, height;
	input.open("data.txt", ios::in);

	while (!input.eof())
	{
		input >> name >> weight >> height;
		dll.insertDll(name, weight, height);
	}

	dll.forward();
	cout << endl;

	dll.searchDll("lee");
	cout << endl;

	dll.deleteDll("lee");
	dll.forward();
	cout << endl;

	dll.insertAfter("park", 73, 176, 2);
	dll.forward();
	cout << endl;

	dll.findNth(2);
	cout << endl;

	dll.backward();
}
