#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,4>
using namespace std;

// notice this is a variation of the shortest path in an unweighted graph problem but we are given another constraint
// we are inclined to lean towards a bfs solution
// however a typical visited array doesn't work here because we might want to take a longer path
// that leads to a shorter cost at that square

// one approach is to instead store a visited array based on row, column, and the cost we arrived at the square
// lets say we are at row r, column col, and cost c
// if we have already reached a state r, col, and c previously we don't have to continue searching
// the complexity of this solution is O(N*M*S)
// this is about 10^8 operations and just fit in the constraints

// the 2nd approach is the code below where we can instead consider this greedy idea
// if we have come across this square before, then we should only consider more paths from this square
// if and only if the current cost is lower than the previous visit
// this has the same complexity of O(N*M*S)

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
    queue<ii> q;
    q.push({0,0,0,0});
    while(!pq.empty()) {
        auto [depth, cost, r, c] = q.front();
        q.pop();
        if(r >= n || c >= m || r < 0 || c < 0) continue;
        ll ncost = cost+g[r][c];
        if(ncost > s) continue;
        if(r == n-1 && c == m-1 && ncost <= s) {
            cout << depth;
            return;
        }
        if(ncost >= dp[r][c]) continue;
        dp[r][c] = ncost;
        q.push({depth+1,ncost,r+1,c});
        q.push({depth+1,ncost,r-1,c});
        q.push({depth+1,ncost,r,c+1});
        q.push({depth+1,ncost,r,c-1});
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
