#include<bits/stdc++.h>
using namespace std;

int indp[100100];
int outdp[100100];
int sz[100100];
int par[100100];

void dfs1(int nn, int pp) {
    par[nn] = pp;
    sz[nn] = 1;
    indp[nn] = 0;
    for(auto ch:g[nn]) {
        if(ch != pp) {
            dfs1(ch, nn);
            sz[nn] += sz[ch];
            indp[nn] += indp[ch]+sz[ch];
        }
    }
}

void dfs2(int nn, int pp) {
    // create the outdp of this node
    if(pp == 0) {
        outdp[nn] = 0;
    }
    else {
        outdp[nn] = outdp[pp] + indp[nn] + N - 2*sz[nn] - indp[nn];
    }
    for(auto ch:g[nn]) {
        dfs2(ch, nn);
    }
    // go to its child
}

void solve() {
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= N; i++) {
        cout << indp[i]+outdp[i] << "\n";
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