/*********************************************
*Time Complexity:O(n^2) Best:O(n)
*Space Complexity:O(1)
*Advantage:Already given Sorted list.
*Inplace Sorting Algorithm
**********************************************/
int bubble_sort(vector<int> &a)
{
	int i,j;

	bool flag=0;

	int n = a.size();
	int swapcnt=0;

	for(i=0;i<n-1;i++)   // why (n-1) iterations..?? Because at each time you place highest element at right side...
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				swapcnt++;
				swap(a[j],a[j+1]);
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	return swapcnt;
}
