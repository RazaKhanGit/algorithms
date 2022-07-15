#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;

vector<int> dis;
vector<int> par;

void dfs(int nn, int pp, int dd) {
    dis[nn] = dd;
    par[nn] = pp;
    for(auto v:g[nn]) {
        if(v != pp) {
            dfs(v, nn, dd+1);
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n+1);
    dis.resize(n+1);
    par.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int max1 = 1;
    for(int i = 2; i <= n; i++) {
        if(dis[max1] < dis[i]) {
            max1 = i;
        }
    }
    dfs(max1,0, 0);
    int max2 = 1;
    for(int i = 2; i <= n; i++) {
        if(dis[max2] < dis[i]) {
            max2 = i;
        }
    }
    vector<int> path;
    int temp = max2;
    while(temp!=0) {
        path.push_back(temp);
        temp = par[temp];
    }
    cout << path.size()-1 << "\n";
    if(path.size() %2) {
        int centre = path[path.size()/2];
    }
    else {
        int centre1 = path[path.size()/2];
        int centre2 = path[(path.size()-1)/2];
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