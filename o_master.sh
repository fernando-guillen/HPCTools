#!/bin/bash


binarios_gcc="dgesv_o_Oipo"
binarios_icc="icc_o_dgesvOparallel"
SMALL=2048
MED=4096
LARGE=8192


for binario in $binarios_icc ;do
sbatch run_icc.sh $binario $SMALL 1
sbatch run_icc.sh $binario $SMALL 2
sbatch run_icc.sh $binario $SMALL 3
sbatch run_icc.sh $binario $MED 1
sbatch run_icc.sh $binario $MED 2
sbatch run_icc.sh $binario $MED 3
sbatch run_icc.sh $binario $LARGE 1
sbatch run_icc.sh $binario $LARGE 2
sbatch run_icc.sh $binario $LARGE 3
done
#for binario in $binarios_gcc ;do
#sbatch run_gcc.sh $binario $SMALL 1
#sbatch run_gcc.sh $binario $SMALL 2
#sbatch run_gcc.sh $binario $SMALL 3
#sbatch run_gcc.sh $binario $MED 1
#sbatch run_gcc.sh $binario $MED 2
#sbatch run_gcc.sh $binario $MED 3
#sbatch run_gcc.sh $binario $LARGE 1
#sbatch run_gcc.sh $binario $LARGE 2
#sbatch run_gcc.sh $binario $LARGE 3
#done

