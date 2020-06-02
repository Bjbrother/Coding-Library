const int mx = 1e6;
int  cnt ;
vector<int>divisor(mx+10,0);
vector <int> prime_factor[mx+10] ;
vector<int>phi(mx+10,0);

void sieve()
{
	int i,j;
	for(i=1;i<=mx;i++)
	{
		phi[i]+=i;
		for(j=i;j<=mx;j+=i)
		{
			divisor[j]++;
		}
		for(j=2*i;j<=mx;j+=i)
		{
			phi[j] -= phi[i];
		}
	}

	for(i=2;i<=mx;i++)
	{
		if(prime_factor[i].size()==0)
		{
			  for(int j=i;j<=mx;j+=i) prime_factor[j].pb(i);
		}
	}

}