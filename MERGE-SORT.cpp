/*********************************************
*Time Complexity:O(nlog(n))
*Space Complexity:O(n)
*Advantage:used to sort linked-list,best-worst case is also 
* O(nlog(n))
**********************************************/
int inv_cnt=0;
void merge(vector<int>&a,int start,int mid,int end)
{
	int p=start,q=mid+1,k=0;

	vector<int>v(end-start+1);

	for(int i=start;i<=end;i++)
	{
		if(p>mid)      // first deck is empty!!
		{
			v[k++] = a[q++];
		}
		else if(q>end)  // second dec is emtpty!!
		{
			v[k++] = a[p++];
		}
		else if(a[p]<=a[q]) // first dec top is less than second dec top
		{
			v[k++] = a[p++];
		}
		else
		{
			inv_cnt += (mid-p+1);
			v[k++] = a[q++];
		}
	}

	for(int p=0;p<k;p++)
	{
		a[start++] = v[p];
	}

}

void merge_sort(vector<int>&a,int start,int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;

		merge_sort(a,start,mid);

		merge_sort(a,mid+1,end);

		merge(a,start,mid,end);
	}

}
