vector<int>a;
 
struct data
{
	int mn;
	data() : mn(0) {}; //default parameter
};
 
struct SEGTREE
{
	int n;
 
	vector<data>  tree;
	vector<int>lazy;
	SEGTREE(int N)
	{
		n= N;
		tree.resize(4*n);
		lazy.assign(4*n,0);
	}
 
	data merge(data &d1, data &d2) 
	{
		data res;
		res.mn = d1.mn + d2.mn;
		return res;
	}
 
	void buildTree(int ind,int l,int r)
	{
		if(l==r)
		{
			tree[ind].mn= a[l] ;// required attribute
			return;
		}
 
		int mid = (l+r)/2;
 
		buildTree(2*ind,l,mid);
		buildTree(2*ind+1,mid+1,r);
 
		tree[ind] =merge(tree[2*ind],tree[2*ind+1]);
	}
 
	data query(int ind,int l,int r,int x,int y)
	{
		if(x>r||y<l)  //completely outside..
		{
			return data();    // it will return value which doesn't have impact on result..
		}
 
		if(x<=l&&y>=r)  //completely inside..
		{
			return tree[ind];
		}
		int mid = (l+r)/2;
 
		data u = query(2*ind,l,mid,x,y);
		data v = query(2*ind+1,mid+1,r,x,y);
 
		return merge(u,v);
	}
 
	void update(int ind,int l,int r,int qind)  //point update
	{
		if(l==r)
		{
			tree[ind].mn=a[l];  //whatever value you want to give first align to array.
			return;
		}
 
		int mid = (l+r)/2;
 
		if(qind<=mid)
			update(2*ind,l,mid,qind);
		else
			update(2*ind+1,mid+1,r,qind);
		tree[ind]=merge(tree[2*ind],tree[2*ind+1]); 
	}
 
	// for lazy updates..
	void propagate(int ind, int l, int r)
	{
		if(lazy[ind]!=0)
		{
			int pending = lazy[ind];
			lazy[ind]=0;
			tree[ind].mn ;               // logic releted merge
 
			if(l!=r)
			{
				lazy[2*ind]  ;         //logic for child lazy update after lazy[ind]=0;
				lazy[2*ind+1] ;       
			}
		}
		else
		{
			return;
		}
	}
 
	data RangeQuery(int ind,int l,int r,int x,int y) 
	{
		propagate(ind,l,r);
		if(x>r||y<l)  //completely outside..
		{
			return data();
		}
 
		if(x<=l&&y>=r)  //completely inside..
		{
			return tree[ind];
		}
		int mid = (l+r)/2;
 
		data u = RangeQuery(2*ind,l,mid,x,y);
		data v = RangeQuery(2*ind+1,mid+1,r,x,y);
		return merge(u,v);
	}
 
	void updateRange(int ind,int l,int r,int x,int y,int val)
	{
		propagate(ind,l,r);
		if(l>y||r<x) return;
 
		if(l>=x&&r<=y)
		{
			int pending ;  //val relete with merge
			tree[ind].mn ;    // logic releted
 
			if(l!=r)
			{
				lazy[2*ind] ;       // logic for child to do something with val..
				lazy[2*ind+1] ;
			}
			return;
 
		}
		int mid = (l+r)/2;
 
		updateRange(2*ind,l,mid,x,y,val);
		updateRange(2*ind+1,mid+1,r,x,y,val);
 
		tree[ind]= merge(tree[2*ind],tree[2*ind+1]);
	}

	int find_kth(int ind,int l,int r,int k)
	{
		if(k>tree[ind].mn)
		{
			return -1;
		}
		if(l==r)
		{
			return l;
		}

		int mid = (l+r)/2;
		if(tree[mid].mn>=k)
		{
			return find_kth(ind*2,l,r,k);
		}
		else
		{
			return find_kth(ind*2+1,mid+1,r,k-tree[ind*2].mn);
		}
	}
 
};
 