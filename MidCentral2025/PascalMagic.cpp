#include <bits/stdc++.h>
#define ll long long
#define ii array<int,2>
using namespace std;
 
void solve() {
    ll n,p;
    cin >> n >> p;
    auto count = [&](ll k) -> ll {
        ll cnt = 0;
        for(ll i = p; i <= k; i *= p) {
            cnt += k/i;
        }
        return cnt;
    };
    ll top = count(n);
    ll ans = 0, last = 0;
    ll a = p-1, b = n%p;
    while(a < n || b < n) {
        ll k = min(a,b);
        ll bottom = count(k)+count(n-k);
        if(top > bottom) {
            ans += k-last+1;
        }
        if(k == a) {
            a += p;
        }
        else {
            b += p;
        }
        last = k+1;
    }
    if(last <= n) {
        if(top > count(last)+count(n-last)) {
            ans += n-last+1;
        }
    }
    cout << ans;
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
}
