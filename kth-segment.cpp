#include<bits/stdc++.h>
using namespace std;

int t[400400];
void build(int index, int l, int r) {
    if(l == r) {
        t[index] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);

    t[index] = t[2*index]+t[2*index+1];
}

void update(int index, int l, int r, int pos, int val) {
    if(pos < l || pos > r) {
        return;
    }

    if(l == r) {
        t[index] = val;
        return;
    }

    int mid = (l+r)/2;
    update(2*index, l, mid, pos, val);
    update(2*index+1, mid+1, r, pos, val);

    t[index] = t[2*index]+t[2*index+1];
}

int query(int index, int l, int r, int k) {
    if(l == r) {
        return l;
    }
    int mid = (l+r)/2;
    if(k <= t[2*index]) {
        return query(2*index, l, mid, k);
    }
    else {
        return query(2*index+1, mid+1, r, k-t[2*index]);
    }
}

void solve() {
    int n;
    cin >> n;
    build(1, 0, n);
    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch;
        if(ch == '+') {
            int x;
            cin >> x;
            update(1, 0, n-1, x, +1);
        }
        else if(ch == '-') {
            int x;
            cin >> x;
            update(1, 0, n-1, x, -1);
        }
        else if(ch == '?') {
            int k;
            cin >> k;
            cout << query(1, 0, n-1, k) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++)
    solve();

    return 0;
}