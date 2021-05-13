/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1396/A
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

    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    if(n == 1) {
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        return;
    }

    cout << "1 " << n-1 << endl;
    for(ll i=0; i<n-1; i++) cout << (n-1)*a[i] << ' ';
    cout << endl;

    cout << "1 " << n << endl;
    for(ll i=0; i<n; i++) cout << -n*a[i] << ' ';
    cout << endl;

    cout << n << ' ' << n << endl;
    cout << n*a[n-1]-a[n-1] << endl;
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