#include <bits/stdc++.h>
#define ll long long
#define ii array<int,2>
using namespace std;

// the hint in this problem lies in the constraint of the problem
// we are given that n/p <= 10^6, so we should find a solution that has this constraint
// we can break down the divisiblity rule in a simpler way
// the number of factors of p of the numerator must be greater than
// to the number of factors of p in the denominator
// we now need an efficent way to calaculate the number of factors of p in n!
// notice that n/p is how many times a multiple of p shows up in the expanded form of the factorial
// therefore, we can expand this for n/p^2, n/p^3, ... until we reach 0
// the sum of these terms is the number of factors of p in n!

// i'll be defining count(x) as the number of factor of p in x!

// we need to find when count(n) > count(n-k) + count(k)
// peforming this check on each element in a row of pascals triangle is far too slow because n can be up to 10^18
// this is where the n/p <= 10^6 insight comes to play
// notice that count(n-k) only changes when n-k crosses a multiple of p
// and count(k) only changes when k crosses a multiple of p
// therefore, count(k) + count(n-k) is constant between these boundaries
// we can use a sweep line approach to process entire intervals
// a represents the last position before count(k) increases
// b represents the last position before count(n-k) decreases
// at each iteration, we take the smaller boundary and check whether count(n) > count(k) + count(n-k)
// if this condition holds, every value between last and k is divisble by p
// we can therefore add the entire interval length to our answer
// since each boundary advances by p, we process O(n/p) intervals
// each count calculation takes O(log(n)), giving O(n / p * log(n)) time
 
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
