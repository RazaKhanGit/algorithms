#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n, m;
vector<string> arr;
vector<vector<int> > dist;
vector<vector<pair<int, int> > > par;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#') return 1;
    return 0;
}

void bfs(pair<int, int> st) {
    queue<pair<int, int> > q;

    dist = vector<vector<int> >(n,vector<int>(m,1e9));
    par = vector<vector<pair<int, int> > >(n,vector<pair<int, int> >(m,{0,0}));

    dist[st.F][st.S] = 0;
    par[st.F][st.S] = {-1,-1};
    q.push(st);
    while(!q.empty()) {
        auto pos = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            if(check(pos.F+dx[k], pos.S+dy[k]) && dist[pos.F+dx[k]][pos.S+dy[k]] > dist[pos.F][pos.S]+1) {
                dist[pos.F+dx[k]][pos.S+dy[k]] = dist[pos.F][pos.S]+1;
                par[pos.F+dx[k]][pos.S+dy[k]] = pos;
                q.push({pos.F+dx[k], pos.S+dy[k]});
            }
        }
    }

}

void printPath(pair<int, int> en) {
    if(en == make_pair(-1, -1)) {
        return;
    }
    printPath(par[en.F][en.S]);
    cout << en.F << " " << en.S << "\n";
}

void solve() {
    cin >> n >> m;
    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pair<int, int> st, en;
    cin >> st.F >> st.S;
    cin >> en.F >> en.S;
    bfs(st);
    cout << dist[en.F][en.S] << "\n";
    printPath(en);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t; cin>>t;
    //for(int i = 0; i < t; i++) 
    solve();

    return 0;
}