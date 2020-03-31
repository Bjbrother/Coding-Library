const int N = 2*1e5 + 10;
struct DSU
{
	ll totlst;
	ll link[N] , sz[N];
 
	DSU(){}
 
	DSU(ll n) 
	{
		for(ll i=1;i<=n;i++)
		{
			link[i]=i;
			sz[i]=1;
		}
		totlst=n;
	}
 
	ll find(ll x)
	{

		if(x==link[x])
		{
			return x;
		}
		return link[x] = find(link[x]);

	}
 
	bool same(ll a,ll b)
	{
		return (find(a)==find(b));
	}
 
	void unite(ll a,ll b)
	{
		a = find(a);
		b = find(b);
 
		if(a==b)
		{
			return;
		}
 
		totlst--;
 
		if(sz[a]<sz[b]) swap(a,b);
		sz[a]+=sz[b];
		sz[b]=0;
		link[b]=a;      
	}
 
	ll getSize(ll k)
	{
		return sz[find(k)];
	}
 
	ll getDisjointsets()
	{
		return totlst;
	}
};	
