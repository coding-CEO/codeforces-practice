/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/460/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll power(ll a, ll b) {
    ll res = 1;
    for(ll i=0; i<b; i++) res *= a;
    return res;
}

ll fun(ll a, ll b, ll c, ll val) {
    return ((b*power(val, a)) + c);
}

void runTest()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll limit = 1000000000;

    vector<ll> ans;

    for(ll i=1; i<=81; i++) {
        ll val = fun(a, b, c, i);
        if(val > 0 && val < limit) {
            ll sum = 0, temp = val;
            while(temp > 0) {
                sum += temp%10;
                temp /= 10;
            }
            if(sum == i)
                ans.push_back(val);
        }
    }

    cout << ans.size() << endl;
    for(auto it : ans) cout << it << ' ';
    cout << endl;
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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}