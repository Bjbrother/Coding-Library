/************************************************************
*Time Complexity:O(nlog(n))
*Space Complexity:O(log^2(n))
*Advantage:no extra space like merge-sort. 
*DisAdvantage:Worst Case:O(n^2) when array is almost sorted
*Unstable Sort, in general manner inplace sort algorithm
*************************************************************/

int partition(vector<int>&a,int start,int end)
{
	int i=start+1; //boundry between elements that are less than pivot and greater than pivot
	int pivot = a[start];
	for(int j=start+1;j<=end;j++)// j is for boundry between partitoned and non-partitioned part
	{
		if(a[j]<pivot)
		{
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[start],a[i-1]);
	return i-1;
}

int r_partition(vector<int>&a,int start,int end)
{
	track;
	srand(time(NULL)); 
    int random = start + rand() % (end - start); 

    swap(a[random],a[start]);
    return partition(a,start,end);
  
}

void quick_sort(vector<int>&a,int start,int end)
{
	if(start<end)
	{
		int piv_pos = r_partition(a,start,end);
		quick_sort (a,start , piv_pos -1);  
        quick_sort (a,piv_pos +1 , end) ;
	}
}