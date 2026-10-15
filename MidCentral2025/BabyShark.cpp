#include <bits/stdc++.h>
#define ll long long
#define ii array<int,2>
using namespace std;
 
void solve() {
	map<string,int> mp;
	string s;
	vector<string> a;
	int streak = 1, mx = 0;
	string last = "";
	while(cin >> s) {
		if(last == s) {
			streak++;
		}
		else {
			streak = 1;
		}
		last = s;
		mx = max(mx,streak);
		a.push_back(s);
	}
	int n = a.size();
	streak = 1, last = "";
	for(int i = 0; i < n; i++) {
		if(a[i] == last) {
			streak++;
		}
		else {
			streak = 1;
		}
		last = a[i];
		if(streak == mx) {
			cout << a[i];
			return;
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while(t--) {
		solve();
	}
}

