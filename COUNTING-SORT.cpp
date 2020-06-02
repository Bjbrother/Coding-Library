/*********************************************
*Time Complexity:O(n+max_element)
*Space Complexity:O(n+max_element)
*Advantage:when max_element is in aray's Range..
*DisAdvantage:in high range not sufficiant
*non-comparison based algorithm,external
**********************************************/
vector<int> counting_sort(vector<int>&a)
{
	int Max = *max_element(all(a)),i;
	int Aux[Max+1]={0};
	vector<int>final;

	for(i=0;i<a.size();i++)
	{
		Aux[a[i]]++;
	}
	for(i=0;i<=Max;i++)
	{
		int tmp = Aux[i];
		while(tmp--)
		{
			final.push_back(i);
		}
	}

	return final;

}
