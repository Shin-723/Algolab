#include<iostream>

using namespace std;

/*int main()
{
    int chnum;             // 차수를 나타낼 변수
    int num;               // 계수를 나타낼 변수
    int gop=1;             // 결과를 나타낼 변수 .. 선언과 동시에 초기화함
    int repeat=0;
    cout << "n^i의 반복 알고리즘입니다."<<endl;
    cout << "계수를 입력해주세요 ";
    cin >> num ; // 계수 입력
    cout << "차수를 입력해주세요 ";
    cin >> chnum;  // 차수 입력

    cout << num <<"의 " << chnum <<"승까지의 곱을 구합니다."<<endl;
    for(int i=1;i<=chnum;i++)                  //for문 - i가 차수인 chnum까지 수행
    {
            gop=gop*num;                          // 결과를 출력 하기 위한 다항식
            cout <<i<<" 번 곱할 때 "<<gop<<endl;   // 출력
            repeat++;
    }
    cout<< "연산 횟수는 " << repeat <<"번 입니다";

    return 0;

}*/
int main()
{
    int chnum;             // 차수를 나타낼 변수
    int num;               // 계수를 나타낼 변수
    int gop=1;             // 결과를 나타낼 변수 .. 선언과 동시에 초기화함
    int repeat=0;
    cout << "n^i의 반복 알고리즘입니다."<<endl;
    cout << "계수를 입력해주세요 ";
    cin >> num ; // 계수 입력
    cout << "차수를 입력해주세요 ";
    cin >> chnum;  // 차수 입력

    cout << num <<"의 " << chnum <<"승까지의 곱을 구합니다."<<endl;
}
int Recursive(int i,int chnum, int num, int gop)// 리턴형이 int형이고 int형 매개변수가 4개인 rotate()함수
{                                         // 변수명을 명확히 하기위해 그냥 main에서의 변수명 그대로 사용
        
    if(i<chnum)                      // if 문 
    {
            ++i;                   // i를 계산전에 먼저 1 증가 시킨다.
            gop=gop*num;            // n*n*n*....*n 을 k번 곱하는 것을 나타낸 표현식
            cout <<i<<" 번 곱할 때" << gop << endl;                  
            return Recursive(i,chnum,num,gop);  // 순환 알고리즘 부분
                                                // - 자기 자신을 다시 부르면서 인자값을 넘겨준다.
    }
    return 0;
}