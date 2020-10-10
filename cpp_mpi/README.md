# Use

    docker run --rm -v`pwd`:/scratch -w /scratch mpi_phusion mpic++ hello_mpi.cpp 
    docker run --rm -v`pwd`:/scratch -w /scratch mpi_phusion mpiexec -np 2 ./a.out 
