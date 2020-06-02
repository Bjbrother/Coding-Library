//Time Complexity:(O((V+E)logV))
const int N = 1e5+24;

vector<bool>vis(N,0);
vector<pair<int,int> >g[N];

int primsMST(int x)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater< pair<int,int> > > q;

	int y,cost=0;
	pair<int,int>p
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
        for(int i=0;i<g[x].size();i++)
        {
        	y = g[x][i].ff;
        	if(!vis[y])
        	{
        		q.push(make_pair(g[x][i].ss,y));
        	}
        }

	}
	return cost;
}
