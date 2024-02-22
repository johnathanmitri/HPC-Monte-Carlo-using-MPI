#!/bin/bash
srun -p compute /usr/bin/bash -c '
source ~/.bashrc &&
module load openmpi/2.1.2 &&
g++ -o pi_mpi monty_pi.cpp -I /opt/openmpi-2.1.2/include -L /opt/openmpi-2.1.2/lib -l mpi 
'
