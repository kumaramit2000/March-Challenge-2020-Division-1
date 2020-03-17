/*love_for_code*/
/*code_for_love*/
//Code_written_by: @AMIT KUMAR;
#define ll long long int
#define ull unsigned long long int
#define MODM 1000000007
#define MODS 10000007
#define INF 2000000000000000000LL
#include <bits/stdc++.h>
using namespace std;
int n,k,a[500],p[500],mt[500];
bool adj[500][500],vis[500];
bool dfs(int u) 
{
	vis[u]=1;
	for(int v=0; v<n; ++v) 
	{
		if(adj[u][v]&&(mt[v]<0||!vis[mt[v]]&&dfs(mt[v]))) 
		{
			mt[v]=u;
			return 1;
		}
	}
	return 0;
}
void solve() {
	//input
	cin >> n >> k;
	//all edges are in G initially, except for i->i
	memset(adj, 1, sizeof(adj));
	for(int i=0; i<n; ++i)
		adj[i][i]=0;
	//go through permutations
	while(k--) {
		for(int i=0; i<n; ++i) {
			cin >> a[i], --a[i];
			//remove edges
			for(int j=0; j<i; ++j)
				adj[a[j]][a[i]]=0;
		}
	}

	//the rest is standard "min path cover on DAG"
	//max matching
	memset(mt, -1, 4*n);
	int flow=0;
	for(int i=0; i<n; ++i) {
		memset(vis, 0, n);
		flow+=dfs(i);
	}
	//answer
	cout << n-flow << "\n";
	for(int i=0; i<n; ++i)
		cout << mt[i]+1 << " \n"[i==n-1];
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}