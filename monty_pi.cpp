#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "mpi.h"

int main(int argc, char **argv)
{
    int myid;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    std::cout << "My id is: " << myid << std::endl;
    srand((unsigned)(myid*time(0)));

    double x = ((double)rand()) / ((double)RAND_MAX);
    double y = ((double)rand()) / ((double)RAND_MAX);

    std::cout << x << " " << y << std::endl;

    MPI_Finalize();
    return 0;
}
