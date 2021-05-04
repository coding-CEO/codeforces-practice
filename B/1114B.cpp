/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1114/B
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, m, k;
    cin >> n >> m >> k;

    map<ll,ll> ma;
    ll len = m*k;
    ll b[n], a[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b, b+n, greater<ll>());

    for(ll i=0; i<len; i++) ma[b[i]]++;

    ll sum = 0;
    ll coun = 0;
    vector<ll> ans;
    ll currl = 0, currs = 0;
    for(ll i=0; i<n; i++) {
        if(ma[a[i]] > 0) {
            // special number
            if(currs < m) {
                currs++;
                currl++;
                sum += a[i];
                ma[a[i]]--;
                if(currs >= m) {
                    currs = 0;
                    currl = 0;
                    coun++;
                    if(coun >= k) break;
                    if(i+1 <= n) {
                        ans.push_back(i+1);
                    }
                    continue;
                }
            }
        }else {
            currl++;
        }
    }

    cout << sum << endl;
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
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}