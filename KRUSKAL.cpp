/*********************************************
*Time Complexity(building):O(ElogE)
*Time Complexity:O(E*Log(V))
*Space Complexity:O(V+E)
**********************************************/
struct Edge
{
	int u,v,w,idx;
	bool operator<(Edge const& other)
	{
		return w<other.w;
	}
};

const int N = 1e5 + 13;
int link[N], sz[N];
int n,m,connected;

vector<pair<int, int> > v[N];

Edge g[N];

void init()
{
	for(int i=1;i<=n;i++)
	{
		link[i]=i;
		sz[i]=1;;
	}
	connected=n;
}

int find(int k)
{
	while(k!=link[k])
	{
		link[k]=link[link[k]];
		k=link[k];
	}
	return k;
}

void unite(int u, int v)
{
	int rt1=find(u);
	int rt2=find(v);

	if(rt1==rt2)
		return;

	connected--;

	if(sz[rt1]>sz[rt2])
		swap(rt1, rt2);

	sz[rt2]+=sz[rt1];
	sz[rt1]=0;
	link[rt1]=link[rt2];
}

int kruskalMST()          //Time Complexity::Elog(E)+Elog(V)
{
	init();

	sort(g,g+m);
	int cost=0;
	
	for(int i=0;i<m;i++)
	{
		int u = g[i].u,v = g[i].v,w = g[i].w;
		int rt1=find(u),rt2= find(v);
		if(rt1==rt2)
		{
			continue;
		}
		else
		{
			cost+=w;
			unite(rt1,rt2);
		}
	}
	if(connected!=1)
	{
		cost=-1;
	}
	return cost;
}

