const int N = 1e6;

vector<int>primes;
vector<int>is_prime(N+1,1);


void sieve()
{
	is_prime[0]=0;
	is_prime[1]=0;

	for(int i=2;i*i<=N;i++)
	{
		if(is_prime[i])
		{

			for(int j=i*i;j<=N;j+=i)
			{
				is_prime[j]=0;
			}
		}
	}
	for(int i=2;i<=N;i++)
	{
		if(is_prime[i])
		{
			primes.push_back(i);
		}
	}
}

void seg_sieve(int l,int r)
{
	if(l==1)
	{
		l++;
	}

	int size = r-l+1;

	vector<int>isprime(size,1);

	for(auto it:primes)
	{
		if(it*it<=r)
		{
			int i = (l/it)*it;
			if(i<l) i+=it;  // first multiple of it in Range[l..r]

			for(;i<=r;i+=it)
			{
				if(i!=it)
				{
					isprime[i-l]=0;
				}
			}
		}

	}

	for(int i=0;i<size;i++)
	{
		if(isprime[i])
		{
			cout<<l+i<<endl;
		}
	}
	cout<<endl;

}
