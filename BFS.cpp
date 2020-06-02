
const int N = 1e5+10;

vector<int> vis(N,0), dist(N,0), parent(N,-1),level(N,0),ways(N,0);
vector<int> g[N];
int n,m;

void bfs(int k)
{
	queue<int> q;
	q.push(k);
	vis[k]=1;
	ways[k]=1;
	while(!q.empty())
	{
		d(q);
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(!vis[it])
			{
				dist[it]=dist[node]+1;
				vis[it]=1;
				ways[it]+=ways[node];
				parent[it] = node;
				q.push(it);
				level[dist[it]]++;
			}
			else
			{
				if(dist[node]+1==dist[it])
				{
					ways[it]+=ways[node];
				}
			}
			
		}
	}
}

