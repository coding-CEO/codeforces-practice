/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1353/D
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

struct info
{
    ll l, r;
};

struct comp {
    bool operator()(info const &a, info const &b) {
        ll len1 = a.r - a.l;
        ll len2 = b.r - b.l;

        if(len1 != len2) {
            return !(len1 > len2);
        }
        return !(a.l < b.l);
    }
};

void runTest()
{
    ll n;
    cin >> n;

    vector<ll> ans(n, 0);

    priority_queue<info, vector<info>, comp> q;
    q.push({0, n-1});

    ll counter = 1;
    while(!q.empty()) {
        info i = q.top();
        q.pop();

        ll mid = (i.r + i.l) / 2;
        ans[mid] = counter;
        counter++;

        if(i.l <= mid-1)
            q.push({i.l, mid-1});
        if(i.r >= mid+1)
            q.push({mid+1, i.r});
    }

    for(auto it : ans) cout << it << ' ';
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