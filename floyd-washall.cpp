#include<bits/stdc++.h>
using namespace std;

int dist[404][404];
int par[404][404];
// i->x->...y->par[i][j]->j
void printPath(int i, int j) {
    if(i != j) {
        printPath(i, par[i][j]);
    }
    cout << j << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i != j)
                dist[i][j] = 1e9;
        }
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            par[i][j] = i;
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k]+dist[k][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                    par[i][j] = par[k][j];
                }
            }
        }
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