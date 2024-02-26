#!/bin/bash
#SBATCH --job-name=PI_MPI # Job name
#SBATCH --output=RUN_MONTY_PI_32TASKS_%j.log # Log file name
#SBATCH --partition=compute # Use computing cluster
#SBATCH --mem=100000 # Job memory request
#SBATCH --nodes=19 # Number of computing nodes
#SBATCH --ntasks-per-node=32 # Number of processes on each node
#SBATCH --time=00:08:00 # Time limit HH:MM:SS

. /etc/profile.d/modules.sh

module load openmpi/2.1.2

/opt/openmpi-2.1.2/bin/mpirun ./pi_mpi
