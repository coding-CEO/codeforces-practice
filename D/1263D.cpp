/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1263/D
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

template <class T>
class DSUGeneral
{
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;

public:
    DSUGeneral<T>()
    {
    }

    void makeSet(T a)
    {
        parent[a] = a;
        rank[a] = 0;
    }

    T findSet(T a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = findSet(parent[a]);
    }

    void unionSet(T a, T b)
    {
        a = findSet(a);
        b = findSet(b);

        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);

            parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    unordered_map<T, T> getParents()
    {
        return parent;
    }
};

void runTest()
{
    ll n;
    cin >> n;

    string a[n];
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }

    DSUGeneral<char> dsu;
    for(string s : a) {
        for(char c : s) {
            dsu.makeSet(c);
        }
    }

    for(string s : a) {
        for(ll i=1; i<s.size(); i++) {
            char u = dsu.findSet(s[0]);
            char v = dsu.findSet(s[i]);
            dsu.unionSet(u, v);
        }
    }

    set<char> parents;
    for(string s : a) {
        for(char c : s) {
            parents.insert(dsu.findSet(c));
        }
    }

    cout << parents.size() << endl;
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