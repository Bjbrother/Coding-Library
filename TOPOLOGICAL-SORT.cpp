const int N = 2e5 + 10;

vi g[N];
vi indegree(N,0);
vi order;

bool topologicalSort()
{
	priority_queue<ll, vector<ll>, greater<ll> > q;
	for(ll i=1;i<=n;i++)
	{
		for(auto it:g[i])
		{
			indegree[it]++;
		}
	}

	for(ll i=1;i<=n;i++)
	{
		if(!indegree[i])
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		ll node = q.top();
		q.pop();
		order.pb(node);

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
