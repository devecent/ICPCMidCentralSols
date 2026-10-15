#include <bits/stdc++.h>
#define ll long long
#define ii array<int,2>
using namespace std;
 
void solve() {
	int n,k;
	cin >> n >> k;
	vector<int> hours(25);
	for(int i = 0; i < n; i++) {
		int l,r;
		cin >> l >> r;
		for(int j = l; j < r; j++) {
			hours[j]++;
		}
	}
	int cnt = 0;
	for(int i = 0; i < 25; i++) {
		cnt += (hours[i] >= k);
	}
	cout << cnt;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while(t--) {
		solve();
	}
}

