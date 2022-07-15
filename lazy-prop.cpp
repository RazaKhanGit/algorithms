#include<bits/stdc++.h>
using namespace std;

struct node {
    int sum, maxr, lazy;
    node() {
        sum = 0;
        maxr = 0;
        lazy = 0;
    }
};

node merge(node a, node b) {
    node ans;
    ans.sum = a.sum+b.sum;
    ans.maxr = max(a.maxr, b.maxr);

    return ans;
}

node t[400400];

void push(int id, int l, int r) {
    if(t[id].lazy != 0) {
        t[id].sum = t[id].lazy*(r-l+1);
        t[id].maxr = t[id].lazy;
        if(l != r) {
            t[id<<1].lazy = t[id].lazy;
            t[id<<+1].lazy = t[id].lazy;
        }
        t[id].lazy = 0;
    }
}

void update(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if(lq > r || rq < l) {
        return;
    }
    if(lq <= l && rq >= r) {
        t[id].lazy = val;
        push(id, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(id<<1, l, mid, lq, rq, val);
    update(id<<1+1, mid+1, r, lq, rq, val);
    t[id] = merge(t[id<<1], t[id<<1+1]);

}

node query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    cout << id <<" "<< l <<" "<< r << "\n";
    if(lq > r || rq < l) return  node();
    if(lq <= l && rq >= r) {
        return t[id];
    }
    int mid = (l+r)/2;
    return merge(query(id<<1, l, mid, lq, rq), query(id<<1+1, mid+1, r, lq, rq));
}


void solve() {
    update(1,0,9,0,5,3);
    update(1,0,9,6,9,4);
    node x = query(1,0,9,3,6);
    cout << x.sum << " " << x.maxr << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}