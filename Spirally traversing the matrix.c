void printSpiral(int a[ROWS][COLS], int r, int c)
{
  int last_row=r-1,last_col=c-1,l=0,k=0,i,j;
  while(l<=last_col&&k<=last_row)
  {
    for(i=l;i<=last_col;i++)
    {
      printf("%d\n",a[k][i]);
    }
    k++;
    for(i=k;i<=last_row;i++)
    {
      printf("%d\n",a[i][last_col]);
    }
    last_col--;
    if(k<=last_row)
    {
    for(i=last_col;i>=l;i--)
    {
      printf("%d\n",a[last_row][i]);
    }
    last_row--;
    }
    if(l<=last_col)
    {
    for(i=last_row;i>=k;i--)
    {
      printf("%d\n",a[i][l]);
    }
      l++;
    }
  }
 
}
