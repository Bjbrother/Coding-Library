
const int N = 2*1e5 + 10;
struct DSU
{
	int totlst;
	int link[N] , sz[N];
	int ht[N]; //shows number of groups with givenn size;
 
	DSU(){}
 
	DSU(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			link[i]=i;
			sz[i]=1;
		}
		totlst=n;
	}
 
	int find(int x)
	{

		if(x==link[x])
		{
			return x;
		}
		return link[x] = find(link[x]);

	}
 
	bool same(int a,int b)
	{
		return (find(a)==find(b));
	}
 
	void unite(int a,int b)
	{
		a = find(a);
		b = find(b);
 
		if(a==b)
		{
			return;
		}
 
		totlst--;
 
		if(sz[a]<sz[b]) 
		{
			sz[b]+=sz[a];
			sz[a]=0;
			link[a]=b;
		}
		else
		{
			sz[a]+=sz[b];
			sz[b]=0;
			link[b]=a;  
		}    
	}


	int getSize(int k)
	{
		return sz[find(k)];
	}

	void makeLeader(int a)
	{
		int k = find(a);
		link[k]=link[a]=a;
		sz[a]=sz[k];
		sz[k]=0;
	}
 
 
	int getDisjointsets()
	{
		return totlst;
	}
};	








































