#include<stdio.h>
#include<algorithm>

using namespace std;


int main()
{
  int input, minVal, maxVal;
  //배열크기,입력값,최소값,최대값

  int arr[3];
  // n만큼 배열 생성
    
  for(int i=0; i<3;i++){
      scanf("%d",&input);
      arr[i] = input;
  }
  // input 변수 활용해 입력 값 배열에 각각 저장
  
  minVal=arr[0];
  maxVal=arr[0];
  // 배열 첫번째 값을 최소 최대값으로 설정
  
  for(int i=0; i<3;i++){
      minVal = min(minVal,arr[i]);
      // 최소값과 비교해 더 작으면 최소값에
      maxVal = max(maxVal,arr[i]);
      // 최대값과 비교해 더 크면 최대값에 저장
  }
  
  printf("%d %d",minVal,maxVal);
  // 배열 모두 검사하고 최소값 최대값 출력
}