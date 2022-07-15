#include<bits/stdc++.h>
using namespace std;

vector <vector <int> > g;
vector<int> vis;

void dfs(int node, int comp) {
    vis[node] = comp;
    for(auto v:g[node]) {
        if(!vis[v]) {
            dfs(v, comp);
        }
    }    
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int comp_cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            comp_cnt++;
            dfs(i, comp_cnt);
        }
    }

    int a[comp_cnt+1];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) {
        a[vis[i]]++;
    }

    long long ans = 0;
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i]*sum;
        sum += a[i];
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