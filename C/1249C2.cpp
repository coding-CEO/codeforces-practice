/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1249/C2
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n;
    cin >> n;
    vector<ll> vals;
    ll pos2 = -1;
    while (n > 0) {
        vals.push_back(n % 3);
        if (vals.back() == 2) pos2 = (vals.size()) - 1;
        n /= 3;
    }
    vals.push_back(0);
    if (pos2 != -1) {
        ll pos0 = find(vals.begin() + pos2, vals.end(), 0) - vals.begin();
        vals[pos0] = 1;
        for (ll i = pos0 - 1; i >= 0; --i) {
            vals[i] = 0;
        }
    }
    ll ans = 0;
    ll pw = 1;
    for (ll i = 0; i < vals.size(); ++i) {
        ans += pw * vals[i];
        pw *= 3;
    }
    if (vals.back() == 1) ans = pw / 3;
    cout << ans << endl;
}

int main()
{

#if !defined(ONLINE_JUDGE)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        runTest();

    return 0;
}