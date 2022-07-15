#include<bits/stdc++.h>
using namespace std;

using lli = long long;
lli MOD = 1e9+7;
string L, R;
lli d;
int len;

lli dp[102][2][2][101]; // solving for 0-k then remove 0. 1-k

lli rec(lli idx, lli lo, lli hi, lli firstNonZero) {
    if(idx == len) {
        return 1;
    }
    if(dp[idx][lo][hi][firstNonZero] == -1) {
        lli ans = 0;
        int loLim = 0;
        int hiLim = 9;
        if(lo == 1) {
            loLim = L[idx] - '0';
        } 
        if(hi == 1) {
            hiLim = R[idx] - '0';
        }

        if(idx < firstNonZero) {
            hiLim = 0;
        }

        for(int i = loLim; i <= hiLim; i++) {
            if(idx >=  firstNonZero && (idx-firstNonZero+1-i) %2 == 1) {
                continue;
            }

            lli nlo = lo;
            lli nhi = hi;
            if(i != R[idx]-'0') {
                nhi = 0;
            }
            if(i != L[idx]-'0') {
                nlo = 0;
            }
            ans = (ans + rec(idx+1, nlo, nhi, firstNonZero)) %MOD;
        }
        dp[idx][lo][hi][firstNonZero] = ans;
    }
    return dp[idx][lo][hi][firstNonZero];
}

void solve() {
    cin >> L >> R;
    len = R.length();
    lli extra = R.length()-L.length();
    string temp = "";
    while(extra--) temp+="0";
    L = temp + L;
    memset(dp, -1, sizeof(dp));
    lli ans = 0;
    for(int i = 0; i < len; i++) {
        ans = ans+rec(0, 1, 1, i);
    }
    cout << ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}