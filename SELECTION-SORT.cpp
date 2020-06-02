/*********************************************
*Time Complexity:O(n^2) Best:O(n^2)
*Space Complexity:O(1)
*Advantage:Perform Minimum Swaps....
*DisAdvantage:O(n^2) in all case
*Inplace Sorting Algorithm
**********************************************/
pair<int, int> selection_sort(vector<int> &a,int k=INT_MAX)
{
	int i,j;
	int n = a.size();
	int comp = ((n)*(n-1))/2;
	int swapcnt=0;

	for(i=0;i<n-1;i++)
	{
		int Min = i;
		if(i==k)
		{
			break;
		}

		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[Min])
			{
				Min = j;
			}
		}

		if(i!=Min)
		{
			swapcnt++;
			swap(a[i],a[Min]);
		}
	}

	pair<int, int> p = {comp,swapcnt};
	return p;
}
