struct BIT
{
	int n;
	vector<int>bit;

	BIT(int N)
	{
		n=N;
		bit.assign(N+25 ,0);
	}
	void update(int ind,int val)  // index based on 1
	{
		while(ind<=n)
		{
			bit[ind]+=val;
			ind += (ind&(-ind));
		}
	}

	int prefix(int ind)
	{
		int ans=0;
		while(ind>0)
		{
			ans += bit[ind];
			ind -= (ind&(-ind));
		}
		return ans;
	}

	int rangesum(int l, int r)
	{
		return prefix(r) - prefix(l - 1);
	}

	int findKthSmallest(int k) 
	{ 
    
    	int l = 0; 
    	int h = n; 
    	int ans=-1;
    	while (l <=h) 
    	{ 
        	int mid = (l + h) / 2; 
        	if (prefix(mid)>=k) 
        	{
        		h = mid-1;
        	}
        	else
        	{
            	l = mid+1; 
            	ans = l;
        	}
    	} 
  
    	return ans; 
	} 
};
