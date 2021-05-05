/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/707/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

// I just copy-pasted solution of this...

void runTest()
{
    ll n;
    cin >> n;

    if(n <= 2) {
        cout << -1 << endl;
        return;
    }

    if(n%2 == 0) {
        ll val1 = (n*n)/4 - 1;
        ll val2 = (n*n)/4 + 1;
        cout << val1 << ' ' << val2 << endl;
    }else {
        ll val1 = (n*n - 1)/2;
        ll val2 = (n*n + 1)/2;
        cout << val1 << ' ' << val2 << endl;
    }

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