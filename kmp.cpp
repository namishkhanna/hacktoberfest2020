//Knuth–Morris–Pratt algorithm template

// s string
// p pattern

vector <int> kmp(string s, string p)
{
	vector <int> index;

	if(p.size()>s.size())
		return index;

	int bt[p.size()+1];

	int i=0, j=-1;
	bt[0]=-1;
	
	while(i<p.size())
	{
		while(j>=0 && p[i]!=p[j])
			j=bt[j];
		i++;
		j++;
		bt[i]=j;
	}

	i=0;
	j=0;
	while(i<s.size())
	{
		while(j>=0 && s[i]!=p[j])
			j=bt[j];
		i++;
		j++;
		if(j==p.size())
		{
			index.push_back(i-j);
			j=bt[j];
		}
	}
	return index;
}
