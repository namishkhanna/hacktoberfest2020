#include <stdio.h>
#include <time.h> 

int x[100],count=0,flag=0; //variable initialisation, x-solution vector, x-index-queen number, value at index-column where the queen placed and count-counter

void show(int n) //to print the solution
{
      char board[100][100];  // chessboard variable initialisation
      int i,j; //variable initialisation
      count++;
      //converts x[] into a 2-D matrix in form of chessboard 
      if(flag==0){
       printf("\n\nSolution #%d:\n",count);
        for(i=1;i<=n;i++) //I denotes row of chessboard
        {
            for(j=1;j<=n;j++) //j represents column of chessboard
            {
                if(x[i]==j)// if queen present at the locition
                    board[i][j]='Q'; //queen placed in cell
                else
                    board[i][j]='~';  //queen not present in cell
            }
    }
      
        //to print the chessboard
       for(i=1;i<=n;i++)
        {
           for(j=1;j<=n;j++)
            {
 				printf("%c\t",board[i][j]); //prints chessboard
           }
            printf("\n");
            flag++;
        }}else{
		
        return;
        }
        printf("\n\n"); 
}

int place(int k,int i) //to check if the cell (k,i) is under the attack of any other queen or not
{
    int j; //variable initialisation
    //Checking if queen k can be placed at row k and column i
    for(j=1;j<k;j++) //j checks for all the previous queens
    {
        if( (x[j]==i)) //checks whether any other queen is already placed in same column
                return 0; //as queen can't be placed

        if((k-i==j-x[j]) || (k+i==j+x[j])) //checks whether any other queen is already placed in //same diagonal
            return 0; //as queen can't be placed
    }

    return 1; //queen can be placed at (k,i)
}

void nqueen(int k,int n) //main function where backtracking occurs
{
    int i; //variable initialisation
    for(i=1;i<=n;i++) //to find the locition of queens in columns from 1 to n
    {
        if (place(k,i)) //checks whether queen can be placed in cell (k,i) or not
        {
            x[k]=i; //queen k placed at column i

            if(k==n) //all queens placed
            {
                show(n); //call function to print the solution
            }
            else
            {
                nqueen(k+1,n); //find locition for queen k+1
            }
        }
    }
}

int main()
{
    int n; //variable initialisation
    clock_t start,end;
    printf("Enter the number of queens(N) to be placed on a N*N chessboard:");
    scanf("%d",&n); // input number of queens
    printf("\n");
    start = clock();
    nqueen(1,n); //placing all queens starting from queen 1 upto queen n
    end = clock();
    printf("\nTotal no. of solutions = %d",count); // printing no. of solutions
    double total_time = double(end - start) / double(CLOCKS_PER_SEC); //subtract the value & divide by no. of CLOCKS_PER_SEC to get processor time
    printf("\nProgram took %f seconds to execute \n", total_time); 
    return 0;
}

