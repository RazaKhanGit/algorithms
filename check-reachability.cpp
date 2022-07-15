#include<bits/stdc++.h>
using namespace std;

int dist[404][404];

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
        dist[a][b] = 1;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
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