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

void solve() {
	//input
	int n, m, limit, q;
	cin >> n >> m >> limit >> q;
	int l[q], r[q], ans[q];
	for(int i=0; i<q; ++i)
		cin >> l[i] >> r[i];

	if(limit<q) 
	{
		//subtask 1
		for(int i=0; i<q; ++i)
			ans[i]=m-1;
	} 
	else 
	{
		//subtask 2 & 3
		for(int i=0; i<q; ++i) 
		{
			cout << "1 " << l[i] << " " << r[i] << " " << (1+m)/2 << endl;
			cin >> ans[i];
		}
	}
	cout << 2;
	for(int i=0; i<q; ++i)
		cout << " " << ans[i];
	cout << endl;
	cin >> q;
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