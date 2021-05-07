/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW3.cpp
* Description : 
* - 2차원 배열로 저장되어있는 미로의 길을 찾아 지정된 시작점부터 도착점 까지의 경로와 이동 좌표를 출력해준다.
* - 미로의 이동 경로를 저장하는 과정에서는 Stack을 활용해 저장해주고, 출력해준다.
* Algorithm :
* - 먼저, 미로에서 지나가는 경로를 저장할 때 활용할 Stack class를 구현해준다.
* - 그리고, 미로에서 각 방향으로 이동할 때 행과 열에 각각 더해주어야 할(뺴주어야 할) 값을 저장해주는 offsets 구조체를 구현한다.
* - 벽이 쳐져있기 때문에 (0,0)이 아닌 (1,1)부터 시작해 미로에서 도착점인 (6,6) 까지의 경로를 찾아준다.
* - Stack이 비어있지 않고, 아직 도착점을 찾지 못했다면 path() 함수의 첫번째 while문에 걸려 도착점을 찾을 때 까지 계속 반복할 수 있도록 해준다.
* - 이동하면서 지나가는 좌표는 mark[6][6]에서의 값을 1로 바꿔주어 지나간 것을 표시해준다.
* - 계속 이동이 가능하다면 offsets 구조체 배열을 이용해 각 방향에 해당하는 값을 행과 열에 더해주어 다음 좌표로 이동해준다.
* - 만약 다음 좌표 값이 도착점이라면, 현재 좌표와 다음 좌표를 Stack에 push 해주고 break 해준다.
* - 만약 다음 값이 벽이 아니고, 가보지 않은 좌표라면 현재 좌표와 다음 좌표를 Stack에 push 해주고, dir을 0으로 초기화 한 후
    다음 좌표로 이동해 다시 북쪽부터 길을 찾아준다. 그리고 mark[6][6]에 다음 좌표에 해당하는 값을 1로 바꿔주어 지나간 것을 표시해준다.
* - 만약 길이 막혀 있다면 첫번째 while문에 작성된 코드를 통해 row, col에 각각 Stack에서 바로 이전에 갔던 좌표를 pop 해온 후
    다시 새로운 길이 나올때 까지 돌아간다.
* - 그렇게 해서 도착점을 찾고 모든 while 반복문이 끝나면 이동 경로의 좌표값들과 경로를 출력해준다.
* Variables :
* - class Stack : 미로에서 길을 찾는 과정에서 경로를 저장해 주기 위한 int형 data를 담는 Stack 클래스이다.
                  배열(stack)을 할당해 주기 위한 int형 포인터변수 *stack, stack의 top을 가르키는 int형 변수 top,
                  stack의 사이즈를 저장해 줄 int형 변수 size를 멤버 변수로 가진다.
* - Stack(int value) : stack을 입력받은 크기의 배열로 만들어주는 동시에 top을 -1로 초기화해주는 Stack 클래스의 생성자이다.
* - int IsFull() : Stack이 가득 찼는지 검사해주고 1(true) 혹은 0(false)로 결과값을 리턴해준다.
* - int IsEmpty() : Stack이 비었는지 검사해주고 1(true) 혹은 0(false)로 결과값을 리턴해준다.
* - void push(int val) : Stack에 매개변수로 받아온 int형 매개변수 val을 넣어준다.
* - int pop() : Stack의 top에 들어있는 것을 return 해준 후 top을 1만큼 줄여준다.
* - struct offsets : 각 방향에 따라 행과 열에 더해줘야 할(빼줘야 할) 숫자를 저장할 구조체이다.
                     행과 열에 각각 더해줄 값을 저장할 vert, horiz라는 int형 변수를 가진다.
* - void path() : 시작점부터 도착점까지의 미로의 경로를 기록하고, 지나간 좌표와 경로를 출력해주는 함수이다.
*******************************************************************************************************************************/

#include <iostream>
#define MAX_SIZE 64 //8*8 미로 배열의 모든 좌표의 갯수인 64로 MAX_SIZE를 지정해줌

using namespace std;

class Stack {
public:
   int *stack;
   int top;
   int size;

   Stack(int value);
   int IsFull();
   int IsEmpty();
   void push(int val);
   int pop();
};

Stack::Stack(int value) {
   top = -1;
   size = value;
   stack = new int[size];
}

int Stack::IsFull() { // top이 size-1과 같으면 Stack이 가득 찬 것이다.
   if (top == size - 1) {
      return 1;
   }
   else {
      return 0;
   }
}

int Stack::IsEmpty() { // top이 -1이라면 Stack이 비어있는 것이다.
   if (top == -1) {
      return 1;
   }
   else {
      return 0;
   }
}

void Stack::push(int val) {
   if (IsFull()){
       cout<<"Stack is Full"<<endl;
       return;
   }
      
   else
      stack[++top] = val; // top의 값을 먼저 1만큼 늘려준 후 index에 val 값을 push해준다.
}

int Stack::pop() {
   if (IsEmpty())
   {
       cout<<"Stack is Empty"<<endl;
       return -1;
   }
   else
      return stack[top--]; //stack[top]에 있는 것을 리턴해준 후 top의 크기를 1만큼 줄였다.
}

/*******************************************************************************************************************************
* struct : offsets
* description : offsets의 사용 목적은 방향에 따른 행과 열의 증가값(감소값)을 저장해주기 위함이다.
* variables :
* - int vert : 행의 증가값(감소값)을 저장해주는 int형 변수이다.
* - int horiz : 열의 증가값(감소값)을 저장해주는 int형 변수이다.
*******************************************************************************************************************************/
struct offsets{
    int vert;
    int horiz;
};

/*******************************************************************************************************************************
* function : path()
* description : path()의 사용 목적은 미로의 출발점부터 도착점 까지의 경로와 지나간 좌표를 찾은 후, 둘을 출력해주기 위함이다.
* variables :
* - Stack StackRow(MAX_SIZE), Stack StackCol(MAX_SIZE) : 진행 경로의 행과 열 값을 담아주기 위한 두개의 Stack이다.
* - int row, col : 현재 위치해 있는 행과 열을 저장하기 위한 int형 변수들이다.
* - int next_row, next_col : 다음으로 이동할 행과 열을 저장하기 위한 int형 변수들이다.
* - int dir : 북쪽을 시작으로 0 부터 7까지 시계방향으로 각각의 방향을 나타내기 위한 int형 변수이다.
* - int exit_row, exit_col : 도착점의 행과 열을 저장하기 위한 int형 변수들이다.
* - offsets compass[8] : 8개의 방향에 따라 각각 행과 열에 더해줘야 할(빼줘야 할) 숫자를 저장한 구조체 배열이다.
* - int maze[8][8] : 벽을 표시한 미로가 들어있는 2차원 배열이다.
* - int mark[6][6] : 미로에서 지나간 이동 경로를 표시해주기 위한 2차원 배열이다.
* - bool found : 도착점을 발견했나 못했나를 저장해주기 위한 bool형 변수이다.
*******************************************************************************************************************************/
void path() {

    Stack StackRow(MAX_SIZE), StackCol(MAX_SIZE); //각각 행과 열을 저장할 Stack을 MAX_SIZE로 만들어줌

    StackRow.push(1), StackCol.push(1); //(0,0)은 벽이 있기 때문에 출발점인 (1,1)의 행의 값과 열의 값을 각각 push 해줌

    int row, col, next_row, next_col, dir = 0;
    int exit_row = 6, exit_col = 6; //도착점인 (6,6)의 행과 열을 각각 변수로 선언해줌

    offsets compass[8];

    compass[0].vert = -1; compass[0].horiz = 0; //N
    compass[1].vert = -1; compass[1].horiz = 1; //NE
    compass[2].vert = 0; compass[2].horiz = 1; //E
    compass[3].vert = 1; compass[3].horiz = 1; //SE
    compass[4].vert = 1; compass[4].horiz = 0; //S
    compass[5].vert = 1; compass[5].horiz = -1; //SW
    compass[6].vert = 0; compass[6].horiz = -1; //W
    compass[7].vert = -1; compass[7].horiz = -1; //NW

    int maze[8][8] = { //상하좌우로 벽을 표시해주었기 떄문에 6*6이 아닌 8*8의 배열로 만들어줌
       { 1, 1, 1, 1, 1, 1, 1, 1 },
       { 1, 0, 1, 1, 1, 1, 1, 1 },
       { 1, 1, 0, 1, 1, 1, 1, 1 },
       { 1, 1, 0, 0, 0, 0, 1, 1 },
       { 1, 1, 1, 0, 1, 1, 1, 1 },
       { 1, 1, 0, 1, 0, 0, 1, 1 },
       { 1, 1, 1, 1, 1, 1, 0, 1 },
       { 1, 1, 1, 1, 1, 1, 1, 1 }
    };

    int mark[6][6] = { //이동 경로를 표시하는 mark는 maze에서 벽을 제외하고 6*6 크기의 배열로 만들어줌
       { 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0 },
       { 0, 0, 0, 0, 0, 0 }
    };

    mark[0][0] = 1; //시작점인 maze의 (1,1)은 벽이 없는 mark에선 (0,0)이므로 이 좌표를 지나간단 의미로 mark[0][0]을 1로 바꿔줌

    bool found = false;

    while ( !(StackRow.IsEmpty()) && !(StackCol.IsEmpty()) && !(found) ) {

        dir = 0; //dir을 0으로 초기화해서 북쪽부터 검사할 수 있도록 해줌
        row = StackRow.pop(); 
        col = StackCol.pop(); //row, col에 현재 행과 열의 값을 pop해서 저장해줌

        while ( (dir < 8) && !(found)) { //계속 이동이 가능하다면

            next_row = row + compass[dir].vert; 
            next_col = col + compass[dir].horiz; //현재의 행,열 값에 각각 dir 값과 구조체 배열을 이용해 찾은 이동 좌표값을 더해서 다음 좌표 값을 정해줌

            if ( ( next_row == exit_row ) && ( next_col == exit_col ) ) { //다음 좌표 값이 도착점인 (6,6)라면
                found = true;
                mark[next_row - 1][next_col - 1] = 1; //maze의 크기는 mark의 크기와 달리 8*8이기 때문에 next_row - 1, next_col - 1을 해주어야 함
                StackRow.push(row);
                StackCol.push(col); //현재 위치의 좌표값을 각각 Stack에 push 해줌

                StackRow.push(next_row);
                StackCol.push(next_col); //다음 이동할 좌표값(도착점)을 각각 Stack에 push 해줌

                break; //도착점을 찾았으니 break를 통해 끝내줌
            }

            else if ( !(maze[next_row][next_col]) && !(mark[next_row - 1][next_col - 1]) ) { //벽이 아니고, 가보지 않은 새로운 좌표라면
                mark[next_row - 1][next_col - 1] = 1; //mark를 1로 바꿔줘 이동 경로로 표시해줌

                StackRow.push(row);
                StackCol.push(col); //현재 위치의 row, col값을 각각 Stack에 push해줌

                StackRow.push(next_row);
                StackCol.push(next_col); //이동할 위치의 row, col값을 각각 Stack에 push해줌

                dir = 0;
                break; //이동할 방향을 찾으면 beak를 통해 다음 위치로 바로 이동해줌
            }
            ++dir; //방향을 바꿔 다음 방향을 검사해줌
        }
    }

    cout << "The Path is" << endl;

    cout << endl;

    cout << "row  col" << endl;

    for (int i = 0; i < 8; i++) { //Stack에 index 0 ~ 7 까지 이동 좌표가 기록되어 있음
        cout << " " << StackRow.stack[i] - 1 << "    " << StackCol.stack[i] - 1 << endl; //벽을 표시해놓았기 때문에 행과 열에 1이 더해져있는 상황이므로, 1을 빼줘 6*6 기준의 좌표로 출력해줌
    }

    cout << "Marked Matrix" << endl;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << mark[i][j];
        }
        cout << endl;
    }
}

int main() {

    path();
    
    return -1;
}
