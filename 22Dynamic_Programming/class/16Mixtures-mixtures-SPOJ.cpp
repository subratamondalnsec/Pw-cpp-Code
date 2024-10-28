#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int g(vector<int>&colors,int i,int j){
    int result=0;
    for(int m=i;m<=j;m++){
        result=(result%100+colors[m]%100)%100;
    }
    return result;
}

int f(vector<int>&colors,int i,int j){
    if(i==j) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];
    int result=INT_MAX;
    for(int k=i;k<j;k++){
        result=min(result,f(colors,i,k)+f(colors,k+1,j)+g(colors,i,k)*g(colors,k+1,j));
    }
    return dp[i][j]=result;
}

int fbu(vector<int>&colors){
    memset(dp,0,sizeof dp);
    int n=colors.size();
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            int result=INT_MAX;
            for(int k=i;k<j;k++){
                result=min(result,dp[i][k]+dp[k+1][j]+g(colors,i,k)*g(colors,k+1,j));
            }
            dp[i][j]=result;
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    while(cin>>n){
        vector<int> colors;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            colors.push_back(num);
        }
        //memset(dp,-1,sizeof dp);
        //cout<<f(colors,0,colors.size()-1)<<"\n";
        cout<<fbu(colors);
        colors.clear();
    }
    return 0;
}