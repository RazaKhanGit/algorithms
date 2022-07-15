#include<bits/stdc++.h>
using namespace std;

int a[100100];
int t[400400];

void build(int l, int r, int index) {
    if(l == r) {
        t[index] = a[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(l, mid, 2*index);
    build(mid+1, r, 2*index+1);

    t[index] = t[2*index] + t[2*index+1];
}

void update(int l, int r, int index, int pos, int val) {
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        t[index] += val;
        return;
    }
    int mid = (l+r)/2;
    update(l, mid, 2*index, pos, val);
    update(mid+1, r, 2*index+1, pos, val);

    t[index] = t[2*index] + t[2*index+1];
}

int query(int l, int r, int index, int rq) {
    if(l > rq || 0 > r) return 0;
    if(l >= 0 && rq >= r) return t[index];

    int mid = (l+r)/2;
    return (query(l, mid, 2*index, rq) + query(mid+1, r, 2*index+1, rq));
}

void print(int a[], int n) {
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

void solve() {
    
    int n;
    cin >> n;
    // memset(a, 0, sizeof(n));
    // build(0, n-1, 1);
    
    int q;
    cin >> q;
    for(int i = 0; i < n; i++) cin >> a[i];

    
    for(int i = 0; i < q; i++) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            // print(t, 8);
            l--;
            r--;
            update(0, n-1, 1, l, v);
            update(0, n-1, 1, r+1, -v);
        }
        else {
            int x;
            cin >> x;
            x--;
            cout << a[x] + query(0, n-1, 1, x) << "\n";
            // cout << x.mini << " " << x.cnt << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    //for(int i = 0; i < t; i++) solve();
    solve();
    return 0;
}