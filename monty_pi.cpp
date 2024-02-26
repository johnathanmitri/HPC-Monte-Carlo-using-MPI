#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "mpi.h"
#include <chrono>
#include <cstdio>

const long NUM_POINTS = 100;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int commSize;
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);

    int myid;
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    
    std::chrono::time_point<std::chrono::system_clock> startTime;
    if (myid == 0)
        startTime = std::chrono::system_clock::now();

    // number of points for this node to calculate
    long myPoints = NUM_POINTS / commSize;
    int remainder = NUM_POINTS % commSize;

    if (myid < remainder) // handle the remainder
        myPoints += 1;
    std::cout << "My id is: " << myid << ". I have been assigned " << myPoints << " points." << std::endl;    
    
     
    srand((unsigned)(myid+time(0)));

    long insideCount = 0;

    for (long i = 0; i < myPoints; i++)
    {
        double x = ((double)rand()) / ((double)RAND_MAX);
        double y = ((double)rand()) / ((double)RAND_MAX);

        if (x*x + y*y <= 1)
            insideCount++;
    }

    long totalSum;
    
    MPI_Reduce(&insideCount, &totalSum, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (myid == 0)
    {
        double piEstimate = (totalSum / (double)NUM_POINTS) * 4;
        std::cout << commSize << " NODES" << std::endl;
        std::cout << "POINTS: " << NUM_POINTS << std::endl;
        printf("ESTIMATED PI: %.8f\n", piEstimate);
        printf("DELTA: %.8f\n", fabs(piEstimate - M_PI));
        auto endTime = std::chrono::system_clock::now();
        auto runTime = endTime - startTime;
        printf("TIME: %.6fs\n", runTime.count()/1000000000.0);
    }

    MPI_Finalize();
    return 0;
}
