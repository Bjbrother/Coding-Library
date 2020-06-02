const int N = 2e5 + 10;

vector<int> g[N];
vector<int> indegree(N,0);
vector<int> order;

bool topologicalSort()
{
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			indegree[it]++;
		}
	}

	for(int i=1;i<=n;i++)
	{
		if(!indegree[i])
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int node = q.top();
		q.pop();
		order.push_back(node);

		for(auto itr:g[node])
		{
			indegree[itr]--;
			if(!indegree[itr])
			{
				q.push(itr);
			}
		}
	}

	if(order.size()<n)
	{
		return 0;
	}
	return 1;
}
