const int N = 1e5 + 13;

ll link[N], sz[N];
ll n,m,connected;

vector<pair<ll,pair<ll,ll> > > g;

void init()
{
	for(ll i=1;i<=n;i++)
	{
		link[i]=i;
		sz[i]=1;;
	}
	connected=n;
}

int find(ll k)
{
	while(k!=link[k])
	{
		link[k]=link[link[k]];
		k=link[k];
	}
	return k;
}

void unite(ll u, ll v)
{
	ll rt1=find(u);
	ll rt2=find(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	link[rt1]=link[rt2];
}

ll kruskalMST()
{
	sort(all(g));

	ll cost=0;
	init();
	for(auto it:g)
	{
		if(find(it.ss.ff)!=find(it.ss.ss))
		{
			cost += it.ff;
			unite(it.ss.ff,it.ss.ss);
		}
	}
	return cost;
}
