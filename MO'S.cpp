const int N = 2e6+13;
const int BLK = 555;

int n,q;
vector<int>a;


struct query
{
	int l;
	int r;
	int idx;
};

vector<query>Q;
vector<int>fre(N,0);
int cnt=0;
vector<int>ans(N);

bool comp(query &q1,query &q2)
{
	if(q1.l/BLK!=q2.l/BLK)
	{
		return q1.l/BLK<q2.l/BLK;
	}
	return q1.r<q2.r;
}

void add(int pos)
{
	fre[a[pos]]++;
	if(fre[a[pos]]==1)
	{
		cnt++;
	}
}

void remove(int pos)
{
	fre[a[pos]]--;
	if(fre[a[pos]]==0)
	{
		cnt--;
	}
}
