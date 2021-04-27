/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/576/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

bool isPrime(ll n)
{
    if (n <= 1)
        return false;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void runTest()
{
    ll n;
    cin >> n;

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<ll> ans;

    for(ll i=2; i<=n; i++) {
        if(isPrime(i)) {
            ll j = i;
            while(j <= n) {
                ans.push_back(j);
                j *= i;
            }
        }
    }

    cout << ans.size() << endl;
    for(ll val : ans) cout << val << ' ';
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