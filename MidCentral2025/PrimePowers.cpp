#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,2>
using namespace std;

vector<bool> prime(1e6+10,true);
vector<int> primes;


const ll MOD = 1e9+7;

ll binpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) {
            res = res*a%MOD;
        }
        a  = (a*a)%MOD;
        b >>= 1;
    }
    res %= MOD;
    return res;
}

void solve() {
    int p, l, r;
    cin >> p >> l >> r;
    ll ans = 1;
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] >= l && primes[i] <= r) {
            ans = (ans*binpow(primes[i],p)) % MOD;
        }
    }
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    int t = 1;
    for(int i = 2; i < 1e6+10; i++) {
        if(prime[i]) {
            primes.push_back(i);
            for(int j = i; j < 1e6+10; j+= i) {
                prime[j] = false;
            }
        }
    }
    while(t--) {
        solve();
    }
}
