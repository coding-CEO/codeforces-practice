/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1253/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m;
    cin >> n >> m;

    ll a[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);

    vector<ll> temp(m, 0);
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        sum += a[i] + temp[i%m];
        temp[i%m] += a[i];
        cout << sum << ' ';
    }
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