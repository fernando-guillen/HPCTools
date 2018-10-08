#!/bin/bash

#SBATCH -N 1  #numero de nodos
##SBATCH -n 1 #(1 job)
#SBATCH -c 24 #(cores per job)
#SBATCH -t 04:00:00 #(10 min of execution time)
#SBATCH -p thinnodes,thin-shared

module load intel/2018.3.222

echo "icc dgesvO1"
./icc_dgesvO1 2048

##module unload intel/2018.3.222
##module load gcc/8.1.0

##echo "gcc dgesvO1"
##./dgesvO0 2048
