#!/bin/bash


binarios_gcc="dgesvO1 dgesvO2 dgesvO3 dgesvOfast dgesvOipo"
binarios_icc="icc_dgesvO1 icc_dgesvO2 icc_dgesvO3 icc_dgesvOfast icc_dgesvOipo"
SMALL=2048
MED=4096
LARGE=8192


#for binario in $binarios_icc ;do
#sbatch run_icc.sh $binario $SMALL 1
#sbatch run_icc.sh $binario $SMALL 2
#sbatch run_icc.sh $binario $SMALL 3
#sbatch run_icc.sh $binario $MED 1
#sbatch run_icc.sh $binario $MED 2
#sbatch run_icc.sh $binario $MED 3
#sbatch --mem=20GB run_icc.sh $binario $LARGE 1
#sbatch --mem=20GB run_icc.sh $binario $LARGE 2
#sbatch --mem=20GB run_icc.sh $binario $LARGE 3
#done
#for binario in $binarios_gcc ;do
#sbatch run_gcc.sh $binario $SMALL 1
#sbatch run_gcc.sh $binario $SMALL 2
#sbatch run_gcc.sh $binario $SMALL 3
#sbatch run_gcc.sh $binario $MED 1
#sbatch run_gcc.sh $binario $MED 2
#sbatch run_gcc.sh $binario $MED 3
#sbatch --mem=20GB run_gcc.sh $binario $LARGE 1
#sbatch --mem=20GB run_gcc.sh $binario $LARGE 2
#sbatch --mem=20GB run_gcc.sh $binario $LARGE 3
#done

#PGO
#sbatch run_icc.sh icc_dgesvPGO $SMALL 1
#sbatch run_icc.sh icc_dgesvPGO $SMALL 2
#sbatch run_icc.sh icc_dgesvPGO $SMALL 3
#sbatch run_icc.sh icc_dgesvPGO $MED 1
#sbatch run_icc.sh icc_dgesvPGO $MED 2
#sbatch run_icc.sh icc_dgesvPGO $MED 3
#sbatch run_icc.sh icc_dgesvPGO $LARGE 1
#sbatch run_icc.sh icc_dgesvPGO $LARGE 2
#sbatch run_icc.sh icc_dgesvPGO $LARGE 3


#sbatch run_gcc.sh dgesvPGO $SMALL 1
#sbatch run_gcc.sh dgesvPGO $SMALL 2
#sbatch run_gcc.sh dgesvPGO $SMALL 3
#sbatch run_gcc.sh dgesvPGO $MED 1
#sbatch run_gcc.sh dgesvPGO $MED 2
#sbatch run_gcc.sh dgesvPGO $MED 3
#sbatch run_gcc.sh dgesvPGO $LARGE 1
#sbatch run_gcc.sh dgesvPGO $LARGE 2
#sbatch run_gcc.sh dgesvPGO $LARGE 3

sbatch run_gcc.sh dgesvOcustom $SMALL 1
sbatch run_gcc.sh dgesvOcustom $SMALL 1
sbatch run_gcc.sh dgesvOcustom $SMALL 1
sbatch run_gcc.sh dgesvOcustom $MED 1
sbatch run_gcc.sh dgesvOcustom $MED 1
sbatch run_gcc.sh dgesvOcustom $MED 1
sbatch run_gcc.sh dgesvOcustom $LARGE 1
sbatch run_gcc.sh dgesvOcustom $LARGE 2
sbatch run_gcc.sh dgesvOcustom $LARGE 3
