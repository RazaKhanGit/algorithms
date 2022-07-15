#include<bits/stdc++.h>
using namespace std;

using lli = long long;
lli MOD = 1e9+7;
string a; lli d;
int len;

lli dp[10002][2][101]; // solving for 0-k then remove 0. 1-k

lli rec(lli idx, lli hi, lli rem) {
    if(idx == len) {
        if(rem == 0) return 1;
        return 0;
    }
    if(dp[idx][hi][rem] == -1) {
        lli ans = 0;
        int loLim = 0;
        int hiLim = 9;
        if(hi == 1) {
            hiLim = a[idx] - '0';
        }
        for(int i = loLim; i <= hiLim; i++) {
            lli nhi = hi;
            if(i != a[idx]-'0') {
                nhi = 0;
            }
            lli nrem = (rem+i) %d;
            ans = (ans + rec(idx+1, nhi, nrem)) %MOD;
        }
        dp[idx][hi][rem] = ans;
    }
    return dp[idx][hi][rem];
}

void solve() {
    cin >> a >> d;
    len = a.length();
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 1, 0) - 1 + MOD) %MOD;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}