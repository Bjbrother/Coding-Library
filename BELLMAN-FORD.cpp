const int N = 1e5 +10;

int n,m;

vector<int> dist(N,INT_MAX),vis(N,0);

vector<pair<int,pair<int,int> > >g;

bool BellmanFord(int src)  //complexity O(V*E);(in worst case)
{
	bool flag=0;
	dist[src]=0;
	for(int i=1;i<=n;i++)
	{
		int changed = 0;
		for(auto it:g)
		{
			int v1 = it.ff;
			int v2 = it.ss.ff;
			int weight = it.ss.ss;

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