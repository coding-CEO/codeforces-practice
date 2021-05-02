/*
 *  Question Link:
 *  https://codeforces.com/problemset/problem/1139/C
 */

#include <bits/stdc++.h>

#define ll long long int
#define endl "\n"
#define mod 1000000007

using namespace std;

const ll N = 2e5 + 5;

ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll n, k, sz, ans = 0;
bool vis[N];
vector<ll> g[N];
 
void dfs(ll u)
{
	if(vis[u])
		return;
	sz++;
	vis[u] = 1;
	for(auto &it:g[u])
		dfs(it);
}

void runTest()
{
    cin>>n>>k;
	ll ans = pow(n, k, mod);
	for(ll i=1;i<=n-1;i++)
	{
		ll u, v, x;
		cin>>u>>v>>x;
		if(x == 0)
			g[u].push_back(v), g[v].push_back(u);
	}
	for(ll i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		sz = 0;
		dfs(i);
		ans -= pow(sz, k, mod);
		ans += mod;
		ans %= mod;
	}
	cout<<ans;
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

    ll t = 1;
    // cin >> t;

    while (t--)
        runTest();

    return 0;
}