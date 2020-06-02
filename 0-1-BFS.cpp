
N = 2*1e5 + 10;
vector<int>dist(N,INT_MAX);
vector<pair<int, int>>g[N];
deque<int>q;

bfs01(int src)           //Time-complexity = O(V+E)
{
	dist[src]=0;
	q.push_back(src);

	while(!q.empty())
	{
		int node = q.front();
		q.pop_front();

		for(auto it:g[node])
		{
			int dest = it.ff;
			int weight = it.ss;

			if(dist[dest]>dist[node]+weight)
			{
				dist[dest] = dist[node]+weight;
			}

			if(weight==0)
			{
				q.push_front(dest);
			}
			else
			{
				q.push_back(dest);
			}
		}
	}
}