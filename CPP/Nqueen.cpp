#include<iostream>
using namespace std;
int ans =0;
bool canplace(int board[][10],int n,int x,int y )
{
	for(int k =0;k<x;k++)
	{
		if(board[k][y] == 1)
		{
			return false;
		}
	}
	int i = x,j = y;
	while( i>= 0 and j>=0)
	{
		if(board[i][j] == 1)
		{
			return false;
		}
		i--;
		j--;
	}
	i =x;
	j =y;
	while(i>= 0 and j<n)
	{
		if(board[i][j] == 1)
		{
			return false;
		}
		i--;
		j++;
	}
	
	return true;
}
int Nqueen(int n, int board[][10],int i)
{
	if(i == n)
 	{
// 		for(int x =0;x<n;x++)
// 		{
// 			for(int y = 0;y<n;y++)
// 			{
// 				cout<< board[x][y]<<" ";
//			}	
//			cout<<endl;
//		}
		ans++;
		return 1;
	}
	int cnt  =0;
	for(int j =0;j<n;j++)
	{
		if(canplace(board,n,i,j))
		{
			board[i][j] =1;
			cnt += Nqueen(n,board,i+1);
			board[i][j] = 0;
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin>>n;
	int board[10][10] = {0};
	cout<<Nqueen(n,board,0);
	return 0;
	
}