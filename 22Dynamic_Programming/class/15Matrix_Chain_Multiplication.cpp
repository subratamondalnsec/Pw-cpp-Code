#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >dp;
int f(int i,int j,vector<int>& arr){
    if(i==j or i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,f(i,k,arr)+f(k,j,arr)+arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j]=ans;
}
int main(){
    int n;
    cout<<"Enter the total number of element : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp.clear();
    dp.resize(n+5,vector<int>(n+5,-1));
    cout<<"Total Number of minimum multiply : "<<f(0,n-1,v);
    // dp.resize(n+5,vector<int>(n+5,0));//1005=>n+5//Tebulation     
    // for(int len=3;len<=n;len++){
    //     for(int i=0;i+len-1<n;i++){
    //         int j=i+len-1;
    //         dp[i][j]=INT_MAX;
    //         for(int k=i+1;k<j;k++){
    //             dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
    //         }
    //     }
    // }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<dp[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"Total Number of minimum multiply : "<<  dp[0][n-1];
}