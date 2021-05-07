#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Angle {
private:
	double x;
	double y;
	double r;
    
public:
	void Tri();
	void Rec();
	void Cir();
	void getxy(int xx, int yy);
	void getr(int rr);
};

void Angle::Tri() {
	cout << "triangle " << x << " " << y << " " << x * y * 0.5 << endl;
}

void Angle::Rec() {
	cout << "rectangle " << x << " " << y << " " << x * y << endl;
}

void Angle::Cir() {
	cout << "circle " << r << " " << r * r * 3.14 << endl;
}

void Angle::getxy(int xx, int yy) {
	x = xx;
	y = yy;
}

void Angle::getr(int rr) {
	r = rr;
}

int main() {
 Angle angle;
	string a;
	int xx;
    int yy;
    int rr;

	cout.setf(ios::fixed);
	cout.precision(2);
	fstream instream("Array_practice_3.txt");
	if (!instream.is_open()) {
		cout << "error";
		return 1;
	}



	while (instream >> a) {
		if (a == "triangle") {
			instream >> xx >> yy;
			angle.getxy(xx, yy);
			angle.Tri();
		}
		else if (a == "rectangle") {
			instream >> xx >> yy;
			angle.getxy(xx, yy);
			angle.Rec();
		}
		else if (a == "circle") {
			instream >> rr;
			angle.getr(rr);
			angle.Cir();
		}
		else
			cout << "error";
	}
	return 0;
}