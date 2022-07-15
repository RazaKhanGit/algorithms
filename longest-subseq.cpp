#include<bits/stdc++.h>
using namespace std;

int n, d, a[100100];
map <int, int> compVal;

int t[400400];

//build not required as init with 0 as we want
void update(int indx, int l, int r, int pos, int val) {
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        t[indx] = max(t[indx], val);
        return;
    }
    int mid = (l+r)/2;
    update(2*indx, l, mid, pos, val);
    update(2*indx+1, mid+1, r, pos, val);
    t[indx] = max(t[2*indx], t[2*indx+1]);
}

int query(int indx, int l, int r, int lq, int rq) {
    if(lq > r || rq < l) {
        return 0;
    }
    if(lq >= l && rq <= r) {
        return t[indx];
    }
    int mid = (l+r)/2;
    return max(query(2*indx, l, mid, lq, rq) , query(2*indx+1, mid+1, r, lq, rq));
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        compVal[a[i]];
    }
    int cnt = 0;
    for(auto &v:compVal) {
        v.second = cnt++;
    }
    cin >> d;
    
    int dp[n];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int lo = a[i]-d;
        int hi = a[i]+d;

        auto it = compVal.upper_bound(hi);
        it--; 
        hi = it->second;

        it = compVal.lower_bound(lo);
        lo = it->second;

        dp[i] = query(1, 0, cnt, lo, hi)+1;
        ans = max(ans, dp[i]);
        update(1, 0, cnt, compVal[a[i]], dp[i]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}