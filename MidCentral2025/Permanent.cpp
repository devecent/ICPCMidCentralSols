#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,2>
using namespace std;

// notice N is only up to 10
// so a bruteforce computation is likely to work
// by the definition the permanent of a matrix relies on the permanent of a smaller matrix
// this can be implemented recursively
// construct each of the minors of the matrices and call the permanent on that matrix
// the base case is simply N = 1 where the permanent is the element of the 1 by 1 matrix
// the time complexity of this solution is O(N!)
// since matrix of size N by N has N (N-1) X (N-1) matrices to compute permanents for
// and those have N-1 (N-2) X (N-2) matrices to compute permanents for
// thus, we get N*(N-1)*(N-2), ..., 1
// or N!
// 10! is only 3,628,800 so this fits in the time constraints

void solve() {
    int n; 
    cin >> n;
    vector<vector<ll>> g(n,vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    auto recurse = [&](auto&& recurse, vector<vector<ll>>& a, ll v) -> ll {
        ll curr = 0;
        auto matrix = [&](int r, int c,vector<vector<ll>>& b) {
            int N = b.size();
            vector<vector<ll>> m(N-1);
            int cur = 0;
            for(int i = 0; i < N; i++) {
                if(i == r) continue;
                for(int j = 0; j < N; j++) {
                    if(j == c) continue;
                    if(m[cur].size() == N-1) cur++;
                    m[cur].push_back(b[i][j]);
                }
            }
            return m;
        };
        if(a.size() == 2) {
            return v*(a[0][0]*a[1][1] + a[0][1]*a[1][0]);
        }
        else {
            for(int i = 0; i < a.size(); i++) {
                auto m = matrix(0,i,a);
                curr += recurse(recurse,m,v*a[0][i]);
            }
        }
        return curr;
    };
    if(n == 1) {
        cout << g[0][0] << '\n';
        return;
    }
    ll ans = recurse(recurse,g,1ll);
    std::cout << ans;
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}
