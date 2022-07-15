//can jump from i -> i+1, i*2, i*3 | find min steps to reach 1 -> n
#include<bits/stdc++.h>
using namespace std;

int dp[101]; //1->n
int revDP[101]; //i->n

void solve() {
    memset(dp, -1, size(dp));
    int n;
    cin >> n;
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(i %6 == 0)
            dp[i] = min(dp[i-1], min(dp[i/2], dp[i/3]))+1;
        else if(i %2 == 0)
            dp[i] = min(dp[i-1], dp[i/2])+1;
        else if(i %3 == 0)
            dp[i] = min(dp[i-1], dp[i/3])+1;
        else 
            dp[i] = dp[i-1]+1;        
    }
    
    cout << dp[n] << "\n";
}

int main(){
    //int n; cin>>n;
    //for(int i = 0; i < n; i++) solve();
    solve();
    return 0;
}