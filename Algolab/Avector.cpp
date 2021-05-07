#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Kvecter {
protected:
    int* m;
    int len;
public:
    Kvecter(int sz = 0, int value = 0);
    Kvecter(const Kvecter& v);
    ~Kvecter() {
        cout << this << " :  ~Kvecter() \n";
        delete[] m;
    }
    void print() const {
        for (int i = 0; i < len; i++) cout << m[i] << " ";
        cout << endl;
    }
    void clear() {
        delete[] m;
        m = nullptr;
        len = 0;
    }
    Kvecter& operator=(const Kvecter& s);
    int& operator[](int idx) { return m[idx]; }
    const int& operator[](int idx)const { return m[idx]; }
    friend bool operator==(const Kvecter& c, const Kvecter& d);
    friend ostream& operator<<(ostream& os, const Kvecter& c);
};

Kvecter& Kvecter::operator=(const Kvecter& s) {
    delete[] m;
    len = s.len;
    m = new int[len];
    for (int i = 0; i < len; i++) m[i] = s.m[i];
    return *this;
}
bool operator==(const Kvecter& c, const Kvecter& d) {
    if (c.len != d.len) return false;
    for (int i = 0; i < c.len; i++)
        if (c.m[i] != d.m[i]) return false;
    return true;
}
bool operator!=(const Kvecter& c, const Kvecter& d) {
    return !(c == d);
}
ostream& operator<<(ostream& os, const Kvecter& c) {
    for (int i = 0; i < c.len; i++) os << c.m[i] << " ";
    return os;
}

Kvecter::Kvecter(int sz, int value) {
    len = sz;
    m = new int[len];
    for (int i = 0; i < len; i++) m[i] = value;
    if (!sz) m = NULL;
    cout << this << " : Kvecter(" << len << ", " << value << ")\n";
}
Kvecter::Kvecter(const Kvecter& v) {
    len = v.len;
    m = new int[len];
    copy(v.m, v.m + len, m);
    cout << this << " : Kvecter(*" << &v << ")\n";
}
#define N 3
class Avector : public Kvecter
{
    char table[N];
public:
    Avector(int sz = 0, int v = 0, const char* t = "abc") :Kvecter(sz, v)
    {
        cout << this << "Avector(" << sz << "," << v << "," << t << ")\n";
        for (int i = 0; i < N; i++)
            table[i] = t[i];
    }
    void setTable(const char* t)
    {
        for (int i = 0; i < N; i++)
            table[i] = t[i];
    }

    friend ostream& operator <<(ostream& os, const Avector& v);
};
ostream&operator<<(ostream& os,const Avector& v)
    {
        for (int i = 0; i < v.len; i++)
            os << v.table[v.m[i] % N] << " ";
        return os;
    }

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        cout << "usage : ./avecter pqr\n";
        return 1;
    }
   
    Avector v1(3); v1.print();
    Avector v2(2, 1, "xyz"); v2.print();
    Avector v3(v2); v3.print();
    cout << ("v1 == v2") << (v1==v2) << endl;
    cout << ("v3 == v2") << (v3 == v2) <<endl;
    v3 = v2 = v1;
    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();
    cout << ("v3 != v2") << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2 << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}