#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int map[200][200]={0,};
int prodiaonal(int x,int y){
    int ans =0;
    // cout<<"pro x: "<<x<<" y: "<<y<<endl;
    for(int i=y;i<y+n;i++){
        ans+=map[x][i];
        // cout<<map[x][i]<<" ";
        x++;
    }//cout<<endl;
    // cout<<"ans: "<<ans<<endl;
    return ans;
}
int condiaonal(int x, int y){
    int ans =0;
    //cout<<"con x: "<<x<<" y: "<<y<<endl;
    for(int i=y;i>=y-n+1;i--){
        ans+=map[x+y-i][i];
        //cout<<map[x+y-i][i]<<" ";
    }//cout<<endl;
    // cout<<"ans: "<<ans<<endl;
    return ans;
}
int main(){
    scanf("%d \n",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j+n] = map[i][j];
            map[i+n][j+n] = map[i][j];
            map[i+n][j] = map[i][j];
        }
    }
    vector<int> cntarr;
    for(int i=0;i<n;i++){
        cntarr.push_back(prodiaonal(0,i));
        if (i!=0){
            cntarr.push_back(prodiaonal(i,0));
            cntarr.push_back(condiaonal(i,2*n-1));
        }
        cntarr.push_back(condiaonal(0,n+i));
    }
    sort(cntarr.begin(), cntarr.end());
    cout<< cntarr.back();
}