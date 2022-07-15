#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> g[100100];
int dist[100100];
int n, m;   

void bfs01(int src) {
    deque<int> dq;
    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    dq.push_back(src);
    while(!dq.empty()) {
        int xx = dq.front();
        dq.pop_front();
        for(auto v:g[xx]) {
            int neigh = v.first;
            int wt = v.second;
            if(dist[neigh] > dist[xx]+wt) {
                dist[neigh] = dist[xx]+wt;
                if(wt == 0)
                    dq.push_front(neigh);
                else 
                    dq.push_back(neigh);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int src;
    cin >> src;
    bfs01(src);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}