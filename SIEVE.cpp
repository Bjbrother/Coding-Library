const int N = 1e6+2;

vector<int>prime;
vector<int>isprime(N+1,1);
vector<int>sum(N+1,0);

void sieve(int n=N-1)
{
	isprime[0]=0;
	isprime[1]=0;

	for(int i=2;i*i<=n;i++)
	{
		for(int j=i*i;j<=n;j+=i)
		{
			isprime[j]=0;
		}
	}

	sum[0] = sum[1] = 0;
    for(int i = 2; i < n; ++i)
    {
        sum[i] = (isprime[i] == 1);  // if sum then (isprime[i]==1?i:0);
        sum[i] += sum[i - 1];
        if(isprime[i])
        {
        	prime.push_back(i);
        }
    }

}
