#include<iostream>
using namespace std;
class factorial
{
	private:
	int n,f=1;
	public:
		void setn()
		{
			cout<<"enter n \n";
			cin>>n;
		}
		void factor()
		{
			int i;
			for(i=1;i<=n;i++)
			{
				f=f*i;
			}
			cout<<"\n factorial of "<<n<<" is "<<f;
		}
};
main()
{
	factorial p;
	p.setn();
	p.factor();
}
