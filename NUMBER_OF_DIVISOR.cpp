int cof(int n)
{
	int cnt=0;

	//stack<int> st;
	//vector<int> v;
	for (int i=1; i<=sqrt(n); i++) 
    	{ 
		if (n%i == 0) 
		{ 
		    if (n/i == i) 
		    {
		    	//v.push_back(i);
		    	cnt++;
		    }
		    else 
		    {
			 //v.push_back(i);
			 //st.push(n/i);
			   cnt+=2;
		    }
		} 
    	}

   // while(!st.empty())
   // {
   // 	v.push_back(st.top());
   // 	st.pop();
   // } 
    return cnt;
}