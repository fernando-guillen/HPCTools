#!/bin/bash
#SBATCH -n 1 #(1 job)
#SBATCH -c 4 #(cores per job)
#SBATCH -t 04:00:00 #(10 min of execution time)
#SBATCH -p thinnodes,thin-shared

module load gcc/6.4.0 openmpi/2.1.1 extrae/3.5.2

source /opt/cesga/easybuild-cesga/software/MPI/gcc/6.4.0/openmpi/2.1.1/extrae/3.5.2/etc/extrae.sh

export OMP_NUM_THREADS=4
export EXTRAE_CONFIG_FILE=./extrae.xml
export LD_PRELOAD=${EXTRAE_HOME}/lib/libomptrace.so

##srun -n 12 parallel_dgesv.out 2048
./parallel_dgesv.out 128
