int phi(int n)  //toitent function O(sqrt(N))
{
    int res = n;
    for (int i=2;i*i<=n;i++)
    {
        if(n%i==0) 
        {
            res/=i;
            res*=(i-1);
            while(n%i==0) 
            {
                n/=i;
            }
        }
    }
    if (n != 1) {
       res/=n , res *= (n-1);
    }
    return res;
}

const int N = 1e5+6;
vector<int>phi(N+1);

void calcphi(int n=N)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        phi[i]=i;
    }
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=n;j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }

}

int d, x, y;  //extended euclid algorithms..
void xgcd(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        xgcd(B, A%B);
       int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int modular_inverse(int a, int m)
{
	int x, y;
	int g=xgcd(a, m, x, y);
	if(g!=1)
		return -1;
	else
	{
		x=(x%m + m)%m;
		return x;
	}
}

int mpow(int a, int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return ans;
}

const int MAX = 1e5 + 2;

int fac[MAX],inv[MAX];
void precalc()
{
    int i;
    fac[0]=1;
    inv[0]=1;
    fac[1]=1;
    inv[1]=1;
    for(i=2; i<MAX; i++)
    {
        fac[i]=(i*fac[i-1])%MOD;
        inv[i]=mpow(fac[i],MOD-2);
    }
}
int ncr(int n,int r)
{
    if(n<r)return 0LL;
    int ret1=(inv[r]*inv[n-r])%MOD;
    int ret=(ret1*fac[n])%MOD;
    return ret;
}
