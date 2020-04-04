const int N = 1e5 + 10;

vii g[N];

vi dist(N,LLONG_MAX),vis(N,0),parent(N,-1);

void dijkstra(ll s)
{
	dist[s]=0;
	set<pair<ll,ll> >ms;

	ms.insert({0,s});

	while(!ms.empty())
	{
		pi p = *ms.begin();
		ms.erase(ms.begin());
		ll x = p.ss;

		if(vis[x])
		{
			continue;
		}
		vis[x]=1;

		for(ll i=0;i<g[x].size();i++)
		{
			ll it = g[x][i].ff;
			ll weight = g[x][i].ss;
			if(dist[x]+weight<dist[it])
			{
				if(dist[it]!=LLONG_MAX)
				{
					ms.erase({dist[it],it});
				}
				dist[it]= dist[x]+weight;
				ms.insert({dist[it],it});
				parent[it] = x;
			}
		}

	}

}



