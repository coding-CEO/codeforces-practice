/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1215/C
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

    string s, t;
    cin >> s >> t;

    vector<ll> a, b;
    for(ll i=0; i<n; i++) {
        if(s[i] != t[i]) {
            if(s[i] == 'a') b.push_back(i+1);
            else a.push_back(i+1);
        }
    }

    if((a.size()+b.size())%2 != 0) {
        cout << -1 << endl;
        return;
    }

    vector<pair<ll,ll>> ans;
    ll i=0;
    while(i+1 < a.size()) {
        ans.push_back({a[i], a[i+1]});
        i += 2;
    }
    bool has1 = false;
    if(i == a.size()-1) has1 = true;

    i = 0;
    while(i+1 < b.size()) {
        ans.push_back({b[i], b[i+1]});
        i += 2;
    }

    if(has1) {
        // one element of both remaining
        ans.push_back({a.back(), a.back()});
        ans.push_back({a.back(), b.back()});
    }

    cout << ans.size() << endl;
    for(auto it : ans) cout << it.first << ' ' << it.second << endl;
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