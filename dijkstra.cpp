#include<bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using lli = long long;
#define F first
#define S second
#define MP make_pair
// class prioritize {
// public:
//     bool operator()(ii &p1, ii &p2) {
//         return p1.S > p2.S;
//     }
// };

int n, m;
vector<ii> g[100100];
lli dist[100100];
int vis[100100];
void dijkstra(int src) {
    for(int i = 1; i <= n; i++) {
        dist[i] = 1e18;
        vis[i] = 0;
    }
    dist[src] = 0;
    priority_queue<ii> pq;
    pq.push(MP(-0, src));
    while(!pq.empty()) {
        ii fs = pq.top();
        pq.pop();
        if(vis[fs.S]) {
            continue;
        }
        vis[fs.S] = 1;
        for(auto v:g[fs.S]) {
            int neigh = v.S;
            int wt = v.F;
            if(dist[neigh] > dist[fs.S]+wt) {
                dist[neigh] = dist[fs.S]+wt;
                pq.push(MP(-dist[neigh], neigh));
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
    dijkstra(1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}