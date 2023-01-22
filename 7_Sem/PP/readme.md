# Execution of MPI and OMP files

## MPI

Compilation : mpicc filename.c

Execution : mpirun ./a.out  (or)  mpirun -np 4 ./a.out  (or)
 ./a.out

## OMP

Compilation : gcc filename.c -fopenmp

Execution : ./a.out
