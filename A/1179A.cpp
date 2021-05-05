/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1179/A
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

void runTest()
{
    ll n, q;
    cin >> n >> q;

    ll maxi = INT_MIN;
    deque<ll> dq;
    for(ll i=0; i<n; i++) {
        ll val;
        cin >> val;
        maxi = max(maxi, val);
        dq.push_back(val);
    }

    vector<pair<ll,ll>> temp;
    temp.push_back({-1, -1});
    while(dq.front() != maxi) {
        ll val1 = dq.front();
        dq.pop_front();

        temp.push_back({val1, dq.front()});

        if(val1 > dq.front()) {
            ll val2 = dq.front();
            dq.pop_front();
            dq.push_front(val1);
            dq.push_back(val2);
        }else {
            dq.push_back(val1);
        }
    }

    vector<ll> arr;
    dq.pop_front();
    while(!dq.empty()) {
        arr.push_back(dq.front());
        dq.pop_front();
    }

    while(q > 0) {
        q--;
        ll m;
        cin >> m;

        if(m < temp.size()) {
            cout << temp[m].first << ' ' << temp[m].second << endl;
        }else {
            cout << maxi << ' ';
            ll ind = (m - temp.size())%(n-1);
            // cout << "ind = " << ind << endl;
            cout << arr[ind] << endl;
        }
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