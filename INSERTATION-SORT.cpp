/*********************************************
*Time Complexity:O(n^2)
*Space Complexity:O(1)
*Advantage:Good for short lists
*DisAdvantage:When given sorted list ,Comparisons:depends..
*Inplace Sorting Algorithm
**********************************************/
int insertation_sort(vector<int>&a)
{
	int n= a.size();
	int i,j,key,swapcnt=0;
	int Comparisons=0;

	for(i=1;i<n;i++)
	{
		key = a[i];

		for(j=i-1;j>=0;j--)
		{
			if(a[j]>key)
			{
				Comparisons++;
				swap(a[j],a[j+1]);
				swapcnt++;
			}
			else       
			{
				Comparisons++;
				break;
			}
		}
	}

	return swapcnt;
}
