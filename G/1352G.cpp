/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1352/G
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

    if(n <= 3) {
        cout << -1 << endl;
        return;
    }

    deque<ll> q;
    q.push_back(n);
    q.push_front(n-3);
    q.push_front(n-1);

    for(ll i=n-5; i>0; i-=2) q.push_front(i);
    for(ll i=n-2; i>0; i-=2) q.push_back(i);

    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop_front();
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
    cin >> t;

    while (t--)
        runTest();

    return 0;
}