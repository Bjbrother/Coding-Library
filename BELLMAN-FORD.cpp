const int N = 1e5 +10;

ll n,m;

vi dist(N,INT_MAX),vis(N,0);

vector<pair<ll,pair<ll,ll> > >g;

bool BellmanFord(ll src)  //complexity O(V*E);
{
	bool flag=0;
	dist[src]=0;
	for(ll i=1;i<=n;i++)
	{
		ll changed = 0;
		for(auto it:g)
		{
			ll v1 = it.ff;
			ll v2 = it.ss.ff;
			ll weight = it.ss.ss;

			if(dist[v2]>dist[v1]+weight)
			{
				changed=1;
				if(i==n)
				{
					return 1;
				}
				
				dist[v2] = dist[v1]+weight;
			}
			if(i==n)
			{
				return 0;
			}

		}
		if(changed==0)
		{
			break;
		}
	}

}