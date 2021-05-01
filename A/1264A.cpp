/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1264/A
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

    if(n <= 5) {
        cout << "0 0 0" << endl;
        return;
    }

    ll mid = (n/2) - 1;
    map<ll,ll> m;
    set<ll> se;
    for(ll i=mid; i>=0; i--) {
        if(a[i] != a[i+1]) se.insert(a[i]);

        if(se.find(a[i]) != se.end())
            m[a[i]]++;
    }

    if(se.size() < 3) {
        cout << "0 0 0" << endl;
        return;
    }

    vector<ll> v;
    ll sum = 0;
    for(auto it : m) {
        v.push_back(it.second);
        sum += it.second;
    }

    reverse(v.begin(), v.end());

    ll g = 0, s = 0, b = v.back();
    sum -= v.back();
    v.pop_back();

    ll pre = 0;
    for(auto it : v) {
        pre += it;
        if(pre < sum - pre) {
            ll gtemp = pre;
            ll stemp = sum - pre;
            if(gtemp + stemp > g + s) {
                g = gtemp;
                s = stemp;
            }
        }
    }

    if(g == 0 || s == 0 || b == 0) {
        cout << "0 0 0" << endl;
        return;
    }

    for(ll i=v.size()-1; i>=0; i--) {
        if(g >= b) {
            if(g < s-v[i]) {
                s -= v[i];
                b += v[i];
            } else {
                cout << "0 0 0" << endl;
                return;
            }
        }else{
            break;
        }
    }

    cout << g << ' ' << s << ' ' << b << endl;
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