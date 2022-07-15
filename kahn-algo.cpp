#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int indegree[100100];
vector<int> topo;
int n, m;

void kahn() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(!indegree[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        topo.push_back(x);
        for(auto v:g[x]) {
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        indegree[a]++;
    }
    kahn(); 
    //all node not in topo is a part of cyclic component
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}