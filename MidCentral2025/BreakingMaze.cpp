#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,4>
using namespace std;

void solve() {
    int n,m,s;
    cin >> n >> m >> s;
    vector g(n,vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    vector<vector<ll>> dp(n,vector<ll>(m,1e18));
    queue<ii> pq;
    pq.push({0,0,0,0});
    while(!pq.empty()) {
        auto [depth, cost, r, c] = pq.front();
        pq.pop();
        if(r >= n || c >= m || r < 0 || c < 0) continue;
        ll ncost = cost+g[r][c];
        if(ncost > s) continue;
        if(r == n-1 && c == m-1 && ncost <= s) {
            cout << depth;
            return;
        }
        if(ncost >= dp[r][c]) continue;
        dp[r][c] = ncost;
        pq.push({depth+1,ncost,r+1,c});
        pq.push({depth+1,ncost,r-1,c});
        pq.push({depth+1,ncost,r,c+1});
        pq.push({depth+1,ncost,r,c-1});
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
}
