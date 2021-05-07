#include <iostream>
#include <fstream>
#include <string>
#define MAX_COL 10

using namespace std;
////////////////////////////////////////////////////////////////
// Function : term
// Description:  행, 열, 데이터 값을 구조체에 저장
// Variables : 
//          int row : 행
//          int col : 열
//          int value : 데이터 값
/////////////////////////////////////////////////////////////////
struct term{
    int row, col, val;
};
term a[MAX_COL]; //행 우선 배열
term b[MAX_COL]; //열 우선 배열 -transpose 이용
term c[MAX_COL]; //열 우선 배열 -fast transpose 이용
  
////////////////////////////////////////////////////////////////
// Function : original
// Description :   original matrix A 출력
// Variables : 
//          myarray : 2중 배열로 데이터 값을 저장.
/////////////////////////////////////////////////////////////////
void original(string myarray[6][6]){
    int i=0;
    int j=0;
    ifstream f("lab4.txt"); //파일 불러옴
    while(!f.eof()){ //데이터가 끝날때까지
        f >> myarray[i][j];
        j++;
        if(myarray[i][j] == "\n"){ //한 줄이 끝나면 
            i++;
            j=0;
        }
    }
    cout << "1)  Original matrix : A\n"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout << myarray[i][j]<<" ";
        }
        cout << endl;
    }
}

////////////////////////////////////////////////////////////////
// Function : transpose
// Description :  matrix A를 행과 열 바꾸어 출력
// Variables : 
//          myarray : original matrix에서 [i][j] -> [j][i] 순서로 바꾸어 출력 
/////////////////////////////////////////////////////////////////
void transpose(string myarray[6][6]){
    
    cout << "\n2)  Transpose of Original matrix A\n"<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout << myarray[j][i]<<" ";
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////
// Function : spares_row
// Description:  0이 아닌 항만 "행 우선" 배열로 저장
// Variables: 
//          Imyarray :  string 으로 받은 정보를 int형으로 바꾸어 저장한 배열
/////////////////////////////////////////////////////////////////
void spares_row(string myarray[6][6]){
    int Imyarray[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            Imyarray[i][j]=atoi((myarray[i][j].c_str())); //string으로 받은 정보를 숫자로 변경
        }
    }
    int l=0;
    for(int i=0; i<6;i++){
        for(int j=0; j<6; j++){
            if(Imyarray[i][j]!=0){//value값이 0이 아닌 것들만 term a에 저장
                a[l].row=i; //행
                a[l].col=j; //열
                a[l].val=Imyarray[i][j]; //데이터 값
                l++;
            }
        }
    }
    cout << "\n3)  Spares matrix of A - row major\n" << endl;
    for(int i=0;i<8;i++){
        cout << a[i].row <<" "<<a[i].col<<" "<<a[i].val<<endl;
    }
}

////////////////////////////////////////////////////////////////
// Function : spares_col
// Description:  3의 결과물을 "열 우선" 배열로 저장
// Variables: 
//          currentb :  현재 배열b의 index값을 가리킴
/////////////////////////////////////////////////////////////////
void spares_col (term a[]){
    int currentb=0;
    for(int i=0;i<6;i++){
        for(int j=0;j<8;j++){
            if(a[j].col==i){//col값이 작은 순서대로 저장
                b[currentb].row=a[j].col; //행,열 변경하여 a를 b로 옮김
                b[currentb].col=a[j].row;
                b[currentb].val=a[j].val;
                currentb++;
            }
        }
    }
        
    cout << "\n4)  Spares matrix of A - colum major\n" << endl;
    for(int i=0;i<8;i++){
        cout << b[i].row <<" "<<b[i].col<<" "<<b[i].val<<endl;
    }
}
////////////////////////////////////////////////////////////////
// Function : fast_col
// Description:  5) Fast transpose 이용하여 "열 우선" 배열로 저장
// Variables: 
//          row_terms : 데이터가 각 행에 몇개가 저장되어 있는지 저장
//          starting_pos : 데이터 중 각 행이 시작하는 위치
/////////////////////////////////////////////////////////////////
void fast_col(term a[]){
    int row_terms[MAX_COL], starting_pos[MAX_COL];
    int i,j;
    for(i=0;i<6;i++)
        row_terms[i]=0; //초기화
    for(i=0;i<8;i++)
        row_terms[a[i].col]++; //각 row terms 위한 값
    starting_pos[0]=0; //row term 시작점

    for(i=1;i<=6;i++)
        starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
    for(i=0;i<8;i++){ //a를 c로 옮김
        j=starting_pos[a[i].col]++;
        c[j].row=a[i].col; c[j].col=a[i].row;
        c[j].val=a[i].val;
    }
    cout << "\n5)  Fast transpose of Sparse matrix A\n" << endl;
    for(int i=0;i<8;i++){
        cout << c[i].row <<" "<<c[i].col<<" "<<c[i].val<<endl;
    }
    
}
int main(){

    string myarray[6][6]; //original 배열 저장
    
    original(myarray);
    transpose(myarray);
    spares_row(myarray);
    spares_col(a);
    fast_col(b);
    
    return 0;
}