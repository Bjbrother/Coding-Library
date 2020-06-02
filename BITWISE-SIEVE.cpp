const int N = 1e8+1;
vector<int>prime(8000000);
vector<bool>isPrime(N+1,1);

void bitwise_sieve()
{
	int k=1;
	
	isPrime[0]=0;
	isPrime[1]=0;
	isPrime[2]=1;
	prime[0]=2;


	for(int i=4;i<=N;i+=2)
     	isPrime[i]=0;

	for(int i=3;i<=sqrt(N);i+=2)
	{
			for(int j=i*i;j<=N;j+=2*i)
			{
				isPrime[j] = 0;
			}
	}
	
	for(int i=3;i<=N;i+=2)
	{
		if(isPrime[i])
		{
			prime[k++]=i;
		}
	}
}