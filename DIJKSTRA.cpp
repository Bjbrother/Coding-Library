/*********************************************
*Time Complexity:O(V+ ElogV)
*Space Complexity:O(V+E)
**********************************************/
const int N = 1e5 + 10;

vector<pair<int, int>> g[N];

vector<int> dist(N,LLONG_MAX),vis(N,0),parent(N,-1);

void dijkstra(int s)
{
	dist[s]=0;
	set<pair<int,int> >ms;

	ms.insert({0,s});

	while(!ms.empty())
	{
		pair<int,int> p = *ms.begin();
		ms.erase(ms.begin());
		int x = p.ss;

		if(vis[x])
		{
			continue;
		}
		vis[x]=1;
		
		for(int i=0;i<g[x].size();i++)
		{
			int it = g[x][i].ff;
			int weight = g[x][i].ss;
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



