#!/bin/bash

##SBATCH -N 1  #numero de nodos
#SBATCH -n 1 #(1 job)
#SBATCH -c 4 #(cores per job)
#SBATCH -t 04:00:00 #(10 min of execution time)
#SBATCH -p thinnodes,thin-shared

module load gcc/8.1.0


printf "PROGRAMA:$1\n"
printf "\tTAMAÑO=$2\n"
printf "\tREPETICION $3\n"
./$1 $2
