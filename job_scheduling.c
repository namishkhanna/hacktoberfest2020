#include<stdio.h>

void sort(int n, int a[n][3])
{
	for(int i=0; i<(n-1); i++)
	{
		int max=i;
		for(int j=i+1; j<n; j++)
		{
			if(a[max][1] < a[j][1])
				max=j;
		}
		if(max!=i)
		{
		int temp_n=a[i][0];
		int temp_pr=a[i][1];
		int temp_dl=a[i][2];
		
		a[i][0]=a[max][0];
		a[i][1]=a[max][1];
		a[i][2]=a[max][2];
				
		a[max][0]=temp_n;
		a[max][1]=temp_pr;
		a[max][2]=temp_dl;
		}
	}
}

int max(int n, int a[n][3])
{
	int max=a[0][2];
	for(int i=1; i<n; i++)
	{
		if(a[i][2]>max)
			max=a[i][2];
	}
	return max;
}

int main()
{
	int n;
	printf("Enter n:");
	scanf("%d", &n);
	
	int job[n][3];
	printf("Enter profit and deadline of jobs:\n");
	for(int i=0; i<n ; i++)
	{
		job[i][0]=i+1;
		scanf("%d", &job[i][1]);
		scanf("%d", &job[i][2]);
	}
	
	int m=max(n, job);
	
	int slot[m];
	for(int i=0; i<m; i++)
		slot[i]=0;
	
	sort(n, job);

	int profit=0;
	
	for(int i=0; i<n; i++)
	{
		int DL=job[i][2];
		while(DL>=0)
		{
			if(slot[DL-1]==0)
			{
				slot[DL-1]=job[i][0];
				profit+=job[i][1];
				break;
			}
			DL--;
		}
	}
	
	printf("Jobs selected are:\n");
	for(int i=0; i<m; i++)
		printf("%d ", slot[i]);
	
	printf("\nTotal profit earned:%d\n", profit);
}
