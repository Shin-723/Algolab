#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    int d;
    cin>>d;
    vector<int> stock;
    int n;
    for(int i=0;i<d;i++){
        cin>>n;
        stock.push_back(n);
    }
    int maxValue = *max_element(stock.begin(),stock.end());
    int maxIdx = find(stock.begin(),stock.end(),maxValue)-stock.begin();
    int minValue = *min_element(stock.begin(),stock.end());
    
    int buy[]={0,0};//[0]에는 산 갯수, [1]에는 총 구매 금액
    int sold=0; //수익
    for(int i=0;i<d;i++){
        maxValue = *max_element(stock.begin()+i,stock.end());
        maxIdx = find(stock.begin()+i,stock.end(),maxValue)-stock.begin();
        if(i==maxIdx){
            sold+=stock[i]*buy[0];
            fill_n(buy,2,0);
        }
        else if (i<maxIdx){
            buy[0]+=1;
            buy[1]+=stock[i];
            sold-=stock[i];
        }
    }
    if (buy[0]!=0){
        sold+=stock[d-1]*buy[0];
    }
    cout<<sold<<endl;
}