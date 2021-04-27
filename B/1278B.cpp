/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1278/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll a, b;
    cin >> a >> b;

    ll delta = abs(a - b);

    ll counter = 0;
    ll ans = 0;
    ll temp = 0;
    while(temp < delta || (delta + temp)%2 != 0) {
        temp += counter;
        counter++;
        ans++;
    }

    cout << ((ans > 0) ? ans-1 : ans) << endl;
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