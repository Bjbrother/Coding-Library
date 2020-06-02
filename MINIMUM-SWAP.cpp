int minimumSwap(vector<int>&a)
{
	int n=a.size(),cnt=0;

	b=a;
	sort(all(b));

	bool flag =1;

	while(flag)
	{
		flag=0;

		for(int i=0;i<n;i++)
		{
			int  ind = lower_bound(all(b),a[i])-b.begin();
			if(ind!=i)
			{
				cnt++;
				swap(a[i],a[ind]);
				flag=1;
			}
		}
	}

	return cnt;
}