#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[2005][2005][8];
ll longestCommonSubstring(string& a, string& b, int idxA, int idxB,int k) {
    if (idxA == a.size() || idxB == b.size()) {
        return 0;
    }
    if(dp[idxA][idxB][k]!=-1) return dp[idxA][idxB][k];
    ll res=0;
    if (a[idxA] == b[idxB]) {
        res=1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k);
    }
    else{
        if(k>0){
            res=1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k-1);
        }
        res=max(res,longestCommonSubstring(a, b, idxA + 1, idxB,k));
        res=max(res,longestCommonSubstring(a, b, idxA, idxB + 1,k));
    }
    // else{ both else case are same 
    //     if(k>0){
    //         res=max({1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k-1),longestCommonSubstring(a, b, idxA + 1, idxB,k),longestCommonSubstring(a, b, idxA , idxB+1,k)});
    //     }
    //     else{
    //         res=max(longestCommonSubstring(a, b, idxA + 1, idxB,k),longestCommonSubstring(a, b, idxA, idxB + 1,k));

    //     }
    // }
    dp[idxA][idxB][k]=res;
    return res;
}
int main() {//it is string case it next 21 is number
    string a, b;
    cin >> a >> b;
    int k;
    cin>>k;
    
    memset(dp,-1,sizeof dp);
    ll ans = longestCommonSubstring(a, b, 0, 0,k);
    cout << ans << endl;
    return 0;
}
// ordered
// ordjhed
// 3