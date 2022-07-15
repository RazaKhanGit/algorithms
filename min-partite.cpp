#include<bits/stdc++.h>
using namespace std;

vector <vector <int> > g;
vector<int> vis;
bool is_bip;
void dfs(int node, int color) {
    vis[node] = color;
    for(auto v:g[node]) {
        if(!vis[v]) {
            dfs(v, 1^2^color);
        }
        else {
            if(vis[v] == vis[node]) {
                is_bip = false;
            }
        }
    }    
}

void solve() {
    int n, m;
    cin >> n >> m;
    is_bip = true;
    g.clear();
    g.resize(n+1);
    vis.assign(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, 1);
        }
    }

    cout << is_bip << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}