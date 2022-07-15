#include<bits/stdc++.h>
using namespace std;

int dp[5050][5050];

void solve() {
    int n, x;
    cin >> n >> x;
    int l[n], r[n];
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    for(int i = n; i >= 0; i--) {
        for(int sum = 5000; sum >= 0; sum--) {
            if(i == n) {
                if(sum == x) {
                    dp[i][sum] = 1;
                }
                else {
                    dp[i][sum] = 0;
                }
            }
            else {
                int lo = sum+l[i];
                int hi = sum+r[i];
                hi = min(hi, 5000);
                if(lo > 5000) {
                    dp[i][sum] = 0;
                }
                else {
                    dp[i][sum] = dp[i+1][hi] - (lo>0?dp[i][lo-1]:0);
                }

            }
        }
        
        for(int sum = 1; sum <= 5000; sum++) {
            dp[i][sum] = dp[i][sum]+dp[i][sum-1];
        }

    }

    cout << dp[0][0] << "\n";

}

int main(){
    //int n; cin>>n;
    //for(int i = 0; i < n; i++) solve();
    solve();
    return 0;
}