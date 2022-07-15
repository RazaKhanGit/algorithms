#include<bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> g;
vector<int> subtreeSZ;
vector<int> centroids;

long long ans = 0;

void dfs(int nn, int pp) {
    //add
    subtreeSZ[nn] = 1;
    for(auto v:g[nn]) {
        if(v != pp) {
            dfs(v, nn);
            //add
            subtreeSZ[nn] += subtreeSZ[v];
        }
    }
    //add
    ans += 1LL*subtreeSZ[nn]*(n-subtreeSZ[nn]);
}

void solve() {
    cin >> n;
    g.resize(n+1);
    subtreeSZ.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}