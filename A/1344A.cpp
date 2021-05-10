/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1344/A
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

    set<ll> se;

    for(ll i=0; i<n; i++) {
        ll val;
        cin >> val;
        se.insert(((val+i)%n + n)%n);
    }

    if(se.size() == n) cout << "YES" << endl;
    else cout << "NO" << endl;
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