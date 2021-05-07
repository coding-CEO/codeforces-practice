/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1358/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

ll sum(ll n) {
    if(n < 1) return 0;

    return (n*(n+1))/2;
}

void runTest()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2 || y1 == y2) {
        cout << 1 << endl;
        return;
    }

    ll x = abs(x1 - x2);
    ll y = abs(y1 - y2);

    cout << 2*sum(x) + (x)*(y-x-1) + 1 << endl;
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