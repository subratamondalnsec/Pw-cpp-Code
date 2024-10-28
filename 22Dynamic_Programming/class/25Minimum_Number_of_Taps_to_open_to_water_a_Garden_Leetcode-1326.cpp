#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minTaps(int n,vector<int>&ranges){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            int ans=INT_MAX;
            for(int j=start;j<=end;j++){
                ans=min(ans,dp[j]);
            }
            if(ans!=INT_MAX) dp[end]=min(dp[end],ans+1);
        }
        return dp[n]==INT_MAX ? -1 : dp[n];
    }
};
int main(){
    vector<int>arr={3,4,1,1,0,0};
    int n=arr.size()-1;
    Solution sol;
    int result=sol.minTaps(n,arr);
    cout<<"Minimum Tap of the garden : "<<result;
}