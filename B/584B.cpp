/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/584/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll binaryPowerMod(ll a, ll b, ll m)
{
    ll res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

void runTest()
{
    ll n;
    cin >> n;

    ll a = 1, b = 20;
    ll ans = 0;
    for(ll i=n-1; i>=0; i--) {
        ll temp1 = (a*b)%mod;
        temp1 = (temp1 * binaryPowerMod(27, i, mod))%mod;
        ans = (ans + temp1)%mod;
        a = (a * 7) % mod;
    }

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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}