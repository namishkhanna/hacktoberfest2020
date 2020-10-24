#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{

int my_rank, num_cpus;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
MPI_Comm_size(MPI_COMM_WORLD, &num_cpus);

printf(“Hello, I am process %d among %d processes\n”,
my_rank, num_cpus);

MPI_Finalize();
return 0;
}
