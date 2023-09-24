#include <bits/stdc++.h> 

int solveRec(vector<int> &num, int x, vector<int> &dp) {
    //base case
    if(x == 0)
        return 0;
    if(x < 0) {
        return INT_MAX;
    }
    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;

    for(int i = 0; i < num.size(); i++) {
        int ans = solveRec(num, x-num[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    
    return dp[x];
}

int solveTab(vector<int> &num, int x) {
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {

        for(int j = 0; j < num.size(); j++) {

            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX) {
        return -1;
    }

    return dp[x];
}

int solveEasy(vector<int> &num, int x) {
    int prev2 = 0;
    
}

int minimumElements(vector<int> &num, int x)
{
    
    int ans = solveTab(num, x);
    
    return ans;
}