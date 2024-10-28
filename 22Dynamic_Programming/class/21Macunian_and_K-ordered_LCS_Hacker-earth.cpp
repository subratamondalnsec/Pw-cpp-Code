#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[2005][2005][8];
ll longestCommonSubstring(int a[],int b[], int i, int j,int n,int m,int k) {
    if (i == n || j == m) {
        return 0;
    }
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    ll res=0;
    if (a[i] == b[j]) {
        res=1 + longestCommonSubstring(a, b, i + 1, j + 1,n,m,k);
    }
    // else{
    //     if(k>0){
    //         res=1 + longestCommonSubstring(a, b, i + 1, j + 1,n,m,k-1);
    //     }
    //     res=max(res,longestCommonSubstring(a, b, i + 1, j,n,m,k));
    //     res=max(res,longestCommonSubstring(a, b, i, j + 1,n,m,k));
    // }
    else{ //both else case are same 
        if(k>0){
            res=max({1 + longestCommonSubstring(a, b, i + 1, j + 1,n,m,k-1),longestCommonSubstring(a, b, i + 1, j,n,m,k),longestCommonSubstring(a, b, i , j+1,n,m,k)});
        }
        else{
            res=max(longestCommonSubstring(a, b, i + 1, j,n,m,k),longestCommonSubstring(a, b, i, j + 1,n,m,k));

        }
    }
    dp[i][j][k]=res;
    return res;
}
int main() {
    int N, M;
    cin >> N >> M;
    int k;
    cin>>k;
    int a[N];
    int b[M];
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) cin>>b[i];
    memset(dp,-1,sizeof dp);
    ll ans = longestCommonSubstring(a, b, 0, 0,N,M,k);
    cout <<endl<< ans << endl;
    return 0;
}
// 5 5 1
// 1 2 3 4 5
// 5 3 1 4 2