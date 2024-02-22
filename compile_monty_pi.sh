#!/bin/bash

srun -p compute --pty /usr/bin/bash

module load openmpi/2.1.2

g++ -o pi_mpi monti_pi.cpp -I /opt/openmpi-2.1.2/include -L /opt/openmpi-2.1.2/lib -l mpi