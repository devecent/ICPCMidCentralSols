#include <bits/stdc++.h>
#define ll long long
#define ii array<double,2>
using namespace std;

vector<ii> getHull(vector<ii>& points) {
    sort(points.begin(),points.end());
    points.erase(unique(points.begin(),points.end()),points.end());
    int n = points.size();
    vector<ii> hull;
    if(n < 3) {
        return points;
    }
    auto area = [&](ii a, ii b, ii c) -> double {
        return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
    };
    for(int i = 0; i < n; i++) {
        while(hull.size() > 1 && area(hull[hull.size()-2],hull.back(),points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    int lower = hull.size();
    for(int i = n-2; i >= 0; i--) {
        while(hull.size() > lower && area(hull[hull.size()-2],hull.back(),points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

ii sub(ii a, ii b) {
    return {a[0]-b[0],a[1]-b[1]};
}
 
void solve() {
    int n;
    cin >> n;
    vector<ii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    vector<ii> hull = getHull(a);
    auto perpdist = [&](ii a, ii b, ii c) -> double {
        ii u = {b[0]-a[0],b[1]-a[1]};
        ii v = {c[0]-a[0],c[1]-a[1]};
        ii n = {-u[1],u[0]};
        double norm = sqrt(u[0]*u[0]+u[1]*u[1]);
        n = {n[0]/norm,n[1]/norm};
        return fabs(v[0]*n[0]+v[1]*n[1]);
    };
    auto cross = [&](ii a, ii b) -> double {
        return a[0]*b[1]-a[1]*b[0];
    };
    double ans = 1e18;
    int k = 1;
    int m = hull.size();
    for(int i = 0; i < m; i++) {
        int j = (i+1)%m;
        while(true) {
            int k2 = (k+1)%m;
            double d1 = fabs(cross(sub(hull[j],hull[i]),sub(hull[k],hull[i])));
            double d2 = fabs(cross(sub(hull[j],hull[i]),sub(hull[k2],hull[i])));
            if(d2 > d1) k = k2;
            else break;
        }
        ans = min(ans,perpdist(hull[i],hull[j],hull[k]));
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) {
        solve();
    }
}
