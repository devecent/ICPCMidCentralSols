#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,2>
using namespace std;

// this problem is tricky with its constraints
// the time constraints just barely allow for solutions without sieve of eratosthenes to pass
// but binary exponetiation is necessary to pass time constraints
// theres approximately 80,000 primes up to 10^6 and with an E of 10^6, is about 8 * 10^9 operations which is too many
// in this solution, i used a sieve of eratosthenes to precompute the primes, but checking primes in O(sqrt(N))
// is allowed in this problem by checking if an integer is a divisor of n up to the sqrt(N)
// the solution below has time complexity of O(Nlog(log(N) + P*log(E)) where P is the number of primes up to N


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
