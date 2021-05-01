/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1236/B
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
    ll n, m;
    cin >> n >> m;

    cout << binaryPowerMod(binaryPowerMod(2, m, mod) - 1, n, mod) << endl;
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