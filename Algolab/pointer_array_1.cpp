#include<iostream>
#include<cstdlib>

using namespace std;

void print_arg(char *p)
{
    for(int i=0;p[i]!='\0';i++) cout << p[i];
    cout << endl;
}

int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        cout << "usage: ./args 250\n";
        return -1;
    }
    cout<<"argv[0] is "<<argv[0]<<endl;
    cout<<"argv[0] is "<<(void *)argv[0]<<endl;
    print_arg(argv[0]);
    cout<<"argv[1] is "<<argv[1]<<endl;
    cout<<"argv[1] is "<<(void *)argv[1]<<endl;
    print_arg(argv[1]);
    int n = atoi(argv[1]);
    cout<<"n is "<<n<<endl;
    cout<<"sizeof(argv[1]) :  "<<sizeof(argv[1])<<endl;
    cout<<"sizeof(n) :  "<<sizeof(n)<<endl;
}
