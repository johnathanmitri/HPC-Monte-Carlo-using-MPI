#include <math.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    
    int myid = 7;
    srand((unsigned)(myid));

    int x = ((double)rand()) / ((double)RAND_MAX);
    int y = ((double)rand()) / ((double)RAND_MAX);

    std::cout << x << " " << y << std::endl;

    return 0;
}
