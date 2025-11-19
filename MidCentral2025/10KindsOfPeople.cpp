#include <bits/stdc++.h>
#define ll long long
#define ii array<ll,2>
using namespace std;


void solve() {
    string a, b;
    cin >> a >> b;
    vector<ll> aa, bb;
    for(int i = 0; i < a.size(); i++) {
        if(!isdigit(a[i])) {
            if(isupper(a[i])) {
                aa.push_back(a[i]-'A'+36);
            }
            else {
                aa.push_back(a[i]-'a'+10);
            }
        }
        else {
            aa.push_back(a[i]-'0');
        }
    }
    for(int i = 0; i < b.size(); i++) {
        if(!isdigit(b[i])) {
            if(isupper(b[i])) {
                bb.push_back(b[i]-'A'+36);
            }
            else {
                bb.push_back(b[i]-'a'+10);
            }
        }
        else {
            bb.push_back(b[i]-'0');
        }
    };
    reverse(aa.begin(),aa.end());
    reverse(bb.begin(),bb.end());
    int mxa = 0, mxb = 0;
    for(int x : aa) {
        mxa = max(x,mxa);
    }
    for(int x : bb) {
        mxb = max(mxb,x);
    }
    vector<ll> deca(7501), decb(7501);
    for(ll i = 2; i <= 7500; i++) {
        ll sum = 0;
        ll pow = 1;
        for(ll x : aa) {
            sum += x*pow;
            pow *= i;
        }
        deca[i] = (sum);
        sum = 0;
        pow = 1;
        for(ll x : bb) {
            sum += x*pow;
            pow *= i;
        }
        decb[i] = (sum);
    }

    for(int i = mxa+1; i <= 7500; i++) {
        ll x = deca[i];
        auto it = lower_bound(decb.begin(),decb.end(),x);
        if(it-decb.begin() <= mxb) continue;
        if(it != decb.end() && *it == x) {
            cout << x << ' ' << i << ' ' << it-decb.begin() << '\n';
            return;
        }
    }
    cout << "CANNOT MAKE EQUAL\n";
}

int main() {
    // REMEMBER TO DELETE UNDER
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
