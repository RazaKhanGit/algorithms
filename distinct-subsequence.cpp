#include<bits/stdc++.h>
using namespace std;

int dp[1000];

void print(set<string> &s) {
    for(auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << "\n";
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();


    memset(dp, 0, n+1);
    int charPos[26];
    dp[0] = 1;

    memset(charPos, -1, size(charPos));

    for(int i = 1; i <= n; i++) {
        int lastPos = charPos[s[i-1]-'a'];
        dp[i] = 2*dp[i-1];
        if(lastPos != -1)
            dp[i] -= dp[lastPos-1];
        charPos[s[i-1]-'a'] = i;
    }
    cout << "DP Ans: " << dp[n]-1;

    set<string> ss;
    set<string> sss;
    for(int i = 0; i < n; i++) {
        ss.insert(""+s[i]);
        sss = ss;
        for(auto itr = sss.begin(); itr != sss.end(); itr++) {
            ss.insert(*itr+s[i]);
        }
    }
    cout << "\nRecursion Ans: " << ss.size()-1;
}

int main(){
    //int n; cin>>n;
    //for(int i = 0; i < n; i++) solve();
    solve();
    return 0;
}