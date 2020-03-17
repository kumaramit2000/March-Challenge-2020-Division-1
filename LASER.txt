/*love_for_code*/
/*code_for_love*/
//Code_written_by: @AMIT KUMAR;
#define ll long long int
#define ull unsigned long long int
#define MODM 998244353
#define MODS 10000007
#define pb push_back
#define INF 2000000000000000000LL
#include <bits/stdc++.h>
using namespace std;
int a[100000],l[100000],r[100000],y[100000],f[100000],ans[100000];
int n,q;
void update(int i,int x)
{
    for(i++;i<n;i+=i&-i) // loop run such a way that it run for the next value for the beginning value of i and then all the 2^k values where i< 2^k <n ; 
    {
        f[i]+=x;
    }
}
int query(int i)
{
    int res=0;
    for(;i;i-=i&-i) // loop run such that for particular value of i in which i change the first set bit to 0 from right to left and this end with all set bit become 0 ;
    {
        res+=f[i];
    }
    return res;
}
struct event
{
    int y,type,index;
    bool operator <(const event &temp) const
    {
        return make_pair(y,type)<make_pair(temp.y,temp.type);
    }
};
void solve()
{
    // read the input;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>l[i];
        cin>>r[i];
        cin>>y[i];
        l[i]--;
        r[i]--;
    }
    // main solution start at here;
    vector<event> v;
    // create the event for each segment;
    for(int i=0;i<n-1;i++)
    {
        // add segment;
        v.pb({min(a[i],a[i+1]),1,i});
        // remove segment;
        v.pb({max(a[i],a[i+1]),3,i});
    }
    // now create the events for the query;
    for(int i=0;i<q;i++)
    {
        v.pb({y[i],2,i});
    }
    // process events;
    sort(v.begin(),v.end());
    for(event e: v)
    {
        if(e.type==1)
        {
            // add segment;
            update(e.index,1);
        }
        else if(e.type==2)
        {
            // solution for query;
            ans[e.index]=query(r[e.index])-query(l[e.index]);
        }
        else
        {
            // remove segment;
            update(e.index,-1);
        }
    }
    //output for all the query;
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}