const int N = 5*1e5 + 10;
vector<bool>isPrime;
vector<int>prime;
vector<int>SPF;
vector<int>BPF;

void linear_sieve(int n=N)
{
	isPrime.resize(n+1,true);
	SPF.resize(n+1);
	BPF.resize(n+1);
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2;i<=n;i++)
	{
		if(isPrime[i])
		{
			prime.push_back(i);
			SPF[i]=i;
			BPF[i]=i;
		}

		for(int j=0;j<(long long int)prime.size()&&i*prime[j]<=n&&prime[j]<=SPF[i];j++)
		{
			isPrime[i*prime[j]] = false;
			SPF[i*prime[j]] = prime[j];
			BPF[i*prime[j]] = max(BPF[i*prime[j]],BPF[i]);
		}
	}
}

int factorsOf(int n)
{
	vector<pair<int, int>>v;

	int prev = SPF[n],cnt=0,s=1;

	int num_of_divisor=1;
	int sum_of_divisor=1;

	while(n!=1)
	{
		s = SPF[n];
		if(s==prev)
		{
			n /= SPF[n];
			prev = s;
			cnt++;
		}
		else
		{
			v.push_back({prev,cnt});
			cnt=0;
			prev = s;
		}
	}
	v.push_back({prev,cnt});

	for(auto it:v)
	{
		num_of_divisor *= (it.ss+1);
	}
	return num_of_divisor;

	// for(auto it:v)
	// {
	// 	sum_of_divisor *= (pow(it.ff,it.ss+1)-1)/(it.ff-1);
	// }

	// return sum_of_divisor;
}
