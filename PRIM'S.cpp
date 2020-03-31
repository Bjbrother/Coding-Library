const int N = 1e5+24;

vector<bool>vis(N,0);
vii g[N];

ll primsMST(ll x)
{
	priority_queue<pi, vii, greater<pi> > q;

	ll y,cost=0;
	pi p;
	q.push(mp(0,x));
	while(!q.empty())
	{
		p = q.top();
        q.pop();
        x = p.second;
        if(vis[x])
        {
        	continue;
        }
        cost+=p.first;
        vis[x]=1;
        for(ll i=0;i<g[x].size();i++)
        {
        	y = g[x][i].ff;
        	if(!vis[y])
        	{
        		q.push(mp(g[x][i].ss,y));
        	}
        }

	}
	return cost;
}
