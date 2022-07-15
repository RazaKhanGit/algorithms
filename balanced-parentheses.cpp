#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
string s;

int rec(int i, int numOfOpenBrac) {
    if(dp[i][numOfOpenBrac] != 0) {
        return dp[i][numOfOpenBrac];
    }
    if(numOfOpenBrac < 0) {
        return 0;
    }
    else if(i == s.length() && numOfOpenBrac == 0) {
        dp[i][numOfOpenBrac] = 1;
        return 1;
    }
    
    if(s[i] == '?') {
        dp[i][numOfOpenBrac] = rec(i+1, numOfOpenBrac+1);
        dp[i][numOfOpenBrac] = rec(i+1, numOfOpenBrac-1);
    }

    else if(s[i] == '(') {
        dp[i][numOfOpenBrac] = rec(i+1, numOfOpenBrac+1);
    }

    else if (s[i] == ')') {
        dp[i][numOfOpenBrac] = rec(i+1, numOfOpenBrac-1);
    }

    cout << i <<":"<< numOfOpenBrac <<":"<<dp[i][numOfOpenBrac] <<"**\n";
    return dp[i][numOfOpenBrac];
}

void solve() {
    cin >> s;
    int n = s.length();
    memset(dp, 0, size(dp));
    dp[0][0] = 0;
    dp[0][0] = rec(0, 0);
    cout << dp[0][0];
}

int main(){
    //int n; cin>>n;
    //for(int i = 0; i < n; i++) solve();
    solve();
    return 0;
}