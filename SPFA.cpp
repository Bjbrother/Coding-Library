const int N = 1e5 + 1728;

int n,m;

vector<int> dist(N,INT_MAX),vis(N,0),inQueue(N,0);
vector<pair<int, int> > g[N];


bool SPFA(int src)
{
	dist[src]=0;
	queue<int>q;
	q.push(src);
	inQueue[src]=1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		inQueue[v]=0;
		vis[v]++;

		if(vis[v]>n)
		{
			return 1;
		}

		for(auto it:g[v])
		{
			if(dist[it.ff]>dist[v]+it.ss)
			{
				dist[it.ff] = dist[v]+it.ss;
				if(!inQueue[it.ff])
				{
					q.push(it.ff);
					inQueue[it.ff]=1;
				}

			}
		}

	}
	return 0;
}
