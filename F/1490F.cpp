/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1490/F
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

    map<ll,ll> fre;
    for(ll i=0; i<n; i++) {
        ll val;
        cin >> val;
        fre[val]++;
    }

    vector<ll> v;
    for(auto it : fre) v.push_back(it.second);

    sort(v.begin(), v.end());

    ll less = 0;
    ll total = 0;
    vector<ll> ans(v.size());
    for(ll i=0; i<v.size(); i++) {
        ans[i] = less;
        if(i != v.size()-1 && v[i] != v[i+1])
            less = total+v[i];
        total+=v[i];
    }

    total = 0;
    ll sum = 0;
    for(ll i=v.size()-1; i>=0; i--) {
        ans[i] += sum - v[i]*total;
        total++;
        sum += v[i];
    }

    ll mini = ans[0];
    for(auto it : ans) {
        mini = min(mini, it);
        // cout << it << ' ';
    }
    // cout << endl;
    cout << mini << endl;
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